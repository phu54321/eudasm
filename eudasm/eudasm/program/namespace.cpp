#include "namespace.h"
#include "../util.h"
#include "../murmurhash3.h"

Namespace::StringRef::StringRef(int id, const char* str) : value(new std::string(str)), id(id) { }


Namespace::Namespace() : _totalvariablenum(0) {
	_variabletablelist.push_back(nullptr);
}

Namespace::~Namespace() {
	for(auto it : _variabletablelist) {
		delete it;
	}
}


Namespace::MM3HashVal Namespace::CalculateMM3Hash(const char* str) const {
	MM3HashVal v;
	MurmurHash3_x86_128(str,strlen(str), 0x00000000, &v);
	return v;
}

Namespace::LabelRef Namespace::GetLabel(const char* name) {
	MM3HashVal hash = CalculateMM3Hash(name);
	auto it = _labeltable.find(hash);
	if(it == _labeltable.end()) {
		int id = _labeltable.size();
		_labeltable.insert(std::make_pair(hash, id));
		return id;
	}
	return it->second;
}


Namespace::StringRef Namespace::GetString(const char* content) {
	MM3HashVal hash = CalculateMM3Hash(content);
	auto it = _stringtable.find(hash);
	if(it == _stringtable.end()) {
		int id = _stringtable.size();
		StringRef ref(id, content);
		_stringtable.insert(std::make_pair(hash, ref));
		return ref;
	}
	return it->second;
}


Namespace::VariableRef Namespace::GetVariable(const char* name) {
	MM3HashVal hash = CalculateMM3Hash(name);
	for(auto it = _variabletablelist.rbegin() ; it != _variabletablelist.rend() ; it++) {
		if(*it == nullptr) continue;
		
		auto it2 = (*it)->find(hash);
		if(it2 != (*it)->end()) {
			return it2->second;
		}
	}

	char errorstring[512];
	snprintf(errorstring, 512, "Variable name %s not found on scope level %d.", name, _variabletablelist.size());
	throw ParserException(errorstring);
}


void Namespace::PushBlock() {
	// pushes nullptr instead of new VariableTable
	// Most of the blocks don't really define new variables, so most of the blocks will be empty.
	// Initalizing new tables for every occuring blocks isn't optimal.
	// We use lazy initalization. If new variable is created, then new VariableTable is created.
	_variabletablelist.push_back(nullptr);
}

void Namespace::PopBlock() {
	runtime_assert(_variabletablelist.size() > 1);
	VariableTable* ptr = _variabletablelist.back();
	_variabletablelist.pop_back();
	delete ptr;
}

void Namespace::CreateVariable(const char* name, CTypePtr type) {
	// duplicate check for the most recent block
	MM3HashVal hash = CalculateMM3Hash(name);
	auto lastvt = _variabletablelist.back();
	if(lastvt) {
		auto it2 = lastvt->find(hash);
		if(it2 != lastvt->end()) {
			char errorstring[512];
			snprintf(errorstring, 512, "Variable name %s duplicated on scope level %d.", name, _variabletablelist.size());
			throw ParserException(errorstring);
		}
	}

	else { // Lazy initalization of new variable table if needed.
		lastvt = new VariableTable;
		_variabletablelist.back() = lastvt;
	}

	VariableRef vref;
	vref.id = GetNewVariableID();
	vref.type = type;
	lastvt->insert(std::make_pair(hash, vref));
}


size_t Namespace::GetNewVariableID() {
	return _totalvariablenum++;
}
#include "namespace.h"
#include "../util.h"

Namespace::Namespace() {
	_variabletablelist.push_back(nullptr);
}

Namespace::~Namespace() {
	for(auto it : _variabletablelist) {
		delete it;
	}
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
	sprintf(errorstring, "Variable name %s not found on scope level %d.", name, _variabletablelist.size());
	throw ParserException(errorstring);
}


void Namespace::PushBlock(const char* blockname) {
	// pushes nullptr instead of new VariableTable
	// Most of the blocks don't really define new variables, so most of the blocks will be empty.
	// Initalizing new tables for every occuring blocks isn't optimal.
	// We use lazy initalization. If new variable is created, then new VariableTable is created.
	_variabletablelist.push_back(nullptr);
}

void Namespace::PopBlock() {
	runtime_assert(_variabletablelist.size() > 1, "No more available scope.");
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
			sprintf(errorstring, "Variable name %s duplicated on scope level %d.", name, _variabletablelist.size());
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

/*
class Namespace {
public:
	Namespace();
	~Namespace();

	int GetLabel(const char* name);
	int GetString(const char* content);
	int GetVariable(const char* name);
	
	int PushBlock();
	int CreateVariable(const char* name, CTypePtr type);
	int PopBlock();

private:
	struct MM3HashVal {
		uint64_t data[2];
	};

	MM3HashVal CalculateMM3Hash(const char* str);


	typedef int LabelRef;

	struct StringRef {
		int id;
		std::string value;
	};

	struct VariableRef {
		CTypePtr type;
		int id;
	};

	typedef std::map<MM3HashVal, LabelRef> LabelTable;
	typedef std::map<MM3HashVal, StringRef> StringTable;
	typedef std::map<MM3HashVal, VariableRef> VariableTable;
	typedef std::deque<VariableTable> VariableTableList;

	LabelTable _labeltable;
	StringTable _stringtable;
	VariableTableList _variabletablelist;
};
*/
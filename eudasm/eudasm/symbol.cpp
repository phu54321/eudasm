/*

#include <unordered_map>
#include <stack>
#include <time.h>

#include "symbol.hpp"


static std::stack<int> _prefix_offset;
static char _prefix[1024];

void InitSymbolList() {
	_prefix_offset.push(0);
}

void PushBlock() {
	int n;
	sprintf(_prefix + _prefix_offset.top(), "_prefix_rnd%d_%n", rand(), &n);
	_prefix_offset.push(_prefix_offset.top() + n);
}

static std::unordered_map<std::string, Variable> _vartable;

int CreateVariable(Vartype type, const std::string& name) {
	std::string prefixed_name(_prefix);
	prefixed_name += name;
	
	auto it = _vartable.find(prefixed_name);
	if(it != _vartable.end()) {
		return -1;
	}
	else {
		Variable var = {_vartable.size(), type};
		_vartable.insert(std::make_pair(prefixed_name, var));
		return var.ID;
	}
}

Variable GetVariable(Vartype type, const std::string& name) {
	std::string prefixed_name(_prefix);
	prefixed_name += name;
	
	auto it = _vartable.find(prefixed_name);
	if(it != _vartable.end()) {
		return it->second;
	}
	else {
		Variable var = {-1, VAR_FULL};
		return var;
	}
}

Variable GetTempVariable() {
	char tmpname[256];
	static int tmpid = 0;
	static int random = (int)time(NULL);
	sprintf(tmpname, "_tmp_t%d_t%d", random, tmpid++);

	return GetVariable(VAR_FULL, tmpname);
}


void PopBlock() {
	_prefix_offset.pop();
	_prefix[_prefix_offset.top()] = 0;
}





static std::unordered_map<std::string, Function> _functable;

Function CreateFunction(const std::string& funcname, int argn) {
	auto it = _functable.find(funcname);
	if(it != _functable.end()) {
		Function func = {-1, -1};
		return func;
	}
	else {
		Function func = {_functable.size(), argn};
		_functable.insert(std::make_pair(funcname, func));
		return it->second;
	}
}

Function GetFunction(const std::string& funcname) {
	auto it = _functable.find(funcname);
	if(it == _functable.end()) {
		Function func = {-1, -1};
		return func;
	}
	else {
		return it->second;
	}
}


static std::unordered_map<std::string, int> _stringtable;

*/
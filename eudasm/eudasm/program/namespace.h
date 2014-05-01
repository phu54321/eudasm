#pragma once

#include <memory>
#include <string>
#include <map>
#include <deque>

#include "../type/type.h"

class Namespace {
public:
	typedef int LabelRef;

	struct StringRef {
		StringRef(int id, const char* str);
		int id;
		const std::unique_ptr<std::string> value;
	};

	struct VariableRef {
		CTypePtr type;
		int id;
	};

	Namespace();
	~Namespace();

	LabelRef GetLabel(const char* name);
	StringRef GetString(const char* content);
	VariableRef GetVariable(const char* name);
	
	void PushBlock(const char* blockname);
	void CreateVariable(const char* name, CTypePtr type);
	void PopBlock();

private:
	struct MM3HashVal {
		uint64_t data[2];
	};

	MM3HashVal CalculateMM3Hash(const char* str);

	size_t GetNewVariableID();

	typedef std::map<MM3HashVal, LabelRef> LabelTable;
	typedef std::map<MM3HashVal, StringRef> StringTable;
	typedef std::map<MM3HashVal, VariableRef> VariableTable;
	typedef std::deque<VariableTable*> VariableTableList;

	LabelTable _labeltable;
	StringTable _stringtable;
	VariableTableList _variabletablelist;

	size_t _totalvariablenum;
};

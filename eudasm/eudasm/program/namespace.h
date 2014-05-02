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
		const std::shared_ptr<const std::string> value;
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
	
	void PushBlock();
	void CreateVariable(const char* name, CTypePtr type);
	void PopBlock();

public:
	struct MM3HashVal {
		uint64_t data[2];
		bool operator<(const MM3HashVal& rhs) const {
			return data[0] < rhs.data[0] || data[1] < rhs.data[1];
		}
	};

	MM3HashVal CalculateMM3Hash(const char* str) const;

private:
	typedef std::map<MM3HashVal, LabelRef> LabelTable;
	typedef std::map<MM3HashVal, StringRef> StringTable;
	typedef std::map<MM3HashVal, VariableRef> VariableTable;
	typedef std::deque<VariableTable*> VariableTableList;

	LabelTable _labeltable;
	StringTable _stringtable;
	VariableTableList _variabletablelist;

private:
	size_t GetNewVariableID();
	size_t _totalvariablenum;
};

namespace std {

}
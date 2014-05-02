#pragma once

#include "typebase.h"
#include <vector>

class CType_Struct : public CType {
public:
	CType_Struct(const std::vector<CTypePtr>& typelist);
	virtual ~CType_Struct();

	virtual CTypeType GetType() const { return CTypeType::TYPE_STRUCT; }
	virtual bool IsElementaryType() const;
	virtual size_t GetSize() const;
	virtual size_t GetElementNum() const;
	virtual bool GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const;
	virtual void EmitStringRepr(std::ostream& os) const;

	virtual bool IsInstantiable() const;

private:
	std::vector<CTypePtr> _typelist;
	std::vector<int> _offsetlist;
	size_t _size;
};


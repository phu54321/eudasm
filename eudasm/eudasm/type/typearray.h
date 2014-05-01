#pragma once

#include "typebase.h"

class CType_Array : public CType {
public:
	CType_Array(CTypePtr orig, size_t count);
	virtual ~CType_Array();

	virtual CTypeType GetType() const { return CTypeType::TYPE_ARRAY; }
	virtual bool IsElementaryType() const;
	virtual size_t GetSize() const;
	virtual size_t GetElementNum() const;
	virtual bool GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const;
	virtual void EmitStringRepr(std::ostream& os) const;

	virtual bool IsInstantiable() const;

private:
	CTypePtr _orig;
	size_t _cnt;
};

#pragma once

#include "typebase.h"

class CType_Var : public CType {
public:
	CType_Var();
	virtual ~CType_Var();

	virtual CTypeType GetType() const { return CTypeType::TYPE_VAR; }
	virtual bool IsElementaryType() const;
	virtual size_t GetSize() const;
	virtual size_t GetElementNum() const;
	virtual bool GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const;
	virtual void EmitStringRepr(std::ostream& os) const;

	virtual bool IsInstantiable() const;
};

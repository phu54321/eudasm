#pragma once

#include "typebase.h"

class CType_Ref : public CType {
public:
	CType_Ref(CTypePtr orig);
	virtual ~CType_Ref();

	virtual CTypeType GetType() const { return CTypeType::TYPE_REF; }
	virtual bool IsElementaryType() const;
	virtual size_t GetSize() const;
	virtual size_t GetElementNum() const;
	virtual bool GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const;
	virtual void EmitStringRepr(std::ostream& os) const;

	virtual bool IsCastableTo(const CTypePtr type) const;
	virtual bool IsInstantiable() const;

private:
	CTypePtr _orig;
};

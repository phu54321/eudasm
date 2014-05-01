#pragma once

#include "typebase.h"

class CType_Void : public CType {
public:
	CType_Void();
	virtual ~CType_Void();

	virtual CTypeType GetType() const { return CTypeType::TYPE_NONE; }
	virtual bool IsElementaryType() const;
	virtual size_t GetSize() const;
	virtual size_t GetElementNum() const;
	virtual bool GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const;
	virtual void EmitStringRepr(std::ostream& os) const;
};

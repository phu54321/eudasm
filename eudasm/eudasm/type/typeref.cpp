#include "typeref.h"
#include "typeutil.h"

CType_Ref::CType_Ref(CTypePtr orig) : _orig(orig) {
	SetHash(CombineInteger(orig->GetHash(), 0x13198A2E));
}


CType_Ref::~CType_Ref() {}


bool CType_Ref::IsElementaryType() const {
	return false;
}


size_t CType_Ref::GetSize() const {
	return 1;
}


size_t CType_Ref::GetElementNum() const {
	return 1;
}


bool CType_Ref::GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const {
	if(index == 0) {
		ptr = _orig;
		offset = 0;
		return true;
	}
	else {
		ptr = NULL;
		offset = 0;
		return false;
	}
}


void CType_Ref::EmitStringRepr(std::ostream& os) const {
	os << *_orig << '&';
}

bool CType_Ref::IsCastableTo(const CTypePtr type) const {
	if(type->GetType() == CTypeType::TYPE_REF) {
		const CType_Ref* type2 = static_cast<const CType_Ref*>(type.get());
		if(type2->_orig->GetType() == CTypeType::TYPE_NONE) { // conversion to void&
			return true;
		}
	}

	else if(type->GetType() == CTypeType::TYPE_VAR) {
		return true;
	}

	return false;
}

bool CType_Ref::IsInstantiable() const {
	return true;
}

#include "typevoid.h"

CType_Void::CType_Void() {
	SetHash(0x243F6A88);
}


CType_Void::~CType_Void() {}


bool   CType_Void::IsElementaryType() const {
	return true;
}


size_t CType_Void::GetSize() const {
	return 0;
}


size_t CType_Void::GetElementNum() const {
	return 0;
}


bool CType_Void::GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const {
	ptr = NULL;
	offset = 0;
	return false;
}


void CType_Void::EmitStringRepr(std::ostream& os) const {
	os << "void";
}

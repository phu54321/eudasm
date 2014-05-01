#include "typevar.h"

CType_Var::CType_Var() {
	SetHash(0x85A308D3);
}


CType_Var::~CType_Var() {}


bool CType_Var::IsElementaryType() const {
	return true;
}


size_t CType_Var::GetSize() const {
	return 1;
}


size_t CType_Var::GetElementNum() const {
	return 0;
}


bool CType_Var::GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const {
	ptr = NULL;
	offset = 0;
	return false;
}


void CType_Var::EmitStringRepr(std::ostream& os) const {
	os << "var";
}

bool CType_Var::IsInstantiable() const {
	return true;
}

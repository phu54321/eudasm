#include <numeric>

#include "typebase.h"

CType::CType() : _hash(0) {}
CType::~CType() {}

bool CType::operator==(const CType& b) const {
	return this->_hash == b._hash;
}

bool CType::operator!=(const CType& b) const {
	return !(*this == b);
}

bool CType::IsCastableTo(const CTypePtr type) const {
	return false;
}

bool CType::IsInstantiable() const {
	return false;
}


void CType::SetHash(uint32_t newhash) {
	_hash = newhash;
}

uint32_t CType::GetHash() const {
	return _hash;
}


std::ostream& operator<<(std::ostream& os, const CType& type) {
	type.EmitStringRepr(os);
	return os;
}

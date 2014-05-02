#include "typearray.h"
#include "typeutil.h"
#include "../util.h"

CType_Array::CType_Array(CTypePtr orig, size_t cnt) : _orig(orig), _cnt(cnt) {
	if(cnt <= 0) {
		throw ParserException("Only array with positive item count is allowed.");
	}

	else if(!orig->IsInstantiable()) {
		if(orig->GetType() == CTypeType::TYPE_NONE) {
			throw ParserException("void[] not allowed.");
		}
		else {
			throw ParserException("Cannot make array of noninstantiable type not allowed.");
		}
	}

	// calculate hash
	uint32_t hashvalue = 0x03707344;
	for(uint32_t i = 0 ; i < cnt ; i++) {
		hashvalue = CombineInteger(hashvalue, orig->GetHash());
	}
	SetHash(hashvalue);
}


CType_Array::~CType_Array() {}


bool CType_Array::IsElementaryType() const {
	return true;
}


size_t CType_Array::GetSize() const {
	return _orig->GetSize() * _cnt;
}


size_t CType_Array::GetElementNum() const {
	return 0;
}


bool CType_Array::GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const {
	if(index < _cnt) {
		ptr = _orig;
		offset = _orig->GetSize() * index;
		return true;
	}

	else {
		ptr = NULL;
		offset = 0;
		return false;
	}
}


void CType_Array::EmitStringRepr(std::ostream& os) const {
	os << *_orig << '[' << _cnt << ']';
}


bool CType_Array::IsInstantiable() const {
	return true;
}

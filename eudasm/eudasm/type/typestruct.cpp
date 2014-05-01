#include "typestruct.h"
#include "typeutil.h"
#include "../util.h"

#include <numeric>

CType_Struct::CType_Struct(std::vector<CTypePtr> typelist) : _typelist(typelist) {
	for(auto type : _typelist) {
		if(!type->IsInstantiable()) {
			throw ParserException("Struct cannot have noninstantiable typed variable in it.");
		}
	}

	// calculate hash & offset table
	uint32_t hashvalue = 0xA4093822;

	_size = std::accumulate(_typelist.begin(), _typelist.end(), 0, [&](int offset, CTypePtr p) {
		hashvalue = CombineInteger(hashvalue, p->GetHash());
		_offsetlist.push_back(offset);
		return offset + p->GetSize();
	});

	SetHash(hashvalue);
}


CType_Struct::~CType_Struct() {}


bool CType_Struct::IsElementaryType() const {
	return true;
}


size_t CType_Struct::GetSize() const {
	return 1;
}


size_t CType_Struct::GetElementNum() const {
	return 0;
}


bool CType_Struct::GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const {
	if(index < _typelist.size()) {
		ptr = _typelist[index];
		offset = _offsetlist[index];
		return true;
	}
	
	else {
		ptr = NULL;
		offset = 0;
		return false;
	}
}

void CType_Struct::EmitStringRepr(std::ostream& os) const {
	os << "struct" << GetHash();
}

bool CType_Struct::IsInstantiable() const {
	return true;
}
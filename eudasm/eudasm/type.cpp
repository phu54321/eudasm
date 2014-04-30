#include "type.h"
#include <numeric>

CType::CType() {}
CType::~CType() {}


/****/ CType_Void::CType_Void() {}
/****/ CType_Void::~CType_Void() {}
bool   CType_Void::IsElementaryType() const { return true; }
size_t CType_Void::GetSize() const { return 0; }
size_t CType_Void::GetElementNum() const { return 0; }
bool   CType_Void::GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const {
	ptr = NULL;
	offset = 0;
	return false;
}


/****/ CType_Var::CType_Var() {}
/****/ CType_Var::~CType_Var() {}
bool   CType_Var::IsElementaryType() const { return true; }
size_t CType_Var::GetSize() const { return 1; }
size_t CType_Var::GetElementNum() const { return 0; }
bool   CType_Var::GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const {
	ptr = NULL;
	offset = 0;
	return false;
}

/****/ CType_Ref::CType_Ref(CTypePtr orig) : _orig(orig) {}
/****/ CType_Ref::~CType_Ref() {}
bool   CType_Ref::IsElementaryType() const { return false; }
size_t CType_Ref::GetSize() const { return 1; }
size_t CType_Ref::GetElementNum() const { return 1; }
bool   CType_Ref::GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const {
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

/****/ CType_Array::CType_Array(CTypePtr orig, size_t cnt) : _orig(orig), _cnt(cnt) { if(cnt < 0) { perror("fuck"); exit(-1); } }
/****/ CType_Array::~CType_Array() {}
bool   CType_Array::IsElementaryType() const { return true; }
size_t CType_Array::GetSize() const { return _orig->GetSize() * _cnt; }
size_t CType_Array::GetElementNum() const { return 0; }
bool   CType_Array::GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const {
	if(index >= 0 && index < _cnt) {
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

/****/ CType_Struct::CType_Struct(std::vector<CTypePtr> typelist) : _typelist(typelist) {
	_size = std::accumulate(_typelist.begin(), _typelist.end(), 0, [&](int offset, CTypePtr p) {
		_offsetlist.push_back(offset);
		return offset + p->GetSize();
	});
}

/****/ CType_Struct::~CType_Struct() {}
bool   CType_Struct::IsElementaryType() const { return true; }
size_t CType_Struct::GetSize() const { return 1; }
size_t CType_Struct::GetElementNum() const { return 0; }
bool   CType_Struct::GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const {
	if(index >= 0 && index < _typelist.size()) {
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

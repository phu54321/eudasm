#pragma once

#include <stdio.h>
#include <memory>
#include <vector>

class CType;
typedef std::shared_ptr<CType> CTypePtr;

class CType {
public:
	CType();
	virtual ~CType();

	virtual bool IsElementaryType() const = 0;
	virtual size_t GetSize() const = 0;
	virtual size_t GetElementNum() const = 0;
	virtual bool GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const = 0;
};

class CType_Void : public CType {
public:
	CType_Void();
	virtual ~CType_Void();

	virtual bool IsElementaryType() const;
	virtual size_t GetSize() const;
	virtual size_t GetElementNum() const;
	virtual bool GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const;
};

class CType_Var : public CType {
public:
	CType_Var();
	virtual ~CType_Var();

	virtual bool IsElementaryType() const;
	virtual size_t GetSize() const;
	virtual size_t GetElementNum() const;
	virtual bool GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const;
};

class CType_Ref : public CType {
public:
	CType_Ref(CTypePtr orig);
	virtual ~CType_Ref();

	virtual bool IsElementaryType() const;
	virtual size_t GetSize() const;
	virtual size_t GetElementNum() const;
	virtual bool GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const;

private:
	CTypePtr _orig;
};

class CType_Array : public CType {
public:
	CType_Array(CTypePtr orig, size_t count);
	virtual ~CType_Array();

	virtual bool IsElementaryType() const;
	virtual size_t GetSize() const;
	virtual size_t GetElementNum() const;
	virtual bool GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const;

private:
	CTypePtr _orig;
	size_t _cnt;
};

class CType_Struct : public CType {
public:
	CType_Struct(std::vector<CTypePtr> typelist);
	virtual ~CType_Struct();

	virtual bool IsElementaryType() const;
	virtual size_t GetSize() const;
	virtual size_t GetElementNum() const;
	virtual bool GetElementTypePtr(int index, CTypePtr& ptr, size_t& offset) const;

private:
	std::vector<CTypePtr> _typelist;
	std::vector<int> _offsetlist;
	size_t _size;
};

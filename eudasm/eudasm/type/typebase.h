#pragma once

#include <memory>
#include <ostream>

enum class CTypeType {
	TYPE_NONE,
	TYPE_VAR,
	TYPE_REF,
	TYPE_ARRAY,
	TYPE_STRUCT
};

class CType;
typedef std::shared_ptr<CType> CTypePtr;

class CType {
public:
	CType();
	virtual ~CType();

	virtual CTypeType GetType() const = 0;
	virtual bool IsElementaryType() const = 0;
	virtual size_t GetSize() const = 0;
	virtual size_t GetElementNum() const = 0;
	virtual bool GetElementTypePtr(size_t index, CTypePtr& ptr, size_t& offset) const = 0;
	virtual void EmitStringRepr(std::ostream& os) const = 0;
	
	bool operator==(const CType& b) const;
	bool operator!=(const CType& b) const;

	virtual bool IsCastableTo(const CTypePtr type) const;
	virtual bool IsInstantiable() const;


public:
	void SetHash(uint32_t hash);
	uint32_t GetHash() const;

private:
	uint32_t _hash;
};

std::ostream& operator<<(std::ostream& os, const CType& type);

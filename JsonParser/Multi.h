#pragma once
#include "Type.h"
#include "Vector.hpp"
#include "SharePtr.hpp"

class Multi : public Type
{
protected:
	Vector<SharedPtr<Type>> types;
public:
	Multi() = default;
	Multi(const MyString& fieldName, size_t indent);
	virtual void print(std::ostream& os) const = 0;
	virtual ObjectTypes getObjectType() const = 0;
	virtual Type* clone() const = 0;
	virtual void create(const MyString* pathArr, size_t pathSize, MyString&& value) = 0;

	//void searchKey(Array& searchArray, const MyString& key) override;
	void setValue(const MyString* pathArr, size_t pathSize, MyString&& value) override;
	void deleteAt(const MyString* pathArr, size_t pathSize) override;

	void addToMulti(Type* type);

	virtual ~Multi() = default;
};
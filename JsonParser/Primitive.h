#pragma once
#include "Object.h"
#include <iostream>

class Primitive : public Type 
{
	MyString value;
public:
	Primitive(const MyString& fieldName, size_t indent, const MyString& value);
	void print(std::ostream& os) const override;
	ObjectTypes getObjectType() const override;
	//void searchKey(Array& searchArray, const MyString& key) override;
	void setValue(const MyString* pathArr, size_t pathSize, MyString&& value) override;
	void deleteAt(const MyString* pathArr, size_t pathSize) override;
	void create(const MyString* pathArr, size_t pathSize, MyString&& value) override;
	const Type& getTypeFromPath(const MyString* pathArr, size_t pathSize) const override;

	Type* clone() const override;
};
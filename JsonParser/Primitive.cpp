#include "Primitive.h"

Primitive::Primitive(const MyString& fieldName, size_t indent, const MyString& value) : Type(fieldName, indent), value(value)
{
}

void Primitive::print(std::ostream& os) const
{
	printIndent(os);
	os << fieldName << ":";
	os << value;
}

ObjectTypes Primitive::getObjectType() const
{
	return ObjectTypes::String;
}
/*
void Primitive::searchKey(Array& searchArray, const MyString& key)
{
	if (checkFieldNameMatches(key))
		searchArray.addToArray(this->clone());
}
*/
void Primitive::setValue(const MyString* pathArr, size_t pathSize, MyString&& value)
{
	throw std::exception("Invalid path!");//type change happens from object or array
}

void Primitive::deleteAt(const MyString* pathArr, size_t pathSize)
{
	throw std::exception("Invalid path!");//type deletion happens from object or array
}

void Primitive::create(const MyString* pathArr, size_t pathSize, MyString&& value)
{
	throw std::exception("Invalid path!");//type creation happens from object or array
}

Type* Primitive::clone() const
{
	return new Primitive(*this);
}
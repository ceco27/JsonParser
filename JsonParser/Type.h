#pragma once
#include "MyString.h"
//#include "Array.h"

enum class ObjectTypes
{
	String,
	Array,
	Object
};

class Type
{
protected:
	MyString fieldName;
	size_t indent = 0;
public:
	Type() = default;
	Type(const MyString& fieldName, size_t indent);
	virtual void print(std::ostream& os) const = 0;
	virtual ObjectTypes getObjectType() const = 0;
	
	virtual Type* clone() const = 0;

	//virtual void searchKey(Array& searchArray, const MyString& key) = 0;
	//virtual Type& searchPath(const MyString* path) = 0;
	virtual void setValue(const MyString* pathArr, size_t pathSize, MyString&& value) = 0;
	virtual void deleteAt(const MyString* pathArr, size_t pathSize) = 0;
	virtual void create(const MyString* pathArr, size_t pathSize, MyString&& value) = 0;

	virtual ~Type() = default;
	
	void printIndent(std::ostream& os) const;
	MyString getFieldName() const;
	bool checkFieldNameMatches(const MyString& fieldName) const;
};
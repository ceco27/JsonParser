#pragma once
#include "Multi.h"

class Array : public Multi
{
public:
	Array(const MyString& fieldName, size_t indent);
	void print(std::ostream& os) const override;
	ObjectTypes getObjectType() const override;

	Type* clone() const override;
	void create(const MyString* pathArr, size_t pathSize, MyString&& value) override;
};
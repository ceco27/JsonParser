#pragma once
#include "Multi.h"

class Object : public Multi
{

public:
	Object(const MyString& fieldName, size_t indent);
	void print(std::ostream& os) const override;
	ObjectTypes getObjectType() const override;
	void create(const MyString* pathArr, size_t pathSize, MyString&& value) override;

	Type* clone() const override;

};
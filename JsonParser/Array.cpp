#include "Array.h"
#include "Primitive.h"

Array::Array(const MyString& fieldName, size_t indent) : Multi(fieldName, indent)
{
}

void Array::print(std::ostream& os) const
{
	printIndent(os);
	os << fieldName << ": [" << std::endl;
	int objectsCount = types.getSize();

	for (size_t i = 0; i < objectsCount; i++)
	{
		types[i]->print(os);
		if (i != objectsCount - 1)
			os << "," << std::endl;
	}

	printIndent(os);
	os << std::endl << "]" << std::endl;
}

ObjectTypes Array::getObjectType() const
{
	return ObjectTypes();
}

Type* Array::clone() const
{
	return new Array(*this);
}

void Array::create(const MyString* pathArr, size_t pathSize, MyString&& value)
{
	if (checkFieldNameMatches(pathArr[pathSize - 1]) && pathSize == indent)
	{
		addToMulti(new Primitive(MyString(), indent + 1, std::move(value)));
		return;
	}
/*
	size_t typesSize = types.getSize();
	for (size_t i = 0; i < typesSize; i++)
	{
		if (types[i]->checkFieldNameMatches(pathArr[indent]))
		{
			
		}
	}
	*/
}

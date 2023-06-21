#include "Multi.h"
#include "Primitive.h"

Multi::Multi(const MyString& fieldName, size_t indent) : Type(fieldName, indent)
{
}
/*
void Multi::searchKey(Array& searchArray, const MyString& key)
{
	size_t typesSize = types.getSize();
	for (size_t i = 0; i < typesSize; i++)
	{
		if (types[i]->checkFieldNameMatches(key))
		{
			searchArray.addToArray(types[i]->clone());
		}
	}
}
*/
void Multi::setValue(const MyString* pathArr, size_t pathSize, MyString&& value)
{
	size_t typesSize = types.getSize();

	for (size_t i = 0; i < typesSize; i++)
	{
		if (types[i]->checkFieldNameMatches(pathArr[indent - 1]))
		{
			if (pathSize - 1 == indent)
			{
				types[i] = new Primitive(pathArr[indent - 1], indent, value);
				return;
			}
			else
			{
				types[i]->setValue(pathArr, pathSize, std::move(value));
				return;
			}
		}
	}

	throw std::exception("Type not found");
}

void Multi::deleteAt(const MyString* pathArr, size_t pathSize)
{
	size_t typesSize = types.getSize();

	for (size_t i = 0; i < typesSize; i++)
	{
		if (types[i]->checkFieldNameMatches(pathArr[indent - 1]))
		{
			if (pathSize - 1 == indent)
			{
				types.popAt(i);
				return;
			}
			else
			{
				types[i]->deleteAt(pathArr, pathSize);
				return;
			}
		}
	}

	throw std::exception("Type not found");
}

void Multi::addToMulti(Type* type)
{
	types.pushBack(type->clone());
}

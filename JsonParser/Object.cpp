#include "Object.h"
#include "Primitive.h"

Object::Object(const MyString& fieldName, size_t indent) : Multi(fieldName, indent)
{
}

void Object::print(std::ostream& os) const
{
	printIndent(os);
	
	if (fieldName.length() == 0) 
		os << "{" << std::endl;
	else
		os << fieldName << ": {" << std::endl;

	int objectsCount = types.getSize();

	for (size_t i = 0; i < objectsCount; i++)
	{
		types[i]->print(os);
		if (i != objectsCount - 1)
			os << "," << std::endl;
	}

	os << std::endl;
	printIndent(os);
	os << "}";
}

ObjectTypes Object::getObjectType() const
{
	return ObjectTypes::Object;
}

void Object::create(const MyString* pathArr, size_t pathSize, MyString&& value)
{
	size_t typesSize = types.getSize();
	for (size_t i = 0; i < typesSize; i++)
	{
		if (types[i]->checkFieldNameMatches(pathArr[indent]))
		{
			if (indent == pathSize)
			{
				throw std::exception("Type already exists!");
			}
			else
			{
				types[i]->create(pathArr, pathSize, std::move(value));
				return;
			}
		}
	}

	if (pathSize - 1 == indent)
	{
		types.pushBack(new Primitive(pathArr[indent], indent + 1, std::move(value)));
	}
	else
	{
		types.pushBack(new Object(pathArr[indent], indent + 1));
		types[typesSize]->create(pathArr, pathSize, std::move(value));
	}
}

Type* Object::clone() const
{
	return new Object(*this);
}


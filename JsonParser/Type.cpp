#include "Type.h"

void Type::printIndent(std::ostream& os) const
{
	for (size_t i = 0; i < indent; i++)
	{
		os << "    ";
	}
}

MyString Type::getFieldName() const
{
	return MyString(fieldName);
}

bool Type::checkFieldNameMatches(const MyString& fieldName) const
{
	return this->fieldName == fieldName;
}

Type::Type(const MyString& fieldName, size_t indent) : fieldName(fieldName), indent(indent)
{
}

#pragma once
#include "Object.h"
class Command
{
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
};
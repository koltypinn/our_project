#pragma once
#ifndef SERIALIZATION_H__
#define SERIALIZATION_H__

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif

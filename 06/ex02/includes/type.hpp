#pragma once
#ifndef TYPE_H__
#define TYPE_H__

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif
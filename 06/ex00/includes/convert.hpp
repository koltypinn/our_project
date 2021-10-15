#pragma once
#ifndef CONVERT_H__
#define CONVERT_H__

#include <iostream>
#include <stdlib.h>
#include <errno.h>

typedef struct      s_status
{
    double          raw;
    std::string     type;
    std::string     arg;
}                   t_status;

void                convert(char *arg);

#endif

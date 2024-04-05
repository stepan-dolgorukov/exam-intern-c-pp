#ifndef PAIR_FLOAT_H
#define PAIR_FLOAT_H

#include <stdbool.h>

struct pair_float
{
  float components[2];
};

bool
in_pair( float value,
         const struct pair_float* pair );

#endif
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#include "pair_float.h"

bool
in_pair( float value,
         const struct pair_float* pair )
{
  /* Если пара отсутствует, то в ней не может содержаться любой элемент. */
  if( NULL == pair )
  {
    return false;
  }

  const int length =
    sizeof( pair->components )
    /
    sizeof( pair->components[ 0 ] );

  for( int i = 0; i < length; ++i )
  {
    if( value == pair->components[ i ] )
    {
      return true;
    }
  }

  return false;
}

bool
in_pair_with_precision( float value,
                        const struct pair_float* pair,
                        float precision                )
{
  /* Если пара отсутствует, то в ней не может содержаться любой элемент. */
  if( NULL == pair )
  {
    return false;
  }

  const int length =
    sizeof( pair->components )
    /
    sizeof( pair->components[ 0 ] );

  for( int i = 0; i < length; ++i )
  {
    if( fabsf( value - pair->components[ i ] ) < precision )
    {
      return true;
    }
  }

  return false;
}
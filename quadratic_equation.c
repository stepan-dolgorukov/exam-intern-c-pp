#include "quadratic_equation.h"

struct pair_float
solve_equation( float a,
                float b,
                float c  )
{
  struct pair_float
    answer = {
               .components[ 0 ] = NAN,
               .components[ 1 ] = NAN  };

  if( .0f == a )
  {
    return answer;
  }

  const float
    discriminant = ( b * b ) - ( 4 * a * c );

  if( .0f > discriminant )
  {
    return answer;
  }

  if( .0f == discriminant )
  {
    answer.components[ 0 ] =
    answer.components[ 1 ] = -b
                             /
                             ( 2.f * a );
    return answer;
  }

  answer.components[ 0 ] = ( -b + sqrt( discriminant ) )
                           /
                           ( 2. * a );

  answer.components[ 1 ] = ( -b - sqrt( discriminant ) )
                           /
                           ( 2. * a );

  return answer;
}
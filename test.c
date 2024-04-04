#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "quadratic_equation.h"
#include "pair_float.h"

int
main( void )
{

  /* x^2 + 10x + 25 = (x + 5)^2 = 0 */
  {
    const struct pair_float
      answer = solve_equation( 1.f, 10.f, 25.f );

    assert( -5.f == answer.components[ 0 ] &&
            answer.components[ 0 ] == answer.components[ 1 ] );
  }

  /* x^2 + x + 1 = 0 */
  {
    const struct pair_float
      answer = solve_equation( 1.f, 1.f, 1.f );

    assert( isnan( answer.components[ 0 ] ) &&
            isnan( answer.components[ 1 ] )    );
  }

  /* 4x^2 + 5x + 1 = 0 */
  {
    const struct pair_float
      answer = solve_equation( 4.f, 5.f, 1.f );

    assert( ( -.25f == answer.components[ 0 ] &&
              -1.f == answer.components[ 1 ]     ) ||

            ( -1.f == answer.components[ 1 ] &&
              -.25f == answer.components[ 0 ]   )     );
  }

  return 0;
}
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "quadratic_equation.h"
#include "pair_float.h"

#define PRECISION ( 1e-6 )

void
run_cases_with_no_roots( void )
{
  /* x^2 + x + 1 = 0 */
  {
    const struct pair_float
      answer = solve_equation( 1.f,
                               1.f,
                               1.f  );

    assert( isnan( answer.components[ 0 ] ) &&
            isnan( answer.components[ 1 ] )    );
  }

  /* 8592.5 * x^2 + 327.12 * x + 3.125 = 0 */
  {
    const struct pair_float
      answer = solve_equation( 8592.5f,
                               327.12f,
                               3.125f   );

    assert( isnan( answer.components[ 0 ] ) &&
            isnan( answer.components[ 1 ] )    );
  }

  /* x^2 - 0.73 * x + 0.137 */
  {
    const struct pair_float
      answer = solve_equation( 1.f,
                               0.73f,
                               0.137f );

    assert( isnan( answer.components[ 0 ] ) &&
            isnan( answer.components[ 1 ] )    );
  }
}

void
run_cases_with_equal_roots( void )
{
  /* x^2 + 10x + 25 = (x + 5)^2 = 0 */
  {
    const struct pair_float
      answer = solve_equation( 1.f,
                               10.f,
                               25.f  );

    assert( in_pair_with_precision( -5.0f, &answer, PRECISION ) &&
            answer.components[ 0 ] == answer.components[ 1 ]       );
  }

  /* 0.45 * x^2 + 1.5 * x + 1.25 */
  {
    const struct pair_float
      answer = solve_equation( .45f,
                               1.5f,
                               1.25f );

    assert( in_pair_with_precision( -5.f / 3.f, &answer, PRECISION ) &&
            answer.components[ 0 ] == answer.components[ 1 ]            );
  }

  /* x^2 = 0 */
  {
    const struct pair_float
      answer = solve_equation( 1.f,
                               0.f,
                               0.f  );

    assert( in_pair_with_precision( 0.0f, &answer, PRECISION ) &&
            answer.components[ 0 ] == answer.components[ 1 ]      );
  }
}

void
run_cases_with_different_roots( void )
{
  /* 4x^2 + 5x + 1 = 0 */
  {
    const struct pair_float
      answer = solve_equation( 4.f,
                               5.f,
                               1.f  );

    assert( in_pair_with_precision( -.25f, &answer, PRECISION ) &&
            in_pair_with_precision( -1.f, &answer, PRECISION )     );
  }
}

int
main( void )
{
  run_cases_with_no_roots(  );
  run_cases_with_equal_roots(  );
  run_cases_with_different_roots(  );

  return 0;
}
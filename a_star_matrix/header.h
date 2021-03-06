#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define INF (1 << 20)

typedef unsigned char Byte;
typedef long long Integer;
typedef long double Rational;
typedef void* Generic;

#include "basic_structures/heap.h"

#include "matrix_related/pair.h"
#include "matrix_related/matrix.h"
#include "matrix_related/a_star_matrix.h"

#include "utility_functions/utility.h"


﻿##solve##
找规律+打表

$A[0][n] = n + 1$

$A[1][0] = A[0][1], A[1][n] = A[1][n - 1] + 1$

$A[2][0] = A[1][1], A[2][n] = A[2][n - 1] + 2$

$A[3][0] = A[2][1], A[3][n] = A[3][n - 1] * 2 + 3$
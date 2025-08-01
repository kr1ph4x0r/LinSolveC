# 📐 Fast C linear System Solvers

## To build :
```bash
gcc -O3 -o main main.c -lm [model]/*.c
```

## Pipeline :

1. **Pivot Partial + Decomposition :**  
  Course each pivot and decay the input to resolve.

2. **System Resolution :**
  Resolve the forward/backward substitution.

-------------------------------------------------------------------------

🔹 Create the 3x3 Matrix :
```c
double A[N][N] = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
}
```

🔹 Create the vector result :
```c
double b[N] = {5, 3, 7};
```

🔹 Compute the unknow vector :
```c
if (lu_decay(A) != 0) return 1;

forward_subs(A, b, x);
backward_subs(A, y, x);
```

🔹 Print the result :
```c
for (int i=0; i<N; i++)
  printf("x%d %.5f\n", i+1, x[i]);
```

## ⚠️ Issue :
If the `pivot` is `null` (diagonal too small), the decay explodes !

# kr1p.c on discord for any questions

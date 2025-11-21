# Algorithm optimization in C

## Fibonacci Number Generation

Fibonacci Numbers are defined as:
```math
F_n = \begin{cases}
F_{n-1} + F_{n-2}, & n \geq2 \\
1, & n = 1 \\
0, & n = 0
\end{cases}
```

### Algorithms

| Algorithm                      |                 Time Complexity                 |
|--------------------------------|:-----------------------------------------------:|
| Naive Recursive                |                    $O(2^n)$                     |
| Linear                         |                    $O(n^2)$                     |
| Matrix Multiplication (Naive)  |                    $O(n^3)$                     |
| Fast Exponentiation            |                 $O(n^2 log(n))$                 |
| 3-vector Fast Exponentiation   |                 $O(n^2 log(n))$                 |
| 2-vector Fast Exponentiation   |                 $O(n^2 log(n))$                 |
| Fast Doubling                  |                 $O(n^2 log(n))$                 |
| GMP implementation (Reference) | (uses fast doubling on hand-optimized assembly) |

### Naive Recursive Algorithm

By definition:
$F_n = F_{n-1} + F_{n-2}$

```python
def fib_naive(n: int):
    if n < 2:
        return n

    return fib_naive(n - 1) + fib_naive(n - 2)
```

### Linear Algorithm

The "linear" algorithm has a time complexity of $O(n^2)$, because each addition of two n-bit numbers takes $O(n)$ time,
and we perform n such additions.

```python
def fib_linear(n: int):
    if n < 2:
        return n

    a, b = 0, 1

    for _ in range(2, n + 1):
        a, b = b, a + b

    return b
```

### Matrix Multiplication (Naive)

[Fibonacci Sequence (Matrix Form) - Wikipedia](https://en.wikipedia.org/wiki/Fibonacci_sequence#Matrix_form)

Fibonacci numbers can be computed using matrix exponentiation:

```math
\begin{bmatrix}
0 & 1 \\ 1 & 1
\end{bmatrix}
^n
=
\begin{bmatrix}
F_{n-1} & F_n \\ F_n & F_{n-1}
\end{bmatrix}
```

So:

```math
\begin{bmatrix}
F_{n} \\ F_{n+1}
\end{bmatrix}
=
\begin{bmatrix}
0 & 1 \\ 1 & 1
\end{bmatrix}^n
\begin{bmatrix}
0 \\ 1
\end{bmatrix}
```

Adding up to 8 multiplications and 4 additions for each matrix multiplication, the naive matrix multiplication method
has a time complexity of $O(n^3)$.

Those multiplications can be drastically reduced using the following methods.

### Fast Exponentiation Method

To compute the power of a matrix efficiently, we can use the method of exponentiation by squaring:
```math
x^n = \begin{cases}
x(x^2)^{(n-1)/2} & \text{if } n \text{ is odd} \\
(x^2)^{n/2} & \text{if } n \text{ is even}
\end{cases}
```

Reducing the number of multiplications to $O(log(n))$.

[Exponentiation by Squaring - Wikipedia](https://en.wikipedia.org/wiki/Exponentiation_by_squaring)

### 3-vector Fast Exponentiation

Since the Fibonacci matrix
```math
Q =
\begin{bmatrix}
0 & 1 \\ 1 & 1
\end{bmatrix}
```

is symmetric, every power of $Q$ will also be a symmetrix 2x2 matrix. Any symmetrix 2x2 matrix can be encoded as a
3-vector:
```math
\begin{bmatrix}
a \\ b \\ c
\end{bmatrix}
```

We can define this behavior as a linear map:

```math
\phi:\mathbf{R}^3 \to M_{2x2}(\mathbf{R}), \quad
\phi
\begin{bmatrix}
a \\ b \\ c
\end{bmatrix}
=
\begin{bmatrix}
a & b \\ b & c
\end{bmatrix}
```

Matrix multiplication on 2x2 matrices then translates to multiplication on the 3-vectors:

```math
\phi
\begin{bmatrix}
a \\ b \\ c
\end{bmatrix}
\phi
\begin{bmatrix}
a' \\ b' \\ c'
\end{bmatrix}
=
\begin{bmatrix}
aa' + bb' & ab' + bc' \\ ab' + bc' & bb' + cc
\end{bmatrix}
```

Projecting this product back to $\mathbf{R}^3$ gives us the following definition:

```math
\begin{bmatrix}
a \\ b \\ c
\end{bmatrix}
\otimes
\begin{bmatrix}
a' \\ b' \\ c'
\end{bmatrix}
:=
\begin{bmatrix}
aa' + bb' \\ ab' + bc' \\ bb' + cc'
\end{bmatrix}
```

Reducing the number of multiplications from 8 to 6 and additions from 4 to 3.

### 2-vector Fast Exponentiation

Each power of the Fibonacci matrix

```math
Q =
\begin{bmatrix}
0 & 1 \\ 1 & 1
\end{bmatrix}
```

can be encoded as the pair $(F_{n+1}, F_n)$, which corresponds to the second column of $Q^n$. THis is sufficient becuase
the first column is just a shifted version of the second column.

Define a 2-vector:

```math
v_Q =
\begin{bmatrix}
a \\ b
\end{bmatrix}
\leftrightarrow
\begin{bmatrix}
a - b & b \\ b & a
\end{bmatrix}
```

Matrix multiplication on 2x2 matrices then translates to multiplication on the 2-vectors:

```math
\begin{bmatrix}
a \\ b
\end{bmatrix}
\otimes
\begin{bmatrix}
a' \\ b'
\end{bmatrix}
:=
\begin{bmatrix}
aa' + bb' \\ ab' + ba' + bb'
\end{bmatrix}
```

Reducing the number of multiplications from 6 to 4 and additions from 3 to 2.

### Fast Doubling

Using the identities:
```math
F_{2n} = F_n(2F_{n+1} - F_n)
```
```math
F_{2n+1} = F_{n+1}^2 + F_n^2
```

# Usage

*GMP must be installed via Homebrew*

```bash
mkdir build \
  && cd build \
  && cmake .. \
  && cmake --build .
```

### Rebuild

```bash
cd build \
  && cmake --build . --clean-first
```

### Usage

```python
from fibonacci import fib_fast_doubling

print(fib_fast_doubling(5))
```



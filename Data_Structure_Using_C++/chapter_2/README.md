# Array
- Sequential list
- Ordered list
- One Dimention Array
> int A[20]
- Two Dimention Array
> int A[20][19]
- Three Dimention Array
> int A[20][19][30]

## Lvalue and Rvalue
- `Lvalue`: **const** or varialbes, they are only have one unique memeory address.(variable data is Rvalue, can be change in anywhere)
- `Rvalue`: the value that can be change dynamically.

### Learning topic: 2.4 practice 
- represnet the polynomial as a array (n is exponent, m is coefficient)
    1. the first element is the biggist number of exponent, and store coefficient only (n+2)
    2. the first elemnet is all non-zeor coefficient, and store coefficient and exponent together (2m+1)
    - for instance: p = 8x^5 + 6x^4 + 3x^2 + 12
        - 1. p = (5, 8, 6, 0, 3, 0, 12)
        - 2. p = (4, 5, 8, 4, 6, 2, 3, 0, 12), n before m
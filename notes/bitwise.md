# Bitwise

## Two's complement
- [video](https://youtu.be/4qH4unVtJkE)
- Consider only 4 bits, the form will be like:
```txt
1 000   -8
1 001   -7
1 010   -6
1 011   -5
1 100   -4
1 101   -3
1 110   -2
1 111   -1

0 000   0
0 001   1
0 010   2
0 011   3
0 100   4
0 101   5
0 110   6
0 111   7
```
- The first bit is signed bit, but it also has a mathematical meaning - e.g. `1 000` is like `-1 * 8 + 0`, `1 100` is like `-1 * 8 + 4`
- Because of the mathematical meaning, the add/sub works naturally - e.g. `5 + -5` = `0 101` + `1 011` = `(1)` `0000`, or you can see it like `5 + -8 + 3`
- The only tricky things are ...
  - positive -> negative requires a inverse than add one, e.g. -p = (~p) + 1
  - there is -8 above but no 8
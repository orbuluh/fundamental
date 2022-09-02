# Bitwise

## Size of integers in C++
- from [stackoverflow](https://stackoverflow.com/questions/18353168/why-long-int-has-same-size-as-int-does-this-modifier-works-at-all)
- All that the standard requires is that:
  - `sizeof(char) == 1`
  - `sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)`
  - (and that the corresponding unsigned types have the same size as the signed types).
- On 16 bit platforms, it is usual for both `short` and `int` to be 16 bits;
- on 32 bit platforms, `int` and `long` are **almost always the same size.**
- On modern 64 bit platforms (with byte addressing), the rational solution would be to **make all four types have different sizes** (although one could argue that according to the standard, int should be 64 bits, which would mean that `int`, `long` and `long long` all had the same size).
- MS choose to make `long` 32 bits even on a 64-bit system is that the existing Windows API, for historical reasons use a mixture of `int` and `long` for similar things, and the expectation is that this is s 32-bit value (some of this goes back to times when Windows was a 16-bit system). So **to make the conversion of old code to the new 64-bit architecture, they choose to keep `long` at 32 bits**, so that applications mixing `int` and `long` in various places would still compile.

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
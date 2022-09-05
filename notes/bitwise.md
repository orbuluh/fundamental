# Bitwise
- [Bit hacks](http://graphics.stanford.edu/~seander/bithacks.html)

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
<details><summary markdown="span">Details</summary>

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

</details>

## Reset the last set bit: `x & (x - 1)`
- I think the way to think about it is that for any number x, say, x = 4 (0100), x - 1 will always set all the LSB's below the lowest set bit and clear the lowest set bit (e.g. 4 - 1 = 3 = 0011.
- quicker way to count bits set with this trick... (only needs set_bit of iteration instead of scan the full 32 bits)
```cpp
unsigned int v = someinput_val; // count the number of bits set in v
unsigned int cnt = 0; // c accumulates the total bits set in v
for (; v; cnt++)
{
  v &= v - 1; // clear the least significant bit set
}
```

## Isolate the least significant bit: `x & (-x)`

<details><summary markdown="span">Proof</summary>

- Say `x = a1b` (in binary) is the number whose least significant bit we want to isolate.
  - `a` is some binary sequence of any length of 1’s and 0’s and
  - `b` is some sequence of any length but of **0’s only**.
  - That tiny intermediate 1 bit sitting between **a** and **b** to be the least significant bit
- Then
```
-x = 2’s complement of x = (a1b)’ + 1
   = a’0b’ + 1
   = a’0(0...0)’ + 1
   = a’0(1...1) + 1
   = a’1(0...0)
   = a’1b
```
- Then
```
        a  1 b     ->  X
&       a' 1 b     -> -X
-----------------
=  (0...0) 1 (0...0)   ---> e.g. we get the LSB through X & (-x)
```

</details>

## Detect if two integers have opposite signs: `f = (X ^ Y) < 0`
- quicker than `f = x * y < 0`


## Common mask
- `0x5` == `0101`
- `0xA` == `1010`
- `0x3` == `0011`
- `0xC` == `1100`
- `0x0` == `0000`
- `0xF` == `1111`

- Reversing the bits in integer
```
x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
```
- Conceptually ...
  - ABCD -> `((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)` -> BADC
  - BADC -> `((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)` -> DCBA

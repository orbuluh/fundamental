/*
    (a ^ b) gives you the result of sum (without carry)
    (a & b) << 1 gives you the result of carry

    so it's like you keep doing a ^ b to derived the sum
    without carry, then you add the carry bit, till carry
    is no longer needed.

    The main issue is dealing with overflow. For C++, int
    is 32 bits, you just need to make sure when you are
    doing shift, you are working on a higher bits of
    representation, and you can just ignore the bits after
    the right 32 bits with a mask
*/

class Solution {
 public:
  static constexpr int64_t maskOf32Bits = 0xffffffff;
  int getSum(int a, int b) {
    int64_t carry = 0;
    while (b != 0) {
      carry = a & b;
      a = a ^ b;
      // limited to 32 bits
      b = ((carry & maskOf32Bits) << 1);
    }

    return a;
  }
};
/*
@StefanPochmann's math solution ...

Bulb i is toggle during its divisors round ...
For example, bulb 6 is toggled in round 1, 2, 3, 6
A bulb is only on at the end iff it's toggled odd number of times, which means
the bulb must have odd number of divisors.

What number could have odd number of divisors? Only squares number. Why?

Divisors come in pairs, like i=12 has divisors 1 and 12, 2 and 6, and 3 and 4.

Except when i is a square, like 36 has divisors 1 and 36, 2 and 18, 3 and 12,
4 and 9, and double divisor 6.

So bulb i ends up on if and only if i is a square number.

So, for an input number n, the number of bulb that will still be on are the
bulb with index being a square. E.g. we count number of squares within n.
*/

class Solution {
 public:
  int bulbSwitch(int n) {
    int i = 1;
    while (i * i <= n) {
      i++;
    }
    return i - 1;
  }
};
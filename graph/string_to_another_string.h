/*
making char -> char conversion is like making edge in graph with node being char

The simple case would be several single edges

str1 = ace ; str2 = bdf

a -> b
c -> d
e -> f

And the simple invalid case is when there is one to many mapping

str1 = aa ; str2 = cd

a -> c
a -> d (X) can't be - because one conversion you can convert all occurrences of
one character in str1 to any other lowercase English character - which means
once you do a -> c, str1 = cc, so you can't do a -> d to make it work.

A variant of simple case is we can have many to one mapping

str1 = ab ; str2 = cc

a -> c
b -> c  .... totally fine.

Slightly complicated is linked list like graph. For this, nothing tricky, it's
just a simple one-to-one mapping

str1 = abc ; str2 = bcd

a -> b
b -> c
c -> d

for this, you can do it backward to achieve the conversion:
      str1
      abc
c->d: abd
b->c: acd
a->b: bcd

The tricky thing is when the edge for a cycle:

str1 = abc ; str2 = bca

a -> b
b -> c
c -> a

To achieve this, we need to use a temporary unused char to do the conversion

say we making:
      str1
      abc
a->z  zbc
c->a  zba
b->c  zca
z->b  bca

Note: Cyclic case only works if there exist a "temporary unused char". But when
will be no "temporary unused char"?

-> When s2 exhaust the alphabet while s1 != s2.


Taking further look:


Say alphabet has only 4 chars {a b c d}

s1 = abc
s2 = bca

we could do:

try [a -> b], but realize this would make s1 bbc, where b then need to map to
both b and c. So we can't just do [a->b] conversion.

Rather, we try to point the conflicted one to the unused d first: s1 = adc
then we go back to convert [a-> b]: s1 = bdc, and we know now a is unused.

Then we try to make the [d->c] conversion, but realize this will make s1 = bdd
So we just point c to the unused a first, which gives us bda. Then finally, we
di [d->c], which gives us s1 = bca = s2.


However, if alphabet has only 3 chars {a b c}

s1 = abc
s2 = bca

when we change a->b, it makes bbc.
even if we don't do a->b first, we do b-> c first, we get acc
same if we do c->a first, we get aba

either way, we just can't make sure a conversion in an iteration do what we
want. (There is no simultaneously conversion of a->b, b->c, c->a, we have to do
this one by one)


Exception of observation 2 - when s2 used all the alphabet - the only case that
would have worked is s1 == s2 from the beginning.


Given all above observations, the final implementation is actually simple.
We just make the mapping one by one. If there could have one to many mapping, it
fails. Otherwise at the end, if s2 actually used all the alphabet, it means no
temporary can be used to break the cycle. And because all the alphabet is used,
there must be a cycle, say [a ... y] map to [b ... z] respectively, so the final
option will be z map to a, which eventually makes it a cycle. And in such case,
because no unused temporary can be used, there can't be a conversion.
*/

class Solution {
 public:
  static constexpr int UNUSED = -1;
  bool canConvert(string str1, string str2) {
    if (str1 == str2) return true;
    std::vector<int> mapping(26, UNUSED);
    std::bitset<26> charInS2;
    for (int i = 0; i < str1.size(); ++i) {
      const int c1Idx = str1[i] - 'a';
      const int c2Idx = str2[i] - 'a';
      if (mapping[c1Idx] != UNUSED) {
        // making same char point to different chars, invalid
        if (mapping[c1Idx] != c2Idx) {
          return false;
        }
      } else {
        // c1 hasn't mapped to anything, we just try to map it
        // accordingly
        mapping[c1Idx] = c2Idx;
        charInS2.set(c2Idx);
      }
    }
    return charInS2.count() != 26;
  }
};
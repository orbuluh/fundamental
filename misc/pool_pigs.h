/*
    don't think about how to allocate pig to buckets in each round
    but think about what happen to a pig.

    when we have 2 tests - a pig can either
    - not die at all
    - die in test-1
    - die in test-2

    Say we have 2 pigs ... we can uniquely encounter ...
    pigA pigB
    0    0     - pigA not die, pigB not die
    0    1     - pigA not die, pigB die at test-1
    0    2     - pigA not die, pigB die at test-2
    1    0     - pigA die at test-1, pigB not die
    1    1     - pigA die at test-1, pitB die at test-1
    1    2     - pigA die at test-1, pitB die at test-2
    2    0     - pigA die at test-2, pigB not die
    2    1     - pigA die at test-2, pitB die at test-1
    2    2     - pigA die at test-2, pitB die at test-2

    which means we can actually match this 3^2 cases to 9 bucket
    where the result of case we met represents which bucket is poisonous

    Overall is's basically an encoding problem - each pig represents a bit
    testRound represents the base of the encoding (cases a bit can represents)

    e.g. what we are looking is
    (testCnt + 1) ^ pigCnt >= buckets

    */
class Solution {
  public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        const int testCnt = minutesToTest / minutesToDie;
        int pigCnt = 0;
        while (true) {
            if (pow(testCnt + 1, pigCnt) >= buckets)
                return pigCnt;
            pigCnt++;
        }
        return 0;
    }
};
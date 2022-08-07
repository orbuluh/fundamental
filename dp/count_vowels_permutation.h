class Solution {
  public:
    /*
    dp
    a[i] -> count of string ending with a at i
    e[i] -> count of string ending with e at i
    ...
    ... as we only need previous, we can reduce the memory usage with O(1)

j-1 \ j a e i o u
    a   x o x x x  ('a' may only be followed by an 'e')
    e   o x o x x  ('e' may only be followed by an 'a' or an 'i')
    i   o o x o o  ('i' may not be followed by another 'i'.)
    o   x x o x o  ('o' may only be followed by an 'i' or a 'u')
    u   o x x x x  ('u' may only be followed by an 'a')
    */
    static constexpr int mod = 1'000'000'007;

    template <typename... Args> int add(Args... args) {
        int res = 0;
        // use power of the comma operator for fold expression
        return (
            [&]() {
                res += args;
                return res %= mod;
            }(),
            ...);
    };

    int countVowelPermutation(int n) {
        std::array<int, 2> a{}, e{}, i{}, o{}, u{};
        a[1] = e[1] = i[1] = o[1] = u[1] = 1;
        for (int j = 2; j <= n; ++j) {
            const int cur = j % 2;
            const int pre = !cur;
            a[cur] = add(e[pre], i[pre], u[pre]);
            e[cur] = add(a[pre], i[pre]);
            i[cur] = add(e[pre], o[pre]);
            o[cur] = i[pre] % mod;
            u[cur] = add(i[pre], o[pre]);
        }
        const int cur = n % 2;
        return add(a[cur], e[cur], i[cur], o[cur], u[cur]);
    }
};
/*

Input: ideas = ["coffee","donuts","time","toffee"]

Method 1:

Group ideas by first char, and store the suffix

c: [offee]
d: [onuts]
t: [ime, offee]

For different group here, if they have different suffix, they can form a pair.

c: [offee] v.s. d: [onuts]

-> can form 1 * 1 * 2 (uniq key 1 size * uniq key 2 size * 2)

c: [offee] v.s. t:[ime, offee]

-> offee appear in both, can't form any valid group

d: [onuts] v.s. t:[ime, offee]

-> can form 1 * 2 * 2 (uniq key 1 size * uniq key 2 size * 2)

Overall doing so, the outer comparison loop is constant (first char set) *
(first char set) = O(26 * 26)

But inside the loop, to find the difference set of suffix, it takes
O(unique_suffix_cnt)

//--------------------------------------------------------------

Method 2: suffix as key

offee: [c, t]
onuts: [d]
ime: [t]

group offee v.s. onuts creates 2 * 1 * 2
group offee v.s. ime creates 1 * 0 * 2
group onuts v.s. ime creates 1 * 1 * 2

This will get a TLE because the O(unique_suffix_cnt * unique_suffix_cnt) in
outer loop, And inside to find the difference set of first char, it's constant
O(26 + 26)

//--------------------------------------------------------------

Method 3 (optimal): further improve method2

How to not looping on uniq_suffix_cnt * uniq_suffix_cnt of combination in method
2?

You gather a counter[c1][c2][2], where

for any char pairs {c1, c2}
    : cnt[c1][c2][0]: how many suffix only having c2 but not c1 as first char
      cnt[c1][c2][1]: how many suffix only having c1 but not c2 as first char

Then when you gather the result, it will be a loop on O(26 * 26) again...

offee: [c, t]
onuts: [d]
ime: [t]

chars pairs| suffix only have one of the char
    {c, d} | {offee}    || e.g. there is no doffee exists, only coffee
    {c, t} | {ime}      || e.g. there is no cime exists, only time
    {d, t} | {ime}      || e.g. there is no dime exists, only time
*/

class Solution {
 public:
  long long distinctNames(vector<string>& ideas) /*optimal method 3*/ {
    std::unordered_map<std::string_view, std::bitset<26>> suffixToFirstChars;
    for (std::string_view idea : ideas) {
      suffixToFirstChars[idea.substr(1)].set(idea[0] - 'a');
    }

    std::array<std::array<std::array<int, 2>, 26>, 26> cnt{};
    for (const auto& [suffix, firstCharSet] : suffixToFirstChars) {
      for (int i = 0; i < 26; ++i) {
        for (int j = i + 1; j < 26; ++j) {
          if (bool containOnlyOne =
                  firstCharSet.test(i) ^ firstCharSet.test(j)) {
            // for a suffix and 2 different chars, if such suffix
            // only contain one of the char, we record it in cnt
            // for any char pairs {c1, c2}
            // cnt[c1][c2][0]: how many suffix only having c2 as first char
            // cnt[c1][c2][1]: how many suffix only having c1 as first char
            ++cnt[i][j][firstCharSet.test(i)];
          }
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i < 26; ++i) {
      for (int j = i + 1; j < 26; ++j) {
        ans += 2ll * cnt[i][j][0] * cnt[i][j][1];
      }
    }
    return ans;
  }

  long long distinctNames_method_1(vector<string>& ideas) {
      std::unordered_map<char, std::set<std::string_view>> firstChar2Suffix;
      for (std::string_view idea : ideas) {
          firstChar2Suffix[idea[0]].insert(idea.substr(1));
      }
      std::vector<char> keys;
      const int groupSz = firstChar2Suffix.size();
      keys.reserve(groupSz);
      for (const auto& p : firstChar2Suffix) {
          keys.push_back(p.first);
      }
      long long res = 0;
      for (int i = 0; i < groupSz; ++i) {
          for (int j = i + 1; j < groupSz; ++j) {
              const auto& set1 = firstChar2Suffix[keys[i]];
              const auto& set2 = firstChar2Suffix[keys[j]];
              std::vector<std::string_view> unionSet;
              std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                  std::back_inserter(unionSet));
              res += (set1.size() - unionSet.size()) * (set2.size() -
  unionSet.size()) * 2;
          }
      }
      return res;
  }


  long long distinctNames_method_2(vector<string>& ideas) {
      std::unordered_map<std::string_view, std::bitset<26>> suffixToFirstChars;
      for (std::string_view idea : ideas) {
          suffixToFirstChars[idea.substr(1)].set(idea[0] - 'a');
      }
      std::vector<std::string_view> keys;
      const int groupSz = suffixToFirstChars.size();
      keys.reserve(groupSz);
      for (const auto& p : suffixToFirstChars) {
          keys.push_back(p.first);
      }
      long long res = 0;
      for (int i = 0; i < groupSz; ++i) {
          for (int j = i + 1; j < groupSz; ++j) {
              const auto& firstCharsSet1 = suffixToFirstChars[keys[i]];
              const auto& firstCharsSet2 = suffixToFirstChars[keys[j]];
              const auto unionSetSz = (firstCharsSet1 & firstCharsSet2).count();
              res += (firstCharsSet1.count() - unionSetSz) *
  (firstCharsSet2.count() - unionSetSz) * 2;
          }
      }
      return res;
  }
};
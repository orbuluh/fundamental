/*
The hard part is that you need to find the smallest result.
So the question is, when a character can be kept?

a b a --> if there is nothing bigger than 'a' afterwards, 'a' must be here.
^

c b c --> if something afterwards is smaller, and itself shows up in a latter
^         place, we are sure it's okay to remove

b a c a --> we won't bother checking this later a, even though it's smaller than
      ^     previous c, because a has been kept

So the idea is like ... say, input [c b a c a]

check ... result
c         [c]
b         [b] ... remove c because c < b and c exists in later place
a         [b a] ... b is smaller than a but there is no other b in later place
c         [b a c] ... just put c in
a         [b a c] ... ignore the last a as we've seen it

e.g. if char is seen, we won't do anything
otherwise, if char is smaller than previous inserted char, and previous inserted
char can be found in later place, we can insert it later. So we can pop it from
the stack and remove the flag of seeing such char
*/

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    std::unordered_map<char, int> pos;
    for (int i = 0; i < s.size(); ++i) {
      // you just need to know what's the last position of a char can be
      // to decide if it's possible to put a char in the later place
      pos[s[i]] = i;
    }
    std::deque<char> deq;
    std::bitset<26> seen;
    for (int i = 0; i < s.size(); ++i) {
      if (seen.test(s[i] - 'a')) {
        continue;
      }
      while (!deq.empty() && deq.back() > s[i] && pos[deq.back()] > i) {
        seen.reset(deq.back() - 'a');
        deq.pop_back();
      }
      seen.set(s[i] - 'a');
      deq.push_back(s[i]);
    }
    return std::string(deq.begin(), deq.end());
  }
};
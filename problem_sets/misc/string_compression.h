/*

Your original implementation is fine (bottom)... but it will need a flush at the
end ...

The cleaner way is to think about when to flush. It should be at the end of
exhausting one char. So we use 2 while loops, and for the inner one, we just try
to exhaust the same char and flush.

(Note that the std::copy is way faster than you do a for loop and write.)

*/

class Solution {
 public:
  int compress(vector<char>& chars) {
    int writeIdx = 0;
    int readIdx = 0;
    const int sz = chars.size();
    while (readIdx < sz) {
      char c = chars[readIdx++];
      int cnt = 1;
      while (readIdx < sz && chars[readIdx] == c) {
        readIdx++;
        cnt++;
      }
      chars[writeIdx++] = c;
      if (cnt > 1) {
        const auto numStr = std::to_string(cnt);
        std::copy(numStr.begin(), numStr.end(), chars.begin() + writeIdx);
        writeIdx += numStr.size();
      }
    }
    return writeIdx;
  }
};

/*
  int compress_ori(vector<char>& chars) {
    int cnt = 0;
    char preChar = ' ';
    int writeIdx = 0;
    auto writeCompress = [&]() {
      if (!cnt) {
        return;
      }
      chars[writeIdx++] = preChar;
      if (cnt != 1) {
        const auto numStr = std::to_string(cnt);
        for (char c : numStr) {
          chars[writeIdx++] = c;
        }
      }
    };
    for (char c : chars) {
      if (c != preChar) {
        writeCompress();
        preChar = c;
        cnt = 1;
      } else {
        cnt++;
      }
    }
    writeCompress();
    return writeIdx;
  }
*/
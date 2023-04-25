/*
From @votrubac, quite clean thought ....
so you will only added back value if it's smaller than the smallest value of the
continuous range

say you pop 1 to 4, continuous smallest value is 5 (e.g. 5 to inf exists)

if you addBack 6 -> no op
if you addBack 2, then 2, 5 to inf exists
if you then add Back 4, then 2, 4, 5 to inf exists

so just put the valid addBack value into an ordered set, then if the set still
have value, smallest must be the smallest value in the set, otherwise we should
update the continuous smallest value!
*/

class SmallestInfiniteSet {
  std::set<int> added;
  int continuousSmallest = 1;
 public:
  int popSmallest() {
    if (!added.empty()) {
      const auto v = *added.begin();
      added.erase(added.begin());
      return v;
    }
    return continuousSmallest++;
  }

  void addBack(int num) {
    if (continuousSmallest > num) {
      added.insert(num);
    }
  }
};

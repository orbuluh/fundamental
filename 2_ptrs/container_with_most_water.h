class Solution {
    /*
    Idea:
    - The initial is widest, hence could be a candidate. After shrinking the
      range, the width must be smaller. So we need a higher height to make a
      higher area.
    - So we basically can always greedily try to move the bound with lower
      height.
    - ** Tricky part: when height[l] == height[r], moving either one actually
    make no difference, as it's just guarantee to shrink the solution:
      --> say height[l+1] > height[l]

        when you moved to l+1, the result will be bounded by
        std::min(height[l+1], height[r]) = height[l].
        So the area is the same height plus smaller width, so it can't be a
        better choice.

      --> say height[l+1] < height[l],

        doing this just make result worse. can't be a better choice neither.
        same rationale for moving to r-1.

        So either way you are not throwing any potential candidate and the
        resulting area is guarantee to be smaller.
    - So when height[l] == height[r], just move whatever you like.
    */
  public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxArea = 0;
        while (l < r) {
            const auto minHeight = std::min(height[l], height[r]);
            maxArea = std::max(maxArea, minHeight * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
};
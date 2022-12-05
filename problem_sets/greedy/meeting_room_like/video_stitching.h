/*
The idea is that we can sort the input with begin time.
Then we keep track of the endTime we've covered so far.

Then in each iteration, there will be some valid options where
newClip.start <= coveredSoFar. For such newClip, it should be a valid option as
it ensure a wider coverage.

And among all the valid options in an iteration, we can just do it in a greedy
way such that we can expand the coveredSoFar as much as possible. Such option
will give us best chance to explore more remaining options in the next run. And
all the options that isn't been picked up can be discarded. As they are just not
providing better result compared to the one choose.

And side case based on problem ... you can early terminate if coveredEnd already
larger than the required time.
*/

class Solution {
 public:
  int videoStitching(vector<vector<int>>& clips, int time) {
    std::sort(clips.begin(), clips.end());
    int sz = clips.size();
    int coveredEnd = 0;
    int idx = 0;
    int took = 0;
    while (idx < sz && coveredEnd < time) {
      if (clips[idx][0] >
          coveredEnd) {  // the valid next option can't even concatenate
        return -1;
      }
      int prevEnd = coveredEnd;
      // go through all viable options and greedily find the max end as what
      // we will take in this iteration
      while (idx < sz && clips[idx][0] <= prevEnd) {
        coveredEnd = std::max(coveredEnd, clips[idx++][1]);
      }
      took++;
    }
    return coveredEnd >= time ? took : -1;
  }
};
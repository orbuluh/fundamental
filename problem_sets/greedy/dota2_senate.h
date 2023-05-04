/*
Need to understand what the question asks first ...

DRRDRDRDRDDRDRDR is R, why?

It's "round based" where
- each round "each senator can exercise one of the two rights".
- So it's not like going through "one senate"" is one round, rather,
  going through "all available senate" is one round)

say, _ means that senate is banned in the previous round, showing
the state of the beginning of the round:

Round 0: DRRDRDRDRDDRDRDR
Round 1: D_R_R_R_R_D_D_D_
Round 2: D___R_R_R_______
Round 3: ______R_R_______ (D ban the first R, then next R ban the D front)

Same ... DDRRR will be D because

Round 0: DDRRR
Round 1: _D__R
Round 2: _D___

Overall, you try to ban the senate on the right first as it has right
to ban your other available ally. And if there is no other opposite senate
on the right, you ban the one on the left, so in next round, it can't do
anything.

A very smart solution from discussion ...

as you eventually will try to remove opposite candidate on the left, you simply
add the pos + senate.size() back to queue to simulate it ... holy molly!
*/
class Solution {
 public:
  string predictPartyVictory(string& senate) {
    std::queue<int> dq, rq;
    const int sz = senate.size();
    for (int i = 0; i < sz; ++i) {
      senate[i] == 'R' ? rq.push(i) : dq.push(i);
    }
    while (!dq.empty() && !rq.empty()) {
      int dCandidate = dq.front();
      dq.pop();
      int rCandidate = rq.front();
      rq.pop();
      if (dCandidate < rCandidate) {
        dq.push(dCandidate + sz);
      } else {
        rq.push(rCandidate + sz);
      }
    }
    return rq.empty() ? "Dire"s : "Radiant"s;
  }

  string predictPartyVictory_your_slow_list_sol(string senate) {
    std::vector<std::list<int>> pos(2);
    auto party = [](char c) { return c == 'R'; };  // 0:D, 1: R
    const int sz = senate.size();
    for (int i = 0; i < sz; ++i) {
      pos[party(senate[i])].push_back(i);
    }

    auto& dPos = pos[0];
    auto& rPos = pos[1];

    while (!dPos.empty() && !rPos.empty()) {
      auto dIt = dPos.begin();
      auto rIt = rPos.begin();
      while (dIt != dPos.end() && rIt != rPos.end()) {
        if (*dIt < *rIt) {
          rIt = (rPos.erase(rIt));
          dIt++;
        } else {
          dIt = (dPos.erase(dIt));
          rIt++;
        }
      }
      // at this point, either dIt reach end or rIt reach end
      // for which ever hasn't, remove opposite senate on the
      // left
      auto rBegin = rPos.begin();
      while (dIt != dPos.end() && rBegin != rPos.end()) {
        rBegin = rPos.erase(rBegin);
        dIt++;
      }
      auto dBegin = dPos.begin();
      while (rIt != rPos.end() && dBegin != dPos.end()) {
        dBegin = dPos.erase(dBegin);
        rIt++;
      }
    }
    return !dPos.empty() ? "Dire"s : "Radiant"s;
  }
};

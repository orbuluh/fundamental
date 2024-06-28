/*
Check your python explain ... actually you are keeping monotonic decreasing
queue... as it forms unique spans
*/

class StockSpanner {
  struct StockData {
    int maxPx = 0;
    int count = 0;
  };
  std::stack<StockData> monoStk;

 public:
  StockSpanner() = default;

  int next(int price) {
    int smallerCnt = 0;
    while (!monoStk.empty() && monoStk.top().maxPx <= price) {
      smallerCnt += monoStk.top().count;
      monoStk.pop();
    }
    monoStk.emplace(StockData{price, smallerCnt + 1});
    return monoStk.top().count;
  }
};
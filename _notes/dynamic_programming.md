# Dynamic programming

- DP's goal is finding **overlapping sub-problems** that can be memorized.
  - To memorize the sub-problems, each of them is basically a "DP state" (a.k.a optimal substructure), where the state is represented by parameters.
- You need to think about what parameters could contribute a **"unique" state.**
- The state, or the result of a subproblem need to be unique:
  - It should not matter where you come from. If you reach state with specific set of parameters, the result is the same.
  - As it's unique, you can memorize it and return without recomputing in constant time - which is what DP is about, **optimizing a brute-force search such that the overlapped subproblem isn't recomputed through memorization.**
- The main difference between DP and divide and conquer is that DP tries out multiple choices of smaller subproblems, subproblems generally recur across different recursive calls.
  - In most divide-and-conquer algorithms, all the subproblems are distinct and there’s no point in caching their solutions.
- Another way to think about DP is: **Suppose someone handed us an optimal solution to us. What must it look like?**
- [Nice video](https://youtu.be/aPQY__2H3tE) with its five steps of solving DP:

```markdown
1. Visualize subproblems (should be a acyclic graph)
2. Find appropriate subproblems
3. Find relationships among subproblems
4. Generalize the relationships
5. Implementing by solving subproblems in order.
```

## The stock buy/sell questions

Modified from [fun4LeetCode's post](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems)

- 121. Best Time to Buy and Sell Stock
- 122. Best Time to Buy and Sell Stock II
- 123. Best Time to Buy and Sell Stock III
- 188. Best Time to Buy and Sell Stock IV
- 309. Best Time to Buy and Sell Stock with Cooldown
- 714. Best Time to Buy and Sell Stock with Transaction Fee
- ...

The general stock problem can be characterized by three factors:

- the day (`i`),
- the maximum number of transactions (`k`), and
- the number of stocks held at the end of the day.

The problem is solved using dynamic programming, with the following recurrence relations for maximum profits:

- `Sell[i][k]`: Maximum profit on the `i-th` day with at most `k` transactions and 0 stocks in hand.
- `Buy[i][k]`: Maximum profit on the `i-th` day with at most `k` transactions and 1 stock in hand.

### Recurrence Relations

- `Sell[i][k] = max(Sell[i-1][k], Buy[i-1][k] + prices[i])`: Either rest or sell on the `i-th` day.
- `Buy[i][k] = max(Buy[i-1][k], Sell[i-1][k-1] - prices[i])`: Either rest or buy on the `i-th` day.

The base cases are:

- `Sell[-1][k] = 0`, `Buy[-1][k] = -Infinity`: No stock or no transaction yields no profit.
- `Sell[i][0] = 0`, `Buy[i][0] = -Infinity`: No transactions allowed yields no profit.

### Applications to Specific Cases

#### Case I: k = 1

```python
def maxProfit(prices):
    Sell_0, Buy_1 = 0, float('-inf')
    for price in prices:
        Sell_0 = max(Sell_0, Buy_1 + price)
        Buy_1 = max(Buy_1, -price)
    return Sell_0
```

#### Case II: k = +Infinity

```python
def maxProfit(prices):
    Sell, Buy = 0, float('-inf')
    for price in prices:
        Sell_old = Sell
        Sell = max(Sell, Buy + price)
        Buy = max(Buy, Sell_old - price)
    return Sell
```

#### Case III: k = 2

```python
def maxProfit(prices):
    Sell_10, Buy_11 = 0, float('-inf')
    Sell_20, Buy_21 = 0, float('-inf')
    for price in prices:
        Sell_20 = max(Sell_20, Buy_21 + price)
        Buy_21 = max(Buy_21, Sell_10 - price)
        Sell_10 = max(Sell_10, Buy_11 + price)
        Buy_11 = max(Buy_11, -price)
    return Sell_20
```

#### Case IV: k is arbitrary

```python
def maxProfit(k, prices):
    if k >= len(prices) // 2:
        Sell, Buy = 0, float('-inf')
        for price in prices:
            Sell_old = Sell
            Sell = max(Sell, Buy + price)
            Buy = max(Buy, Sell_old - price)
        return Sell

    Sell = [0] * (k + 1)
    Buy = [float('-inf')] * (k + 1)
    for price in prices:
        for j in range(k, 0, -1):
            Sell[j] = max(Sell[j], Buy[j] + price)
            Buy[j] = max(Buy[j], Sell[j-1] - price)
    return Sell[k]
```

#### Case V: k = +Infinity but with cooldown

```python
def maxProfit(prices):
    Sell_pre, Sell, Buy = 0, 0, float('-inf')
    for price in prices:
        Sell_old = Sell
        Sell = max(Sell, Buy + price)
        Buy = max(Buy, Sell_pre - price)
        Sell_pre = Sell_old
    return Sell
```

#### Case VI: k = +Infinity but with transaction fee

**Solution I - Pay the fee when buying the stock:**

```python
def maxProfit(prices, fee):
    Sell, Buy = 0, float('-inf')
    for price in prices:
        Sell_old = Sell
        Sell = max(Sell, Buy + price)
        Buy = max(Buy, Sell_old - price - fee)
    return Sell
```

**Solution II - Pay the fee when selling the stock:**

```python
def maxProfit(prices, fee):
    Sell, Buy = 0, float('-inf')
    for price in prices:
        Sell_old = Sell
        Sell = max(Sell, Buy + price - fee)
        Buy = max(Buy, Sell_old - price)
    return Sell
```

### Conclusion

The stock problem is solved using dynamic programming with two 2D matrices, `Sell` and `Buy`, representing the maximum profit on each day with different transactions and stock conditions. Specific cases adjust the recurrence relations to account for constraints like transaction limits, cooldown periods, and transaction fees, leading to optimized solutions in `O(n)` or `O(kn)` time complexity.

TODO: [Check the nice collections from discussion thread](https://leetcode.com/discuss/general-discussion/665604/Important-and-Useful-links-from-all-over-the-LeetCode)

- DP for Beginners [Problems | Patterns | Sample Solutions] by @wh0ami
- DP Patterns by @aatalyk
- Knapsack problems by @old_monk
- How to solve DP - String? Template and 4 Steps to be followed by @igooglethings
- Dynamic Programming Questions thread by @karansingh1559
- DP Classification helpful notes by @adityakrverma
- How to approach DP problems by @heroes3001
- Iterative DP for subset sum problems by @yuxiangmusic
- DP problems summary (problem categorization) by @richenyunqi
- Categorization of Leetcode DP problems by @chuka231
- Must do Dynamic Programming Category wise by @mahesh_nagarwal
- Dynamic programming is simple by @omgitspavel
- Dynamic Programming on subsets with examples by @DBabichev
- DP is easy (Thinking process) by @teampark

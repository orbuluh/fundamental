# Segment tree
- Notes from [YT video](https://youtu.be/-dUiRtJ8ot0)

## Use case - A query about an range
### Example: query maximum within range
- Say you have an array of integers. User will query with a range [l, r]
- You need to return the maximum between [l, r]
- Naively, if you iterate l to r for each query to find the maximum, every query is a O(n) search.
- Segment tree reduce this query to O(logn)

### Example 2: Range query

## Basic tree representation
- say root node idx is `i`
  - left node idx is `2 * i + 1`
  - right node idx is `2 * i + 2`
- root node represents range within [L, R]
  - M = L + (R - L) / 2
  - left node represents range within [L, M]
  - right node represents range within [M+1, R]

![](../srcs/segment_tree_basic_structure.png)

## How to build the tree
- Build is based on the query - For example, query the max of a range:

![](../srcs/segment_tree_build.png)

## How to query
- Return value is based on the query.
- But overall through traversing and check the relationship between query range and node range.
  - **Case 1**: query range **completely cover** node range: `return node value`
  - **Case 2**: query range **out side of** node range: `return INT_MIN`
  - **Case 3**: query range **(partial or full) overlap with** node range: `return min(left, right)`

![](../srcs/segment_tree_query.png)
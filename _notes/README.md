# :book: Notes for algo/DS deep-dive


**[Backtracking](backtracking.md)**
  

  
  

**[Binary search](binary_search.md)**
  

  

  - Keys to implement by yourself
  

**[Bitwise](bitwise.md)**
  

  

  - Size of integers in C++
  

  

  - Two's complement
  

  

  - Reset the last/rightmost set bit: `x & (x - 1)`
  

  

  - Detect is power of 2: `(x & (x - 1)) == 0`
  

  

  - Get the last/rightmost set bit: `x - (x & (x - 1))`
  

  

  - Isolate the least significant bit: `x & (-x)`
  

  

  - Detect if two integers have opposite signs: `f = (X ^ Y) < 0`
  

  

  - Common mask
  

  

  - Bitwise rounding to pow of 2 (useful for memory alignment): `size = (size + alignment-1) & ~(alignment-1)`
  

**[Cycle detection (Floyd's tortoise and hare with 2 pointers)](cycle_detection.md)**
  

  
  

**[Data structures](data_structures.md)**
  

  

  - (Tree) map are sorted by keys `map`, `set`, `multimap`, `multiset`
  

  

  - BST
  

  

  - Binary index tree (BIT)
  

  

  - Segment tree
  

  

  - Monotonic Queue/Stack
  

**[Data structures: All kinds of Heap](ds_all_kinds_of_heap.md)**
  

  

  - (Binary) heap
  

  

  - Binomial heap
  

  

  - Fibonacci heap
  

**[Data structures: Union–find data structure](union_find.md)**
  

  
  

**[Dynamic programming](dynamic_programming.md)**
  

  
  

**[Graph: 1. Topological sort](graph_topological_sort.md)**
  

  
  

**[Graph: 2. Single source shortest path / SSSP](graph_sssp.md)**
  

  

  - Generic structure of shortest path (SP)
  

  

  - Shortest path in DAGs
  

  

  - Dijkstra Algorithm
  

  

  - Bellman Ford Algorithm
  

**[Graph: 3. All pairs shortest path / APSP](graph_apsp.md)**
  

  

  - Floyd Warshall Algorithm
  

**[Graph: 4. Bipartite](graph_bipartite.md)**
  

  
  

**[Graph: 5. Max flow / min cut / Ford-Fulker method](graph_max_flow.md)**
  

  
  

**[Graph: 6. Tarjan's Strongly Connected Component](graph_tarjan_scc.md)**
  

  
  

**[Math: Modular multiplication property](modular.md)**
  

  
  

**[Math: Reservoir sampling](reservoir_sampling.md)**
  

  
  

**[Range query: Binary indexed tree](binary_index_tree.md)**
  

  
  

**[Range query: Segment tree](segment_tree.md)**
  

  
  

**[Substring matching: KMP (Knuth–Morris–Pratt) algorithm for pattern matching](kmp.md)**
  

  
  

**[Substring matching: Rolling hash](rolling_hash.md)**
  

  
  

**[Tree traversal](tree_traversal.md)**
  

  

  - Pre-order iterative
  

  

  - Morris traversal
  

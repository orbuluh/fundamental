## Heap
### Quick facts
- The tree maintain either parent >= child or parent <= child. **Not left <= parent <= right.**
- **Heapify is O(n)**
- insert is O(log(n))
- HeapSort is O(nlog(n))
#### more about [:link: `heapify`](https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity)
- [:link: siftUp/siftDown animation](https://youtu.be/5iBUTMWGtIQ)
- siftDown and siftUp are themselves O(log(n))
- The number of operations required for siftDown and siftUp is proportional to the distance the node may have to move.
- If we are going to choose either siftdown or siftup, we choose to siftdown (e.g. sift top node down), as tree has fewer node at the top, and more node at the bottom.
- [My notes :orange_book:](../srcs/heapify.jpeg) -> from [src](http://www.cs.umd.edu/~meesh/351/mount/lectures/lect14-heapsort-analysis-part.pdf)


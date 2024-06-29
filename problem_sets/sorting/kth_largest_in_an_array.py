class Solution:
    def findKthLargest1(self, nums: List[int], k: int) -> int:
        # convert everything to max heap
        # then pop to the k-th times
        nums = [-v for v in nums]
        heapify(nums)
        for i in range(k - 1):
            heappop(nums)
        return -1 * heappop(nums)

    def findKthLargest(self, nums: List[int], k: int) -> int:
        # keep a min heap of only k numbers
        heap = nums[:k]
        heapify(heap)

        # we keep popping smallest number out of k numbers
        # as long as the new value is larger than the smallest
        # then at the end, because the minQ is with size k
        # the smallest number must be the k-th largest
        for num in nums[k:]:
            if num > heap[0]:
                heappop(heap)
                heappush(heap, num)

        return heap[0]

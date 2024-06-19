"""
You were doing trie ... but it turns out binary search is all you need

not that for the question, when there is no match at all, it won't counted into
that "lexicographically minimums products"
"""


class Solution:
    def suggestedProducts(
        self, products: List[str], searchWord: str
    ) -> List[List[str]]:
        products.sort()
        prefix = ""
        # n = len(products)
        res = []
        for c in searchWord:
            prefix += c
            i = bisect.bisect_left(products, prefix)
            # res += [[products[j] for j in range(i, min(i + 3, n)) if products[j].startswith(prefix)]]
            # NOTE: python slicing will return empty automatically!!!! but products[j] will
            # throw if j > n!!!
            res += [[w for w in products[i : i + 3] if w.startswith(prefix)]]
        return res

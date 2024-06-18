class Node:
    def __init__(self, k: int, v: int):
        self.key = k
        self.val = v
        self.pre = None
        self.nxt = None


class MyHashMap:

    def __init__(self):
        self.bucket = [Node(None, None)] * 1337

    def put(self, key: int, value: int) -> None:
        hash_val = key % len(self.bucket)
        pre = self.bucket[hash_val]
        node = pre.nxt
        while node:
            if node.key == key:
                node.val = value
                return
            pre = node
            node = node.nxt
        pre.nxt = Node(key, value)
        pre.nxt.pre = pre

    def get(self, key: int) -> int:
        hash_val = key % len(self.bucket)
        node = self.bucket[hash_val].nxt
        while node:
            if node.key == key:
                return node.val
            node = node.nxt
        return -1

    def remove(self, key: int) -> None:
        hash_val = key % len(self.bucket)
        pre = self.bucket[hash_val]
        node = pre.nxt
        while node:
            if node.key == key:
                pre.nxt = node.nxt
                if node.nxt:
                    node.nxt.pre = pre
                return
            pre = node
            node = node.nxt


# actually much faster ... and easier to implement. But anyway
class MyHashMapWithList:
    def __init__(self):
        self.bucket = [[] for _ in range(1337)]

    def put(self, key: int, value: int) -> None:
        hash_val = key % len(self.bucket)
        for i, [k, v] in enumerate(self.bucket[hash_val]):
            if k == key:
                self.bucket[hash_val][i][1] = value
                return
        self.bucket[hash_val] += [[key, value]]

    def get(self, key: int) -> int:
        hash_val = key % len(self.bucket)
        for [k, v] in self.bucket[hash_val]:
            if k == key:
                return v
        return -1

    def remove(self, key: int) -> None:
        hash_val = key % len(self.bucket)
        for i, [k, v] in enumerate(self.bucket[hash_val]):
            if k == key:
                del self.bucket[hash_val][i]

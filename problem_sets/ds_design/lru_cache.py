class LRUCache:

    def __init__(self, capacity: int):
        # OrderedDict LIFO by default
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        # pop will return value and remove the key
        # and then by calling setdefault we basically
        # reinsert it again (to the LIFO). setdefault
        # is the method that would have return value
        return (
            -1
            if key not in self.cache
            else self.cache.setdefault(key, self.cache.pop(key))
        )

    def put(self, key: int, value: int) -> None:
        # for LIFO, move_to_end basically means move
        # to (left) end (a.k.a. beginning). And when key
        # is not there, raise KeyError. Then we can insert
        # it when this happens
        try:
            self.cache.move_to_end(key)
            self.cache[key] = value
        except KeyError:
            self.cache[key] = value
            if len(self.cache) > self.capacity:
                self.cache.popitem(last=False)

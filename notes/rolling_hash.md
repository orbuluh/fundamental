# Substring matching: Rolling hash

- [SRC: Tushar Roy - Coding Made Simple channel](https://youtu.be/H4VrKHVG5qI)
- [wiki](https://en.wikipedia.org/wiki/Rolling_hash)
- [Adam Horvath's blog](https://blog.teamleadnet.com/2012/10/rabin-karp-rolling-hash-dynamic-sized.html)

**Quick fact**

- A rolling hash (also known as recursive hashing or rolling checksum) is a hash function where the input is hashed in a window that moves through the input.

**Polynomial rolling hash**

- Polynomial because the function use polynomial equations to achieve the rolling hash
- How?

```markdown
- Say nums = [a0, a1, a2, a3, ...] and window size k is 3
- b is some selected prime number
- W0 = [a0, a1, a2]
- W1 = [a1, a2, a3]
- H(W0) = a0 * b^0 + a1 * b^1 + a2 * b^2
- H(W1) = (H(W0) - a0 * b^0) / b) + a3 * b^2
        = ((a1 * b^1 + a2 * b^2) / b) + a3 * b^2
        = a1 * b^0 + a2 * b^1 + a3 * b^2
```

- So generalize you can see that:

```markdown
- Say nums = [a0, a1, a2, a3, ...] and window size k
- b is some selected prime number
- W_0 = [a0, a1, ..., a_{k-1}]
- W_1 = [a1, a2, ..., a_{k}]
...
H(W_n) = (H(W_{n-1}) - a_{n-1}) / b + a_{k + n - 1} * b^(k - 1)
```

**Rabin Karp rolling hash**

- Rolling hash is a way to quickly spot if a k-size pattern is in the original string - e.g. you build the k size window in the original string into a hash map with rolling hash as hash function.
- Then you can just check the input pattern's hash value to see if it exists in the hashmap

**Question set**

- [:point_right: here](../substr_matching/README.md)
- implementation example check [:point_right: here](../substr_matching/max_len_of_repeated_subarray_rollinghash.h)

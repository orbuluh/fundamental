# Cycle detection (Floyd's tortoise and hare with 2 pointers)

The idea is that we utilize 2 pointers `slow` (tortoise) and `fast` (hare), where we move `slow` 1 step and move `fast` 2 steps in each iteration.

**The observations**:

> 1. If there is no cycle in the list, the fast pointer will eventually reach
   the end and we can return false in this case.

> 2. If there is a cycle, once slow entering the cycle, it will be like both
   slow and fast are running in the cycle. And because fast is just one step
   quicker - eventually it must be able to meet with slow.

So whether or not there is a cycle simply depends on observation 1

**What if we want to find where the cycle starts?**

The algorithm is:

```markdown
- once `slow` and `fast` meet, moves `slow` back to head, `fast` stay at meeting point.
- then move one step for both `slow` and `fast` in each iteration.
- when they meet again, they are at the beginning of cycle.
```


:thinking: Why?

> :bulb: The math basics: `C ≡ 0 (mod C)`.

Let's assume that there is a cycle in the linked list, say

- There are `T` nodes before cycle, and `C` nodes in the cycle.
- Let's mark the node's indices as
  - `[-T, ..., -1]` for the `T` nodes before the cycle and
  - `[0, ..., C - 1]` for the `C` nodes in the cycle.

```txt

    T      ____k       H = head = node index -T
 H--------X     \   <- X = beginning of cycle = node index 0
          ^      |     k = hitting point = node index k
          \_____/      C = number of nodes in the cycle
```

---

**Explanation :one:**

Say when meet at `k`

- `x`: number of complete cycle `fast` pointer run when meeting
- `y`: number of complete cycle `slow` pointer run when meeting

Then

- `slow` took `T + y * C + k` steps ... (1)
- `fast` took `T + x * C + k` steps ... (2)
- And because `f = 2s`, `f = 2 (T + yC + k)` ...(3)
- as (3) == (2), so `2T + 2yC + 2k = T + xC + k`, e.g. `T + k = (x - 2y) * C`
- This implies `T + k` is a multiple of C (cycle length). Thus we can write, `T + k = zC`, `z = (x - 2y)` being some integer. Or we say, `T = zC - k`.

- Say now, we move `slow` pointer from head, and `fast` pointer stay at meeting point `k`, and making both of them only travel 1 at a time
- Then when both `slow` and `fast` move additional `T = zC - k` steps
  - `slow` should be at `0 + T = T`, e.g. begin of cycle.
  - And `fast` should be at `k + T = k + zC - k = zC ≡ 0 (mod C)`.
- E.g. both of them travel to node X (index 0) and they meet again. And the meeting point is node index 0, the start of cycle!!

---

**Explanation :two:**

- As `fast` move twice faster, when `slow` moves `t`, `fast` moves `2t`
- So after `T` iterations, `slow` is at node 0. We assume at the same time, `fast` is at node `r`.
- :bulb: The key observation is, since after `T` iterations, `fast` must have traveled `2T`, while the first `T` are used in the non-cycle portion. We know that `fast` must travel within the cycle for `T` steps at this moment. **This implies that `r ≡ T (mod C)`**

- Say now, we move additional `C - r` iterations, what would happen?
  - `slow` is at node `0 + C - r = C - r`, and
  - `fast` at node `r + 2(C - r) = 2C - r`
  - And because `2C - r ≡ C - r (mod C)`, we know that at this moment, `slow` and `fast` meets.

- So right after they meet (at node `C - r`), if we move `slow` back to front, and change `fast` to move 1 step as well, what would happen after additional `T` steps?
  - `slow` will be at node 0 again.
  - `fast` will be at `C - r + T ≡ C - r + r ≡ 0 (mod C)` (because (Eq.1))
  - E.g. they are both at node 0 now!!!
  - E.g. once they meet again, we find the starting point of cycle!!!
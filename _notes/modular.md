# Math: Modular multiplication property

- `(A * B) % C = ((A % C) * (B % C)) % C`

```text
Proof:

A = C * Qa + Ra where 0 ≤ Ra < C and Qa is some integer. A % C = Ra
B = C * Qb + Rb where 0 ≤ Rb < C and Qb is some integer. B % C = Rb

LHS = (A * B) % C
    = ((C * Qa + Ra) * (C * Qb + Rb)) % C
    = (C * C * Qa * Qb + C * Qa * Rb + C * Qb * Ra + Ra * Rb ) % C
    = (Ra * Rb) % C

RHS = ((A % C) * (B % C))% C
    = (Ra * Rb) % C

Hence LHS == RHS
```
# Reservoir sampling

- [Bizillion Proofs](https://youtu.be/dWfo9XGrqKU)

## What

$X = [x_1, ...., x_n]$ be a stream of unknown number of n distinct items. We want to
- obtain a sample $T_i$ of k items, where $k < n$.

And at any point of timing $i$ where $i < n$
- The probability of picking a random value $x_j$ out of $T_i$ are the same after $i$ steps:
  - $Pr(x_i \in T_i) = Pr(x_j \in T_i)$ where $\forall 1 \leq j \leq i \leq n$
  - Note: $Pr(x_j \in T_i)$ means the probability of an item $x_j$ is in the sample set $T_i$
- (e.g. for all valid i, j that meets the condition, following holds: prob of picking the new item at $i$, $x_i$, is just the same as picking any other $x_j$ that is in the current k size sampling set $T_i$)


## Algorithm

- if $i \leq k: T_i = T_{i - 1} \cup { x_i }$
- else:
  - With probability $\frac{k}{i}$, replace one equal probability chosen element $x_y$ from $T_{i - 1}$, and replace with $x_i$.
  - (e.g. with probability $1 - \frac{k}{i}$, discard the new item $x_i$)


## Proof (by induction)

when $i \leq k$, we simply include $x_i$, so the probability of $x_i$ is in the set is just 1. This holds for all the elements that is in the sample set already.

- For example, when $i = k$, $Pr(x_i \in T_i) = \frac{k}{i} = 1$,

Induction, say we go through $j$ to $j + 1$, where $j > k$
- Assume first j elements have been chosen with prob = $\frac{k}{j}$
- The algorithm chooses the $j + 1$-th element with prob = $\frac{k}{j + 1}$
- Should we choose this element $x_j$ - then each elements in $T_j$ has probability of $\frac{1}{k}$ being replaced.
- The prob that an element is replaced with the $j + 1$-th element is therefore $\frac{1}{k}\frac{k}{j+ 1} = \frac{1}{j + 1}$
- Thus, the prob that an element is not replaced, (hence exists in $T_j$) is $1 - \frac{1}{j + 1} = \frac{j}{j + 1}$
- So, the sample set $T_j$ contains any given element either because
  - it was chosen into the sample set $T_{j - 1}$ and is not replaced: $Pr(x_y \in T_{j + 1}) = \frac{k}{j}\frac{j}{j+ 1} = \frac{k}{j + 1}$
  - or it was chosen in the latest round with prob $\frac{k}{j + 1}$
  - e.g. there are still equal prob for an item to be in the sample set!
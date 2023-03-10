# Math: Reservoir sampling

- [Bizillion Proofs](https://youtu.be/dWfo9XGrqKU)
- Dialogue with ChatGPT ... amazing.

:flags: **What**

Reservoir sampling is a technique used to **randomly select a sample of $k$ items (e.g. the reservoir) from a larger data set of $n$ items, where $n$ is either very large or not completely known in advance (For example, say it's a stream of unknown number).**

- The technique is useful in situations where it is not practical or possible to process the entire data set at once.


Formally, let $X = [x_1, ...., x_n]$ be a stream of unknown number of $n$ distinct items.

We want to obtain a sample $T_i$ at a time point $i$ where $k <= i < n$

- The sample $T_i$ has a fixed size with $k$ items, and the $k$ items are selected out of the $i$ items we've seen so far (imagine it's coming from the stream).
- Noted that at timing $i$, we've seen $i$ items, but we only keeps $k$ items in our sample $T_i$
- We want to make sure, for all the $i$ items we've seen so far, they always have equal probability to be in our sample $T_i$
  - Formally, let $Pr(x_j \in T_i)$ = the probability of an item $x_j$ is in the sample set $T_i$
  - We need to make sure: $Pr(x_i \in T_i) = Pr(x_j \in T_i)$ where $\forall 1 \leq j \leq i \leq n$

---

:flags: **The algorithm**

- At time point $i$ where $i < n$ ...
- if $i \leq k$:
  - $T_i = T_{i - 1} \cup { x_i }$
- else:
  - With probability $\frac{k}{i}$, replace one  element $x_y$ out of previous sample $T_{i - 1}$ with equal probability with the new element $x_i$.
  - Or say, with probability $1 - \frac{k}{i}$, we simply discard the new item $x_i$ and let $T_i$ equal to $T_{i - 1}$

Practically, when $i >= k$, we do the following:

- Generate a random number $r$ between 1 and $i$ (inclusive).
- if $r <= k$, replace a randomly chosen item $x_y$ (with probability $\frac{1}{k}$ in the reservoir/sample $T_{i - 1}$ with item $x_i$ to form the new reservoir/sample $T_i$

---

:flags: **Proof (by induction)**

when $i \leq k$, we simply include $x_i$, so the probability of $x_i$ is in the set is just 1.

- This holds for all the elements that is in the sample set already.
- For example, when $i = k$, $Pr(x_i \in T_i) = \frac{k}{i} = 1$,
- Note that $Pr(x_j \in T_i)$ = the probability of an item $x_j$ is in the sample set $T_i$, NOT the probability of an item $x_j$ is selected from $T_i$

Induction:

- Say we go through timing $j$ to $j + 1$, where $j > k$ and assume first $j$ elements has equal probability $\frac{k}{j}$ to be in the reservoir $T_{j}$
- With prob = $\frac{k}{j+1}$, the algorithm replace the element $x_{j+1}$ with one of the existing element in current sample $T_j$ to form new sample $T_{j+1}$.
- Any element in $T_j$ has a probability of $\frac{1}{k}\frac{k}{j+1} = \frac{1}{j + 1}$ being replaced with $x_{j+1}$ and therefor no longer in $T_{j+1}$
- Thus, the probability that an element is still in $T_{j+1}$ is $1 - \frac{1}{j+1} = \frac{j}{j+1}$

- So, the sample $T_{j+1}$ contains any given element $x_y$ either because
  - the element was chosen into the sample set $T_j$ and is not replaced at timing $j+1$ with $Pr(x_y \in T_{j + 1}) = \frac{k}{j}\frac{j}{j+1} = \frac{k}{j+1}$
  - or the element was chosen in the $j+1$ round with prob $\frac{k}{j+1}$

- E.g. this prove the algorithm holds the relation that for any element that we've seen at $j+1$, they all have equal probability $\frac{k}{j+1}$ to be in our sample $T_{j+1}$

---

:flags: **Real world application**

Reservoir sampling is a useful technique in a variety of real-world applications where random sampling of large data sets is required. Some examples of where reservoir sampling might be used include:

- Web analytics: Reservoir sampling can be used to randomly select a subset of website visitors for a survey or to track user behavior, without having to process data for all visitors.
- Social network analysis: Reservoir sampling can be used to randomly sample social network users for a study, without having to process data for all users.
- Machine learning: Reservoir sampling can be used to randomly sample data points from a large training dataset for model training, without having to process all the data at once.
- Data analysis: Reservoir sampling can be used to randomly sample data for statistical analysis, without having to process all the data at once.
- Sensor networks: Reservoir sampling can be used to randomly sample sensor data for analysis, without having to store or process all the data.

---

:flags: :bulb: It can also be used in "random choose one value out of a linked list"!!

- It's basically the case of 1-size reservoir ($k = 1$) while using O(n) search in each call to make sure all elements got a (1/n) being selected, check: [382. Linked list random node](../problem_sets/math/README.md#💡-382-linked-list-random-node--👨‍💻)
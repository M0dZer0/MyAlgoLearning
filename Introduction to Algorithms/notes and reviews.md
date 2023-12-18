# Introduction to Algorithms

## chapter 1

### exercises

> 1.1-2 Other than speed, what other measures of efficiency might one use in a real-world setting?

1. **Memory Usage (Space Complexity):** Efficient algorithms should use an optimal amount of memory. Minimizing the space complexity can be crucial, especially in environments with limited memory resources.
2. **Power Consumption:** In scenarios where energy efficiency is crucial (e.g., mobile devices, IoT devices), algorithms that consume less power are desirable. Low-power algorithms can contribute to longer battery life and reduced environmental impact.
3. **Scalability:** An algorithm's performance should scale gracefully as the input size or workload increases. Scalability is essential in applications dealing with large datasets or high traffic.
4. **Parallelization and Concurrency, Robustness and Fault Tolerance, Adaptability** and so on...

## chapter 2

### exercises

> 2.1-2 Rewrite the $\text{INSERTION-SORT}$ procedure to sort into nonincreasing instead of nondecreasing order.

```cpp
INSERTION-SORT(A)
    for j = 2 to A.length
        key = A[j]
        i = j - 1
        while i > 0 and A[i] < key
            A[i + 1] = A[i]
            i = i - 1
        A[i + 1] = key
```

> 2.1-3 Consider the **_searching problem_**:

> **Input**: A sequence of $n$ numbers $A = \langle a_1, a_2, \ldots, a_n \rangle$ and a value $v$.
>
> **Output:** An index $i$ such that $v = A[i]$ or the special value $\text{NIL}$ if $v$ does not appear in $A$.
>
> Write pseudocode for **_linear search_**, which scans through the sequence, looking for $v$. Using a loop invariant, prove that your algorithm is correct. Make sure that your loop invariant fulfills the three necessary properties.

```cpp
LINEAR-SEARCH(A, v)
    for i = 1 to A.length
       if A[i] == v
            return i
    return NIL
```

> Consider sorting $n$ numbers stored in array $A$ by first finding the smallest element of $A$ and exchanging it with the element in $A[1]$. Then find the second smallest element of $A$, and exchange it with $A[2]$. Continue in this manner for the first $n - 1$ elements of $A$. Write pseudocode for this algorithm, which is known as **_selection sort_**. What loop invariant does this algorithm maintain? Why does it need to run for only the first $n - 1$ elements, rather than for all $n$ elements? Give the best-case and worst-case running times of selection sort in $\Theta$-notation.

- Pseudocode:

    ```cpp
    n = A.length
    for i = 1 to n - 1
        minIndex = i
        for j = i + 1 to n
            if A[j] < A[minIndex]
                minIndex = j
        swap(A[i], A[minIndex])
    ```

- Loop invariant:

    At the start of the loop in line 1, the subarray $A[1..i - 1]$ consists of the smallest $i - 1$ elements in array $A$ with sorted order.

- Why does it need to run for only the first $n - 1$ elements, rather than for all $n$ elements?

    After $n - 1$ iterations, the subarray $A[1..n - 1]$ consists of the smallest $i - 1$ elements in array $A$ with sorted order. Therefore, $A[n]$ is already the largest element.

- Running time: $\Theta(n^2)$.

> 2.2-4 How can we modify almost any algorithm to have a good best-case running time?


You can modify any algorithm to have a best case time complexity by adding a special case. If the input matches this special case, return the pre-computed answer.

> Rewrite the $\text{MERGE}$ procedure so that it does not use sentinels, instead stopping once either array $L$ or $R$ has had all its elements copied back to $A$ and then copying the remainder of the other array back into $A$.

```cpp
MERGE(A, p, q, r)
    n1 = q - p + 1
    n2 = r - q
    let L[1..n1] and R[1..n2] be new arrays
    for i = 1 to n1
        L[i] = A[p + i - 1]
    for j = 1 to n2
        R[j] = A[q + j]
    i = 1
    j = 1
    for k = p to r
        if i > n1
            A[k] = R[j]
            j = j + 1
        else if j > n2
            A[k] = L[i]
            i = i + 1
        else if L[i] ≤ R[j]
            A[k] = L[i]
            i = i + 1
        else
            A[k] = R[j]
            j = j + 1
```

> 2.3-5 Referring back to the searching problem (see Exercise 2.1-3), observe that if the sequence $A$ is sorted, we can check the midpoint of the sequence against $v$ and eliminate half of the sequence from further consideration. The **_binary search_** algorithm repeats this procedure, halving the size of the remaining portion of the sequence each time. Write pseudocode, either iterative or recursive, for binary search. Argue that the worst-case running time of binary search is $\Theta(\lg n)$.

- Iterative:

  ```cpp
  ITERATIVE-BINARY-SEARCH(A, v, low, high)
      while low ≤ high
          mid = floor((low + high) / 2)
          if v == A[mid]
              return mid
          else if v > A[mid]
              low = mid + 1
          else high = mid - 1
      return NIL
  ```

- Recursive:

  ```cpp
  RECURSIVE-BINARY-SEARCH(A, v, low, high)
      if low > high
          return NIL
      mid = floor((low + high) / 2)
      if v == A[mid]
          return mid
      else if v > A[mid]
          return RECURSIVE-BINARY-SEARCH(A, v, mid + 1, high)
      else return RECURSIVE-BINARY-SEARCH(A, v, low, mid - 1)
  ```

  Each time we do the comparison of $v$ with the middle element, the search range continues with range halved.

  The recurrence

  $$
  T(n) = \begin{cases}
      \Theta(1)            & \text{if } n = 1, \\\\
      T(n / 2) + \Theta(1) & \text{if } n > 1.
  \end{cases}
  $$

  The solution of the recurrence is $T(n) = \Theta(\lg n)$.
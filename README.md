# DSA
Practice

1. 2 sum problem - 001_2_sum_problem.cpp
   Following three approaches in the solution.
   i.   brute force           -    TC: O(n^2)
   ii.  hashmap               -    TC: O(n log n) && SC: O(n)
   iii. two-pointers approach -    TC: O(n log n)

2. Sort 0s, 1s and 2s - 002_sort_0s_1s_2.cpp
   i.   brute force           -    TC: O(n) [count number of 0s, 1s, 2s in one iteration and fill countwise in next iteration]
   iii. dutch national flag   -    TC: O(n)

3. Find majority element, count > n/2
   i.   brute force           -    TC: O(n^2) [count occurance of each element in each iteration and check if > n/2]
   ii.  hashmap               -    TC: O(n)
   iii. Moore's voting        -    TC: O(n) [4 partition, assume 0s sorted on leftmost, then 1s sorted, then unsorted, then rightmost 2s sorted]

# Segment Trees

## 1) st1.cpp 

**Name**: Range Sum

**Functions**:

 - Summation from L to R
 - Element Update : a[x] = new_value
---

## 2) st2.cpp 

**Name**: Range Max + Frequency

**Functions**:

 - < Max from L to R, Frequency of Max from L to R >
 - Element Update : a[x] = new_value
---

## 3) st3.cpp 

**Name**: GCD & LCM

**Functions**:

 - < GCD from L to R, LCM from L to R >
 - Element Update : a[x] = new_value
---

## 4) st4.cpp 

**Name**: Frequency & postion of fixed target

**Functions**:

 - < frequency of fixed target from L to R, Position of Kth fixed target from L to R >
 - Element Update : a[x] = new_value
---

## 5) st5.cpp 

**Name**: LowerBound & UpperBound (Unsorted)

**Functions**:

 - Max from L to R
 - Element Update : a[x] = new_value
 - Position of LowerBound of Passed Value from L to R (Works on unsorted too)
 - Position of UpperBound of Passed Value from L to R (Works on unsorted too)
---

## 6) st6.cpp 

**Name**: Max Range, Prefix, Suffix (Non-empty)

**Functions**:

 - Element Update : a[x] = new_value
Struct Node:
 - Sum from L to R
 - Maximum Prefix Sum from L to R
 - Maximum Suffix Sum from L to R
 - Maximum Contiguous Range Sum from L to R
---

## 7) st7.cpp 

**Name**: Merge Sort Tree 1

**Functions**:

 - Vector Nodes, No point updates
 - Number of elements smaller than passed query value from L to R
---

## 8) st8.cpp 

**Name**: Merge Sort Tree 2 (Pseudo)

**Functions**:

 - Vector Nodes, No point updates
 - Built on indices after sorting
 - Index of the K-th smallest element from L to R, K - query value
---

## 9) st9.cpp 

**Name**: Merge Sort Tree 3

**Functions**:

 - PBDS (Ordered_Set) Nodes
 - Element Update : a[x] = new_value
 - Number of elements smaller than passed query value from L to R
---

## 10) st91.cpp 

**Name**: Lazy Propagation:- add on segment with sum of range

**Functions**:

 - Summation from L to R
 - Range update : a[L...R] = new_value
---

## 11) st92.cpp 

**Name**: 2D Segment Tree

**Functions**:

 - Summation from (X1, Y1) to (X2, Y2)
 - Element update : a[X,Y] = new_value
---

## 12) st93.cpp 

**Name**: Persistent Segment Tree

**Functions**:

 - Preserves all roots of updated Segment Tree
 - Update value of any version's element :- a[pos] += new_val
 - Sum of elements from L to R from any version
---

## 12) st93.cpp 

**Name**: Persistent Segment Tree

**Functions**:

 - Built on Index-Compressed array
 - Preserved N versions from L to R
 - Query:- Kth smallest number from L to R in O(log(n))
---
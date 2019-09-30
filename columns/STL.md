# STL
## next_permuation

## lower\_bound / upper_bound
lower_bound(a, a+n, k)：从已排好序的序列的序列a中利用二分搜索找出指向满足a[i]>=k的a[i]的最小的指针

upper_bound(a, a+n, k)：从已排好序的序列的序列a中利用二分搜索找出指向满足a[i]>k的a[i]的最小的指针。

例如求长度为n的有序数组a中的k的个数：

```
upper_bound(a, a+n,k) - lower_bound(a, a+n, k)
```
## sort

## priority_queue


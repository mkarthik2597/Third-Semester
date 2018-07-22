# Comparison of Various Sorting Algorithms
## Course Code: CO203
## Assignment

### About

The performance of the following sorting algorithms are measured across different sizes of input by noting down the time taken
for execution. 
* Bubble sort
* Selection sort
* Insertion sort
* Merge sort
* Quick sort
* Heap sort

The input sizes vary from 5 to 2,000,000 to study which algorithms perform better for both small and large input sizes. Graphs are plotted on linear, semi-log and log-log scale to understand the behaviour of the algorithms at both small and large input sizes.

### Observations

After conducting the experiment, it is observed that for input sizes till about 150 elements, insertion sort performs the best and for input sizes larger than 10,000 quick sort performs the best. For input sizes in-between, the performance of merge sort, quick sort and heap sort are pretty much the same and they all outperform the remaining sorts.

### Conclusion

It is thus verified that the merge sort, quick sort and heap sort which take O(nlogn) time perform better than bubble sort, selection sort and insertion sort which take O(n<sup>2</sup>) time.

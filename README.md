# Heapsort-Testing
An experiment to generalize heaps to complete k-ary trees in which each node is smaller than its parent. Experiments with finding a value of k which is optimal with respect to time used for heapsort.

###Opportunities for expansion

* The experiment uses a randomly generated list. Sorting is not always done on a completely randomized list. More preemptive arrays could be generated in order to simulate different possible situations.

* Differing list sizes can be evaluated (the current minimum size is 1 million). Perhaps some k-ary heaps are better at sorting different sized heaps, in which case the best algorithm would be one in which a heap is first partially sorted, and then later sorted using some other technique.

* Develop a way to keep track of and graphically display data, rather than simply printing results to the console.
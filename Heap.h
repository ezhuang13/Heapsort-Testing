//
// Author: Eric Zhuang
//

#include <vector>
#include <cstdlib>
#include <iostream>
#include <math.h>

#ifndef HEAP_H
#define HEAP_H


/*
 * Minimalistic heap class that can implement
 * construction of a heap, printing, and sorting
 */
template <int K>
class Heap{

private:

    std::vector<int> myHeap;

    //Bubbles down element at ith position into the heap
    //Assumes the ith position is a valid entry in heap
    void bubbleDown(int i, std::vector<int> &heap) {
        bool mustBubble = false;
        int minChild = heap[i];
        int minChildIndex = i;
        for (int j = 1; j <= K; ++j) {
            int curChild = K * i + j;
            if (curChild < heap.size() && minChild > heap[curChild]) {
                minChild = heap[curChild];
                minChildIndex = curChild;
                mustBubble = true;
            }
        }
        if (mustBubble) {
            std::swap(heap[i], heap[minChildIndex]);
            bubbleDown(minChildIndex, heap);
        }
    }

public:

    //Default constructor for an empty heap
    explicit Heap():myHeap(){}

    //Parametrized constructor that passes in a vector and heapifies it
    //in constant O(n) time
    explicit Heap(std::vector<int> nums):myHeap(nums){
        for (int i = myHeap.size() - 1; i >= 0; --i){
            bubbleDown(i, myHeap);
        }
    }

    //Destructor
    ~Heap(){}

    //Calls heapsort on the current heap, returning a sorted vector
    std::vector<int> heapSort(){
        std::vector<int> sorted;
        std::vector<int> unsorted(myHeap);
        while (!unsorted.empty()) {
            sorted.push_back(unsorted[0]);
            std::swap(unsorted[0], unsorted[unsorted.size() - 1]);
            unsorted.pop_back();
            bubbleDown(0, unsorted);
        }
        return sorted;
    }

    //Prints out the contents of the heap, with each layer in a new line
    void printHeap(){
        int numInLayer = 1;
        int maxInLayer = 1;
        for (int i = 0; i < myHeap.size(); ++i){
            std::cout << myHeap[i] << " ";
            if (numInLayer++ == maxInLayer){
                maxInLayer *= K;
                numInLayer = 1;
                std::cout << "\n";
            }
        }
        std::cout<< "\n";
    }

};

#endif //HEAP_H

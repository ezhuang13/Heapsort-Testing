#include "Heap.h"
#include <ctime>
#include <stdlib.h>

//
// Author: Eric Zhuang
//


/*
An experiment to generalize heaps to complete k-ary trees in which each node is
smaller than its parent. Experiments with finding a value of k which is
optimal with respect to time used for heapsort
 */

int main() {
    //Prompt user for size of test vector
    int size;
    std::cout << "Enter the size of the array (in millions) you wish to sort: ";
    std::cin >> size;
    size *= 1000000;

    //Creates vector filled with random integers
    std::srand(time(NULL));
    std::vector<int> test;
    for (int i = 0; i < size; ++i){
        int val = rand() % 100 + 1;
        test.push_back(val);
    }
    std::cout<<"\n";
    std::cout << "Clock-times of sorting k-ary heaps:\n";


    /*
     * Runs trials by measuring the number of clock cycles needed to sort the randomly generated array
     * Trials are done with complete heaps of 2, 3, 4, 5, 10, and 50 branches
     * Time to both build and sort the heap are measured
     * Note: Unfortunately, trials cannot be generalized as templates require a constant expression argument
     */
    clock_t startTime;

    std::cout << "For a binary heap: ";
    startTime = clock();
    Heap<2> h2(test);
    h2.heapSort();
    std::cout << float(clock() - startTime) << std::endl;

    std::cout << "For a trinary heap: ";
    startTime = clock();
    Heap<3> h3(test);
    h3.heapSort();
    std::cout << float(clock() - startTime) << std::endl;

    std::cout << "For a 4nary heap: ";
    startTime = clock();
    Heap<4> h4(test);
    h4.heapSort();
    std::cout << float(clock() - startTime) << std::endl;

    std::cout << "For a 5nary heap: ";
    startTime = clock();
    Heap<5> h5(test);
    h5.heapSort();
    std::cout << float(clock() - startTime) << std::endl;

    std::cout << "For a 10nary heap: ";
    startTime = clock();
    Heap<10> h10(test);
    h10.heapSort();
    std::cout << float(clock() - startTime) << std::endl;

    std::cout << "For a 50nary heap: ";
    startTime = clock();
    Heap<50> h50(test);
    h50.heapSort();
    std::cout << float(clock() - startTime) << std::endl;

    return 0;
}
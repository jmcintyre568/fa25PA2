//
// Created by Manju Muralidharan on 10/19/25.
//Jasper McIntyre
// Nov 3 2025
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size]=idx;
        size++;
        upheap(size-1, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size==0) return -1;
        int smallest=data[0];
        data[0]=data[size-1];
        size--;
        if (size>0) {
            downheap(0,weightArr);
        }
        return smallest;
        //return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos>0) {
            int parent = (pos-1)/2;
            if (weightArr[data[pos]]<weightArr[data[parent]]) {
                int temp = data[pos];
                data[pos]=data[parent];
                data[parent]=temp;
                pos=parent;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (pos<size) {
            int left = (pos*2)+1;
            int right = (pos*2)+2;
            int smallest = pos;

            if (left<size && weightArr[data[left]]<weightArr[data[smallest]]) {
                smallest = left;
            }
            if (right <size && weightArr[data[right]]<weightArr[data[smallest]]) {
                smallest = right;
            }
            if (smallest != pos) {
                int temp = data[pos];
                data[pos]=data[smallest];
                data[smallest]=temp;
                pos=smallest;
            } else {
                break;
            }
        }
    }
};

#endif

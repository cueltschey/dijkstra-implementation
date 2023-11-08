#include "heap.h"

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int size){
    heap_size = size;
    capacity = size;
    harr = new int[2][size]
    for(int i = 0; i < size; ++i){
      harr[i][0] = i;
      harr[i][1] = INT_MAX;
    }
}
 
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int name, int new_val)
{
    int i = 0;
    for(int i = 0; i < heap_size; i++){
      if(harr[i][0] == name){
        harr[i][1] = new_val;
      }
    }
    while (i != 0 && harr[parent(i)][1] > harr[i][1])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::pop()
{
    if (heap_size <= 0)
        throw("heap empty");
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0][0];
    }
 
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
 
    return root;
}
 
 
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    pop();
}
 
// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l][1] < harr[i][1])
        smallest = l;
    if (r < heap_size && harr[r][1] < harr[smallest][1])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
// A utility function to swap two elements
void MinHeap::swap(int[2] *x, int[2] *y)
{
    int[2] temp = *x;
    *x = *y;
    *y = temp;
}

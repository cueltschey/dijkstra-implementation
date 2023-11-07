#include "heap.h"

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(Node nodes[], int size)
{
    heap_size = 0;
    capacity = size;
    for(int i = 0; i < size; i++){
      insert(nodes[i]);
    }
}

void MinHeap::insert(Node n){
  if(heap_size == capacity){
    return;
  }
  harr[heap_size] = n;
  int i = heap_size;
  while(i != 0 && harr[parent(i)].distance > harr[i].distance){
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }
  heap_size++;
}
 
 
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int name, int new_val)
{
    int i = 0;
    while(harr[i].name != name){i++;}
    harr[i].distance = new_val;
    while (i != 0 && harr[parent(i)].distance > harr[i].distance)
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Method to remove minimum element (or root) from min heap
Node MinHeap::pop()
{
    if (heap_size <= 0)
        throw("heap empty");
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 
    // Store the minimum value, and remove it from heap
    Node root = harr[0];
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
    if (l < heap_size && harr[l].distance < harr[i].distance)
        smallest = l;
    if (r < heap_size && harr[r].distance < harr[smallest].distance)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
// A utility function to swap two elements
void MinHeap::swap(Node *x, Node *y)
{
    Node temp = *x;
    *x = *y;
    *y = temp;
}

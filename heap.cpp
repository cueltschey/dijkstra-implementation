#include "heap.h"

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int vertexes[], int size)
{
    heap_size = 0;
    capacity = size;
    harr = new Vertex[size]
    for(int i = 0; i < size; i++){
      harr[i] = new Vertex(vertexes[i]) 
    }
}
 
// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
 
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    Vertex vert = new Vertex(k);
    harr[i] = vert;
 
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)].distance > harr[i].distance)
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i].distance = new_val;
    while (i != 0 && harr[parent(i)].distance > harr[i].distance)
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Method to remove minimum element (or root) from min heap
Vertex MinHeap::extractMin()
{
    if (heap_size <= 0)
        throw("heap empty");
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 
    // Store the minimum value, and remove it from heap
    Vertex root = harr[0];
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
    extractMin();
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
void swap(Vertex *x, Vertex *y)
{
    Vertex temp = *x;
    *x = *y;
    *y = temp;
}

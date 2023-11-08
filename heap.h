// A C++ program to demonstrate common Binary Heap Operations
#include "Node.h"

using namespace std; 

 
// A class for Min Heap
class MinHeap
{
private:
    Node* harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(Node* nodes[11], int size);

    void insert(Node n);
 
    // to heapify a subtree with the root at given index
    void MinHeapify(int );
 
    int parent(int i) { return (i-1)/2; }
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to extract the root which is the minimum element
    Node* pop();
 
    // Decreases key value of key at index i to new_val
    void decreaseKey(int name, int new_val);
 
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0].distance; }
 
    // Deletes a key stored at index i
    void deleteKey(int i);
 
    // utility for swapping nodes
    void swap(Node *x, Node *y);
};

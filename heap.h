// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include<limits>


using namespace std; 

//class for storing graph related data
class Vertex{
public:    
  int name;
  int distance;
  Vertex* parent;
  Vertex(int n){
    name = n;
    distance = INT_MAX;
    parent = nullptr;
  }
};
 
// A class for Min Heap
class MinHeap
{
private:
    Vertex* harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int* vertexes, int size);
 
    // to heapify a subtree with the root at given index
    void MinHeapify(int );
 
    int parent(int i) { return (i-1)/2; }
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to extract the root which is the minimum element
    Vertex extractMin();
 
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
 
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0].distance; }
 
    // Deletes a key stored at index i
    void deleteKey(int i);
 
    // Inserts a new key 'k'
    void insertKey(int k);

    void swap(Vertex *x, Vertex *y);
};

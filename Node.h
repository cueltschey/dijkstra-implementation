#include <climits>

// class to help organize graph data
class Node
{
  public:
    Node* edges;
    int* weights;
    int num_edges;
    Node parent;
    int name;
    int distance;

    Node(int n, int size){
      name = n;
      parent = nullptr;
      distance = INT_MAX;
    }
  };

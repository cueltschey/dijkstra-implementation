#include <climits>

// class to help organize graph data
class Node
{
  public:
    int* weights;
    Node* edges[3];
    Node* parent;
    int name;
    int distance;

    Node(int n){
      name = n;
      parent = nullptr;
      distance = INT_MAX;
    }
    Node(){
      name = 0;
      parent = nullptr;
      distance = INT_MAX;
    }
  };

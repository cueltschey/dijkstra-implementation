#include "heap.h"
#include <iostream>



using namespace std;

int main(){
  
  /*
  int names[11] = {1,2,3,4,5,6,7,8,9,10,11};
  vector<int> edges[11][2] = {
    {{4,6,9},{1,3,7}},
    {{5,8},{2,2}},
    {{6,5},{2,5}},
    {{3},{5}},
    {{8,9},{6,3}},
    {{5},{6}},
    {{},{}},
    {{10,11},{3,8}},
    {{5,7},{3,4}},
    {{8},{3}},
    {{}},{}}
};
*/
  //initialize nodes
  Node* nodes;
  for(int name = 0; name < 11; ++name){
    nodes[name] = new Node(name);
  }


  // connect nodes
  nodes[0].num_edges = 3;
  nodes[0].edges = {1,3,9};
  nodes[0].weights = {4,1,3};

  nodes[1].num_edges;
  nodes[1].edges;
  nodes[1].weights;

  nodes[2].num_edges;
  nodes[2].edges;
  nodes[2].weights;

  nodes[3].num_edges;
  nodes[3].edges;
  nodes[3].weights;

  nodes[4].num_edges;
  nodes[4].edges;
  nodes[4].weights;

  nodes[5].num_edges;
  nodes[5].edges;
  nodes[5].weights;

  nodes[6].num_edges;
  nodes[6].edges;
  nodes[6].weights;

  nodes[7].num_edges;
  nodes[7].edges;
  nodes[7].weights;

  nodes[8].num_edges;
  nodes[8].edges;
  nodes[8].weights;

  nodes[9].num_edges;
  nodes[9].edges;
  nodes[9].weights;

  nodes[10].num_edges;
  nodes[10].edges;
  nodes[10].weights;

  return 0;
  //strating the algorith:  
  int start;
  cout << "enter starting node: ";
  cin >> start;

  int end;
  cout << "enter ending node: ";
  cin >> end;

   

}

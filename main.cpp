#include "heap.h"
#include <iostream>
#include <cstdlib>



using namespace std;


void algorithm(Node* n, MinHeap &p){
    cout << n->name << endl;
    for(int i = 0; i < 3; ++i){
      int current = n->distance + n->weights[i];
      int cur_dist = n->edges[i]->distance;
      if(current < cur_dist){
        n->edges[i]->distance = current;
        p.decreaseKey(n->name, current);
      }
    }
    algorithm(p.pop(), p);
  }

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
  Node* nodes[11];
  for(int name = 0; name < 11; ++name){
    Node* n = new Node(name);
    nodes[name] = n;
  }


  // connect nodes

  for(int i = 0; i < 11; ++i){
    for(int j = 0; j < 3; ++j){
      nodes[i]->edges[j] = nodes[i + (rand() % 4)];
      int we[3] = {rand() % 5, rand() % 5, rand() % 5};
      nodes[i]->weights = we; 
    }
  }

  //strating the algorith:  
  int start;
  cout << "enter starting node: ";
  cin >> start;

  int end;
  cout << "enter ending node: ";
  cin >> end;

  MinHeap p = MinHeap(nodes, 11);
  p.decreaseKey(start, 0);
  cout << "here" << endl;
  algorithm(p.pop(), p); 
  }

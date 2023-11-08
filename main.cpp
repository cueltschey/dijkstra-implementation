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
  

  //starting the algorith:  
  int start;
  cout << "enter starting node: ";
  cin >> start;

  int end;
  cout << "enter ending node: ";
  cin >> end;

  MinHeap p = MinHeap(11);
  p.decreaseKey(start, 0);
  
  for(int hn = 0; hn < 11; hn++){
    cout << "harr: " << p.harr[hn].name << " " << p.harr[hn].distance << endl;
    cout << "edges:" << endl << endl;
    for(int e = 0; e < 3; e++){
      cout << p.harr[hn].edges[e]->name << " " << p.harr[hn].weights[e] << endl;
    }
    cout << endl;
  }

  algorithm(p.pop(), p); 
  }

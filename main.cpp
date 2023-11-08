#include <iostream>



using namespace std;


void dijkstra(int n[2], MinHeap &p){
    cout << n << endl;
    for(int i = 0; i < 3; ++i){
      int current = n[0] + n->weights[i];
      int cur_dist = p.harr[i];
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

  }

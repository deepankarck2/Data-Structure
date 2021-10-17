#include<iostream>
#include<vector>
#include <cstring>
//https://youtu.be/x6N5FK6ArRk?list=PLFj4kIJmwGu3m30HfYDDufr3PZBfyngr0 
/**
 * Easy to implement and understand
 * Adding/ Removing an edge takes O(1) time complexity 
 * Easy quesries: checking edge, etc can be done with O(1) time
 * */
/**
 * Takes a lot of space --> o(n^2) or V * V, Even if the graph is sparce
 * Adding/Removing a vertex is O(v^2) time. Bc copy evetything in a new 2D array. 
 * */

//https://www.geeksforgeeks.org/create-dynamic-2d-array-inside-class-c/ 
// https://www.youtube.com/watch?v=ZARVM92Xstg 
using namespace std;
#define V 5

class Graph{
    int v; 
    bool **adj; 
//C++ doesn’t allow to create an stack allocated array in a class whose size is not constant. So we need to dynamically allocate memory. 
public: 
   Graph(int v){
        this->v = v; 
        adj = new bool* [v]; 
        
        for(int i=0; i< v; i++){
            adj[i]= new bool[v]; 
            memset(adj[i], false, v*sizeof(bool)); 
   }
}
    
    void addEdge(int u, int v){
        adj[u][v]= 1; 
    }
    void printGraph(){
        for(int i =0; i<v; i++){
            cout << i << "| "; 
            for(int j =0 ; j<v; j++){
                cout<< adj[i][j]<< " "; 
            }
            cout << endl; 
        }
    }
};

int main(){
    Graph g(V); 
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
  
    g.printGraph();
    return 0;
}

/*
//Alternative way 

void addEdge(int graph[][V], int x, int y){
    graph[x][y] =1;  
}
int main(){
    int graph[V][V]={0};
    
    addEdge(graph, 0,1);
    addEdge(graph, 3,4);
    addEdge(graph, 2,1); 
    
    for(int i=0; i< V; i++){
        cout<< i << "| "; 
        for(int j=0; j< V; j++){
            cout << graph[i][j] << " ";
        }
        cout<<endl; 
    }
    
    return 0;
}
*/ 
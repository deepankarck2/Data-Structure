#include<iostream>
#include<unordered_map>
#include<cstring>
#include<list>

using namespace std;

class Graph{
     //Adj list
    unordered_map<string, list<pair<string,int> > >l; //mapping between each nodes and vertices     
    
public:
    void addEdge(string x, string y, bool bidir, int wt){
        l[x].push_back(make_pair(y,wt));
            if(bidir){
                l[y].push_back(make_pair(x,wt)); 
            }
    }

    void printAdjList(){
        //Iterate over all the keys of the map;
        for(auto p : l){
            string city = p.first; 
            list<pair<string,int> > nbrs = p.second ;
            cout << city << "-->"; 
                for(auto nbr: nbrs){
                    string dest = nbr.first; 
                    int wt = nbr.second; 
                    cout << dest << " " << wt << ", "; 
                }
        cout << endl; 
        }
    }

};

int main(){
     
    Graph g;
    
    g.addEdge("A", "B" , true, 20);
    g.addEdge("B", "D" , false, 36); 
    g.addEdge("A", "D" , true, 20); 
    g.addEdge("D", "C" , false, 20); 
    
    g.printAdjList();
    return 0;
}

//--------------------------------Another Example: ----------------------------------------------------//

// https://www.programiz.com/dsa/graph-adjacency-list 
//Here we are using a list vector of lists: vector<int> adj[v] --> v is the number of vertices, 

/* The adjacency list representation of a graph is linked list representation. In this representation we have an array of lists The array size is V. Here V is the number of vertices. In other words, we can say that we have an array to store V number of different lists. If a list header is vertex u, then it signifies that it will hold all of the adjacent vertices of u.
*/ 

// Adjascency List representation in C++

#include <bits/stdc++.h>
using namespace std;

// Add edge
void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

// Print the graph
void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}

int main() {
  int V = 5;

  // Create a graph
  vector<int> adj[V];

  // Add edges
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  printGraph(adj, V);
}
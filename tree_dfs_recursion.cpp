#include<iostream>
#include<map>
#include<vector>
#include<stack>

using namespace std; 

map<int, vector<int> > adj; 
map<int, bool> visited; 

class Graph{
    public: 
        void printGraph(); 
        void addEdge(int u, int v);
        void visitedNode(int node); 
        void dfs(int start); 
}; 


void Graph:: addEdge(int u, int v){
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}

void Graph::visitedNode(int node){
    cout << node << " "; 
    visited[node] = true; 
}

void Graph::printGraph(){
    for(auto it: adj){
        std::cout << it.first << "--> "; 
            for(auto i: it.second){
                cout << i << " ";  
            }
        cout << endl; 
    }
}

void Graph::dfs(int start){ //recursion 
    visitedNode(start); 
    vector<int> current = adj[start]; 
    
    for(auto i: current){
        if(visited[i] != true){
            dfs(i); //for all verteces adjacent to the current vertex  
        }
    }
}

int main(){
    Graph gp; 

    gp.addEdge(1,2); 
    gp.addEdge(1,4); gp.addEdge(4,5);
    gp.addEdge(2,4); gp.addEdge(2,3);
    gp.addEdge(3,6); gp.addEdge(4,6);
    
    gp.printGraph(); 
    
    gp.dfs(1); 
    return 0; 
}
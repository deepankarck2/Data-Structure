//https://www.youtube.com/watch?v=kVyIhwYnLNs&list=PLk6CEY9XxSIBG2Gv6-d1WE3Uxqx94o5B2&index=9 

#include <iostream>
#include <vector>
#include <stack>
#include <map> 

using namespace std; 
map<int, bool> visited;  
map<int, vector<int> > adj; //map of int and vector 

class Graph{
    public: 
        void addEdge(int start, int end){ 
            adj[start].push_back(end); //Ex: Key 4, push bach 5, key again 4, push_back 9. 
            adj[end].push_back(start); 
        }
        void printGraph();
        void dfs(map<int, vector<int> >& adj, int start);          
        void visitedNode(int node); 
};

void Graph::printGraph(){
        for(auto it: adj){ //it => 1 = {4,2,3}, here it returns the whole Key-Value of the first element of the map. 
            cout << it.first << "--> "; //it.first = 1,2,3,4...
             for(auto i: it.second){ //it.second = {4,31,2}
                cout << i << " "; 
            }
            cout << endl; 
        }
} 

void Graph::visitedNode(int node){
    cout << node << " ";  
    visited[node] = true; 
}

void Graph::dfs(map<int, vector<int> >& adj, int start){
    stack<int> stk; 
    stk.push(start);  
    
    while(! stk.empty()){
        int temp = stk.top(); 
        stk.pop(); 
        if(visited[temp] != true) {
            
            visitedNode(temp);
            
            auto tmp = adj[temp];
            for(auto i: tmp){
                stk.push(i); 
            } 
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
    cout << endl; 
    
    gp.dfs(adj, 5); 
}    
    
    
    
    
    
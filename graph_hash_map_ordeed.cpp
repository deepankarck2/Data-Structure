#include<unordered_map>
#include<iostream>
#include<cstring>

using namespace std;

class Graph{
public:
    //Adj list
    unordered_map<string, list<pair<string,int>>> L;

    void addEdge(string x, string y, bool bidir, int wt){
        L[x].push_back(make_pair(x,wt));
            if(bidir){
                L[y].push_back(make_pair(y.wt)); 
            }
    }

    void printAdjList(){
        //Iterate over all the keys of the map;
        for(auto p : L){
            string city = p.first; 
            list<pair<string, int> nbrs = p.second; 
                for(auto nbr: nbrs){
                    string dest = nbr.first; 
                    int wt = nbr.second; 
                    cout << dest << " " << wt << " "; 
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
    return 0;
}
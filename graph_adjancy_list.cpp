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

//3rd
//2nd 
//9th 
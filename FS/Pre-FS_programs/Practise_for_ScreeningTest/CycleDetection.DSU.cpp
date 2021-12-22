#include <bits/stdc++.h>
using namespace std;

struct Edge{            // Can also try pair<int, int>..
    int src, dst;
};

class Graph{
  public:
    vector<vector<int>> edgeList;
    Graph(vector<Edge> edges){
        edgeList.resize(edges.size());      // Expand it.. 
        // Fill the edgeList..
        for(auto edge: edges)
            edgeList[edge.src].push_back(edge.dst);
    }
};

class DisJointSetUnion{
 public: 
    unordered_map<int, int> parents;                    // to store all the parents..
    
    DisJointSetUnion(int numNodes){
        makeSet(numNodes);
    }
    
    // to pr...
    void makeSet(int size){
        for(int idx=0; idx<size; idx++)
            parents[idx] = idx;  //-1  //idx            // Making (size) no. of disjoint sets..
    }

    // Find the root of a given node..
    int findRoot(int u){
        if(u == parents[u])                             // If itself is the root.. means itself is the parent..
            return u;
        //return parents[u] = findRoot(parents[u]);       // CompressedFind..
        return findRoot(parents[u]);
    }

    // Unionize..
    void unionize(int u, int v){
    //if(u!=v)                                          // If not, both already belongs to the same set.. -- not required here.. as handling at the caller side..
        if(u < v)                                       // Weighted Union: Making the smaller one as parent..
            parents[v] = u;
        else
            parents[u] = v;
    }
};

bool isCycleDetected(vector<Edge> edges){
    // Create the graph as a EdgeList format from the collection of edges..
    Graph graph(edges);
    DisJointSetUnion dsu(edges.size());

    for(auto & parent: dsu.parents)
        cout << parent.first << endl;

    // Start finding the cycle.. with the help of edgelist..
    for(int u=0; edges.size(); u++) 
        for(int v : graph.edgeList[u]){
            cout << "[INFO] received  u: " << u <<", v: " << v << endl;
            // find the roots of the nodes..
            u = dsu.findRoot(u);        
            v = dsu.findRoot(v);

            if(u == v){                      // If both belong to a same parent.. indicates that-- its a cycle..
                cout << "[INFO] Got  u: " << u <<", v: " << v << endl;
                return true;
            }
            else
                dsu.unionize(u, v);         // if not so, unionize..
        }
    // Control comes here, after the try of unioniZing..
    return false;
}

int main(int argc, char**argv){
    int numEdges=0, src=0, dstn=0;
    cin >> numEdges;
    vector<Edge> edges;
    for(int edgeCount=0; edgeCount < numEdges; edgeCount++){
        cin >> src >> dstn;
        edges.push_back({src, dstn});
    }

    cout << "Starting Cycle detection..." << endl;
    if(isCycleDetected(edges))
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle detected" << endl;
}

/*

12
0 1	
0 6
0 7
1 2
1 5
2 3
2 4
7 8
7 11
8 9
8 10
10 11 <<<<<<< edge that makes cycle..
Starting Cycle detection...
Cycle Detected

*/
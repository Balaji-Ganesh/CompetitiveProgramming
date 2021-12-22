#include<bits/stdc++.h>
using namespace std;
vector<int> parents;

int find_root(int node){
    if(parents[node] < 0)                             // If it the root element.. 
        return node;
    return parents[node] = find_root(parents[node]);    // Collapsing path 
} 

void unionize(int node1, int node2){
    // Get the absolute roots of the nodes to be unioned..
    int rootA = find_root(node1);
    int rootB = find_root(node2);
    
    if(rootA != rootB)      // Only if both are not already the child of a common root..
        // Who ever has more no. of childs will be the parent..
        if(parents[rootA] <= parents[rootB]){ // -- Dealing with -ve values.. so careful..
            parents[rootA] += parents[rootB];        // Accumulate the rank..
            parents[rootB] = rootA;
        }
        else{
            parents[rootB] += parents[rootA];
            parents[rootA] = rootB;
        }    
}

int findComponents(vector<vector<int>> edges){
    // cout << "parents before making union operation: " << endl;
    // for(auto value: parents)
    //     cout << value << endl;

    // Make the edges in the graph..
    for(auto edge: edges)
        unionize(edge[0], edge[1]);
    
    // cout << endl<< "parents after making union operation: " << endl;
    // for(auto value: parents)
    //     cout << value << endl;

    // find the no. of roots, which answers the question of: "How many components?"
    int num_components=0;
    for(int parent: parents)
        if(parent < 0)
            num_components++;
    
    return num_components;
}

int main(){
    int numNodes=0, numEdges=0, tempEdge1=0, tempEdge2=0;
    cin >> numNodes >> numEdges;
    parents.assign(numNodes, -1);
    vector<vector<int>> edges;

    for(int i=0; i<numEdges; i++){
        cin >> tempEdge1 >> tempEdge2;
        edges.push_back({tempEdge1, tempEdge2});
    }
    
    cout << findComponents(edges) << " components in the graph" << endl;

    int max_childs = 0;
    for(auto value: parents)
        if(value <0 && -value > max_childs)       // If it is root
            max_childs = -value;
    
    cout << "Max childs among the components: " << max_childs << endl;

    // for(int i=0; i<numNodes; i++){
    //     cout << i<<": " << find_root(i) << endl;
    // }
}

// Worked out on 2nd November, 2021 - Tuesday_1 By grace of Krishna
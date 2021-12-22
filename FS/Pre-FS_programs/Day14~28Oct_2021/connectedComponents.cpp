#include <bits/stdc++.h>
using namespace std;

// Recursive function to find the root of any given node...
int find_root(int node, int parents[]){
    // If itself is the root.. return itself..
    if(parents[node] == node)
        return node;
    return parents[node] = find_root(parents[node], parents);        // Also does path compression on the go..
}

void unionize(int parent, int child, int parents[]){
    int child_root  = find_root(child, parents);
    int parent_root = find_root(parent, parents);

    cout << "Obtained parents are: " << child_root<<", " << parent_root;    
    // Only if it itself is not the root..
    if(child_root != parent_root)
        parents[child_root]  = parent_root;
}

int findComponents(vector<vector<int>> edges){
    // An array to store each node's parents
    int parents[edges.size()];
    for(int i=0; i<edges.size(); i++)
        parents[i] = i;                         // Initially, each node itself is the root node (the node which will have its value and index same)
    
    // Connect the edges..
    for(auto edge: edges){
        unionize(edge[0], edge[1], parents);
    	cout << "unioned " << edge[0] << " and " <<edge[1] << endl;
    }

    // Displaying the roots..
    for(auto parent: parents)
	   cout<<parent << "\t"; 
    // Find the no. of unique roots.. which answers the question of "How many connected components?"
    set<int> unique_roots;
    for(int i=0; i<edges.size(); i++)
        unique_roots.insert(parents[i]);
    return unique_roots.size();
}

int main(){
    int num_edges, node1, node2;
    cin >> num_edges;

    vector<vector<int>> edges;

    for(int i=0; i<num_edges; i++){
        cin >> node1 >> node2;
        edges.push_back({node1, node2});
    }

    cout << findComponents(edges);  /// ==1: connected, >1 not connected.
}

/*
 * 0 1 2 4 3
 * { 1, 0 }, { 0, 2 }, { 5, 3 }, { 3, 4 }, { 6, 7 }}*/

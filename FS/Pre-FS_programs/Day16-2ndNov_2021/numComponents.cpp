#include <iostream>
#include <vector>
#include <set>
using namespace std;

int find_root(vector<int>&parents, int city){
    cout <<"parent: " << parents[city] << endl;
    if(parents[city] == city)
        return city;
    return parents[city] = find_root(parents, parents[city]);
}

void unionize(int city1, int city2, vector<int>&parents)
{
    int root1 = find_root(parents, city1);
    int root2 = find_root(parents, city2);

    if(root1 != root2)
        parents[root1]=root2;

    cout<<root1<<"   " << root2 << endl;
}

int findComponents(vector<int> &cities, vector<vector<int>> routes){
    
    for(auto route: routes)
        unionize(route[0], route[1], cities);
    
    //for(auto route: routes

    set<int> unique_cities;
    for(auto city: cities)
        unique_cities.insert(city);

    //for(auto city: cities)
	//    cout << city <<"  ";

    return unique_cities.size();
}

int main(){
    int numCities=0, numRoutes=0, city1=0, city2=0;
    cin >> numCities >> numRoutes;
    vector<vector<int>> routes;
    vector<int> cities;
    
    // Set self-parents..
    for(int i=0; i<numCities; i++)
        cities.push_back(i);
    
    // Take the routes..
    for(int i=0; i<numRoutes; i++){
        cin >> city1 >> city2;
        routes.push_back({city1, city2});
    }
	
   cout << findComponents(cities, routes);
    for(auto city: cities)
    	cout << city << "  ";
   cout << endl;   
   // cout << findComponents(cities, routes);
}

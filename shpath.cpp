// shortest path between two cities -- Djikstra algorithm

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;
using std::cout;
using std::cin;
using std::endl;

void djk_short_path(vector<vector<int>> & graph, int source, int dest) {
    // find shortest path from source to dest -- Djikstra algo

#if 0 
    for (int i = 1; i < graph.size(); ++i) {
        for (int j = 1; j < graph[i].size(); ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << "src: " << source << " dst: " << dest << endl;
#endif

    vector<bool> visited(graph.size(), false), non_visited(graph.size(), true);
    
}

int main() {
    int t;
    cin >> t; // test cases
    for (int i = 0; i < t; ++i) {
        int num_cities;
        cin >> num_cities;
        // 2D adjacency matrix 
        vector<vector<int>> city_graph(num_cities + 1, vector<int>(num_cities + 1, 0));
        unordered_map<string, int> city_names;
        for (int j = 1; j <= num_cities; ++j) {
            string name;
            cin >> name;
            city_names[name] = j; // city_names mapped to numbers
            int nbr; // neighbours
            cin >> nbr;
            for (int k = 0; k < nbr; ++k) {
                int n_index, cost;
                cin >> n_index;
                cin >> cost;
                city_graph[j][n_index] = city_graph[n_index][j] = cost;
            }
        }
        int path_to_find;
        cin >> path_to_find;
        for (int k = 0; k < path_to_find; ++k) {
            string source, dest;
            cin >> source;
            cin >> dest;
            djk_short_path(city_graph, city_names[source], city_names[dest]);
        }
        // ignore blank line
        string blank;
        cin >> blank;
    }


}


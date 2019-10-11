// shortest path between two cities -- Djikstra algorithm

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <climits>
#include <list>
#include <iterator>
#include <utility>
#include <queue>

using std::vector;
using std::string;
using std::list;
using std::set;
using std::unordered_map;
using std::pair;
using std::cout;
using std::cin;
using std::endl;
using std::iterator;

typedef struct {
    int y;      // adjacency info
    int weight; // edge weight
} edgenode;

class Graph {

private:
    int nvertex;               // no. of vertices
    vector <int> degree = vector<int>(nvertex, 0); // degree of each vertex
    vector<list<edgenode>> adj_list = vector<list<edgenode>>(nvertex);   // adjacency list representation

public:
    Graph(int vertices): nvertex {vertices} {
    }
    
    void insert_edge(int src, int dst, int weight);
    void djk_short_path(int source, int dest); 
    void show_graph();

};

void Graph::show_graph() {
    // print graph utility function
    
    for (int i = 1; i < adj_list.size(); ++i) {
        cout << i << "(" << adj_list[i].size() << ")";
        for (auto iter = adj_list[i].begin(); 
                iter != adj_list[i].end(); ++iter) {
            cout << " " << (*iter).y;
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::insert_edge(int src, int dst, int weight) {
    // insert edge src-dst with weight
    
    ++degree[src];
    
    // push edge node for src
    edgenode e;
    e.y = dst;
    e.weight = weight;
    adj_list[src].push_front(e);
}

void Graph::djk_short_path(int source, int dest) {
    // find shortest path from source to dest -- Djikstra algo
    
    using std::make_pair;
    
    // to keep track of visited and non visited nodes
    vector<bool> visited(nvertex, false);
    
    // maintain shortest distance from source
    vector<int> short_dist(nvertex, INT_MAX);
    short_dist[source] = 0;

    // priority queue (using set) to contain the least 
    // cost distance among all discovered node
    // first = least cost yet, second cost's node index
    set<pair<int, int>> least_dist;
    least_dist.insert(make_pair(short_dist[source], source));
    
    // stop as soon as dest is discovered
    while (visited[dest] != true) {
        auto it = least_dist.begin();
        int node_index = (*it).second; // smallest element (current node)
        int sm_cost = (*it).first;     // cost yet
        
        // delete current node
        least_dist.erase(it);
        
        // check all adjacent vertices of node_index
        for (auto iter = adj_list[node_index].begin(); 
                iter != adj_list[node_index].end(); ++iter) {
            int neighbour = (*iter).y;
            int weight = (*iter).weight;
            if (visited[neighbour] == false) { // if the neighbour hasn't been visited yet
                if (sm_cost + weight < short_dist[neighbour]) { // we've discovered smallest route to that node
                    int old_sm_cost = short_dist[neighbour];
                    short_dist[neighbour] = sm_cost + weight;
                    
                    // find if the pair exists in queue
                    auto it = least_dist.find(make_pair(old_sm_cost, neighbour));
                    if (it != least_dist.end()) {
                        // delete the old index and cost
                        least_dist.erase(it);

                        // add new node index and cost
                        least_dist.insert(make_pair(short_dist[neighbour], neighbour));
                    }
                    else {
                        // add new node index and cost
                        least_dist.insert(make_pair(short_dist[neighbour], neighbour));
                    }
                }
            }
        }
        
        visited[node_index] = true;
    }
    
    // print shortest distance
    cout << short_dist[dest] << endl;
}



int main() {
    int t;
    cin >> t; // test cases
    for (int i = 0; i < t; ++i) {
        int num_cities;
        cin >> num_cities;
        
        // city graph
        Graph city_graph(num_cities + 1);

        // mapping of city names to numbers 1 to num_cities
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
                city_graph.insert_edge(j, n_index, cost);
            }
        }
        int path_to_find;
        cin >> path_to_find;
        for (int k = 0; k < path_to_find; ++k) {
            string source, dest;
            cin >> source;
            cin >> dest;
            city_graph.djk_short_path(city_names[source], city_names[dest]);
        }
        //city_graph.show_graph();
    }

}


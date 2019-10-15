// graph algorithms implementation for mst

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
#include <cassert>
#include <unistd.h>

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

// graph data structure 
class Graph {

private:
    int nvertex;               // no. of vertices
    bool directed;             // is the graph directed or not?
    vector <int> degree = vector<int>(nvertex, 0); // degree of each vertex
    vector<list<edgenode>> adj_list = vector<list<edgenode>>(nvertex);   // adjacency list representation

public:
    Graph(int vertices, bool dir = true): nvertex {vertices}, directed {dir} {
    }
    
    void insert_edge(int src, int dst, int weight);
    void djk_short_path(int source, int dest); 
    void prims_mst(int source); 
    void show_graph();

};

void Graph::prims_mst(int source) {
    // prims min spanning tree
   
    using std::make_pair;

    vector <bool> in_tree(nvertex, false);   // is the vertex in the tree yet?
    
    // first is the cost, 
    // second is the index of the vertex
    set <pair <int, int>> distance;          // cost to include the vertex in the tree.
    distance.insert(make_pair(0, source));   // insert cost (0) & source vertex into the set.

    // store result
    vector <int> min_spt;
    
    // current iterator
    std::set< pair <int, int> >::iterator curr = distance.begin();

    int min_spt_cost = 0; // cost of min spanning tree
    
    while (distance.size() != 0) {
        int curr_vertex = (*curr).second; 
        // mark as visited
        in_tree[curr_vertex] = true;
        
        // add to solution
        min_spt.push_back(curr_vertex);
        min_spt_cost += (*curr).first;
        
        // remove curr_vertex from set
        distance.erase(curr);
        
        // iterate over neighbours of curr_vertex
        for (auto i = adj_list[curr_vertex].begin(); 
                i != adj_list[curr_vertex].end(); ++i) {
            int v = (*i).y;
            int v_dist = (*i).weight;
            // if the vertex hasn't been visited yet, include its weight
            if (in_tree[v] == false) {
                distance.insert(make_pair(v_dist, v));
            }
        }
        
        // get the least distance distance vertex 
        // which hasn't been included in the tree
        while (1) {
            if (distance.size() == 0) break;
            curr = distance.begin();
            if (in_tree[(*curr).second] == true)
                distance.erase(curr);
            else
                break;
        }
    }

    // print out min_spt
    cout << "min_spt:  \n"; 
    for (int i = 0; i < min_spt.size(); ++i)
        cout << " " << min_spt[i];
    
    // print out min_spt_cost
    cout << "\nmin_spt_cost:  \n"; 
    cout << min_spt_cost << endl;
    
}

void Graph::show_graph() {
    // print graph utility function
    
    cout << "vertex -- , adjacent vertex1 (weight1), adjacent vertex2 (weight2), ..." << endl;
    for (int i = 0; i < adj_list.size(); ++i) {
        cout << i << " -- ";
        for (auto iter = adj_list[i].begin(); 
                iter != adj_list[i].end(); ++iter) {
            cout << ", " << (*iter).y << " (" << (*iter).weight << ")";
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
    adj_list[src].push_back(e);
    
    // if it is undirected graph, src--dst implies dst--src
    if (directed == false) {
        ++degree[dst];
        e.y = src;
        e.weight = weight;
        adj_list[dst].push_back(e);
    }
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
    
    // shortest distance is in short_dist[dest]
    // cout << short_dist[dest] << endl;
}

int main() {
   
#if 0 
    Graph graph(9, false); // 9 vertices, undirected
    
    graph.insert_edge(0, 1, 4);
    graph.insert_edge(0, 7, 8);
    graph.insert_edge(1, 7, 11);
    graph.insert_edge(1, 2, 8);
    graph.insert_edge(7, 8, 7);
    graph.insert_edge(7, 6, 1);
    graph.insert_edge(8, 6, 6);
    graph.insert_edge(2, 8, 2);
    graph.insert_edge(2, 5, 4);
    graph.insert_edge(2, 3, 7);
    graph.insert_edge(3, 5, 14);
    graph.insert_edge(3, 4, 9);
    graph.insert_edge(5, 4, 10);
    graph.insert_edge(6, 5, 2);
    
    graph.show_graph();
    graph.prims_mst(0);
#endif
    
    Graph graph(8, false);

    graph.insert_edge(0, 3, 4);
    graph.insert_edge(1, 3, 7);
    graph.insert_edge(1, 5, 8);
    graph.insert_edge(5, 2, 7);
    graph.insert_edge(0, 2, 9);
    graph.insert_edge(0, 4, 7);
    graph.insert_edge(2, 6, 4);
    graph.insert_edge(6, 7, 4);
    graph.insert_edge(4, 6, 3);
    graph.insert_edge(2, 4, 9);
    
    graph.show_graph();
    graph.prims_mst(0);

}

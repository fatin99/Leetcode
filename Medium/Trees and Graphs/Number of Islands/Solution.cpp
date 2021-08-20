#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph {
public:
    int V; 
    unordered_map<int, vector<int>> adj;
    
    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; i ++) {
            adj[i] = {};
        }
    }
    
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
};

class Solution {
public:
    unordered_map<int, bool> visited;
    queue<pair<int, int>> todo;

    void DFSUtil(int v, Graph graph) {
        visited[v] = true;
        //cout << v << " ";
        for (int i = 0; i < graph.adj[v].size(); ++i) {
            int curr = graph.adj[v][i];
            if (!visited[curr]) {
                DFSUtil(curr, graph);
            }
        }
    }

    int connectedComponents(Graph graph, int V) {
        int count = 0;
        for (int v = 0; v < V; v++) {
            visited[v] = false;
        }
        for (int v = 0; v < V; v++) {
            if (visited[v] == false) {
                DFSUtil(v, graph);
                //cout << "\n";
                count ++;
            }
        }
        return count;
    }

    void addEdges(vector<vector<int>>& grid, Graph& graph) {
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size(); j ++) {
                int curr = grid[i][j];
                if (i > 0) {
                    int left = grid[i-1][j];
                    if (curr != -1 && left != -1) {
                        graph.addEdge(curr,left);
                    }
                }
                if (j > 0) {
                    int top = grid[i][j-1];
                    if (curr != -1 && top != -1) {
                        graph.addEdge(curr,top);
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> numGrid = {};
        int V = 0;
        for (int i = 0; i < grid.size(); i ++) {
            numGrid.push_back({});
            for (int j = 0; j < grid[i].size(); j ++) {
                if (grid[i][j] == '1') {
                    numGrid[i].push_back(V);
                    V++;
                } else {
                    numGrid[i].push_back(-1);
                }
            }
        }
        Graph graph = Graph(V);
        addEdges(numGrid, graph);
        return connectedComponents(graph, V);
    }

    int numIslands2(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0; 
        int islands = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    BFS(grid, i, j, m, n);
                }
            }
        }
        return islands;
    }

    void BFS (vector<vector<char>>& grid, int i, int j, int m, int n) {
        int offsets[] = {0, 1, 0, -1, 0};
        todo.push({i, j});
        while (!todo.empty()) {
            pair<int, int> p = todo.front();
            todo.pop();
            for (int k = 0; k < 4; k++) {
                int r = p.first + offsets[k];
                int c = p.second + offsets[k + 1];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                    grid[r][c] = '0';
                    todo.push({r, c});
                }
            }
        }
    }
};

int main () {
    vector<vector<char>> grid = {{'1','1','1','1','1','0','1','1','1','1'},
                                 {'1','0','1','0','1','1','1','1','1','1'},
                                 {'0','1','1','1','0','1','1','1','1','1'},
                                 {'1','1','0','1','1','0','0','0','0','1'},
                                 {'1','0','1','0','1','0','0','1','0','1'},
                                 {'1','0','0','1','1','1','0','1','0','0'},
                                 {'0','0','1','0','0','1','1','1','1','0'},
                                 {'1','0','1','1','1','0','0','1','1','1'},
                                 {'1','1','1','1','1','1','1','1','0','1'},
                                 {'1','0','1','1','1','1','1','1','1','0'}};
    Solution solution;
    cout << solution.numIslands2(grid);
}
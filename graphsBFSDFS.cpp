#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
using namespace std;

const int N = 1e5 + 2; // Added 'int' for the data type

bool vis2[N];

class Graph {
public:
    unordered_map<int, list<int>> adj;
    void insert(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void print() {
        for (auto i : adj) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void bfs(int source) {
        bool vis1[N];
        for (int i = 0; i < N; i++) {
            vis1[i] = 0;
        }
        queue<int> q;
        q.push(source);
        vis1[source] = 1;
        while (!q.empty()) { 
            int node = q.front();
            q.pop();
            cout << node << " ";
            list<int>::iterator itr;
            for (itr = adj[node].begin(); itr != adj[node].end(); itr++) {
                if (!vis1[*itr]) {
                    vis1[*itr] = 1;
                    q.push(*itr);
                }
            }
        }
    }

    void fordfs(int source){
        for (int i=0; i<N; i++){
            vis2[i] = 0;
        }
        dfs(source);
    }

    void dfs(int node){
        vis2[node] = 1;
        cout << node << " ";
        list<int>::iterator itr;
        for (itr = adj[node].begin(); itr != adj[node].end(); itr++){
            if (!vis2[*itr]){
                dfs(*itr);
            }
        }
    }
};

int main() {
    Graph g;
    int m,n;
    cout << "Enter number of nodes: " << endl;
    cin >> n;
    cout << "Enter number of edges: " << endl;
    cin >> m;    
    int x,y;
    for (int i=0; i<m; i++){
        cin >> x >> y;
        g.insert(x,y,0); 
    }
    g.bfs(0);
    cout << endl;
    g.fordfs(0);
    return 0;
}

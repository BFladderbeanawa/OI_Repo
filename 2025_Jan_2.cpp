#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

struct DisjointSet {
    vector<int> parent, rank, size;

    DisjointSet(int n) : parent(n), rank(n, 0), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]); // 路径压缩
    }

    void unite(int u, int v, int& current_pairs) {
        int root_u = find(u), root_v = find(v);
        if (root_u != root_v) {
            current_pairs -= size[root_u] * (size[root_u] - 1) / 2;
            current_pairs -= size[root_v] * (size[root_v] - 1) / 2;
            if (rank[root_u] < rank[root_v]) swap(root_u, root_v); // 按秩合并
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
            current_pairs += size[root_u] * (size[root_u] - 1) / 2;
            if (rank[root_u] == rank[root_v]) rank[root_u]++;
        }
    }

    int getSize(int u) {
        return size[find(u)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    vector<set<int>> adj(n); // 使用 set 存储邻接表
    for (const auto& edge : edges) {
        adj[edge.first].insert(edge.second);
        adj[edge.second].insert(edge.first);
    }

    vector<int> ans(n);
    vector<bool> removed(n, false);
    int current_pairs = 0;
    DisjointSet ds(n);

    for (int t = 0; t < n; ++t) {
        if (s[t] == '1') {
            vector<int> neighbors;
            for (int neighbor : adj[t]) {
                if (!removed[neighbor]) {
                    neighbors.push_back(neighbor);
                }
            }
            int num_neighbors = neighbors.size();
            for (int i = 0; i < num_neighbors; ++i) {
                for (int j = i + 1; j < num_neighbors; ++j) {
                     if(!adj[neighbors[i]].count(neighbors[j])){
                        adj[neighbors[i]].insert(neighbors[j]);
                        adj[neighbors[j]].insert(neighbors[i]);
                    }
                }
            }
        }
        
        removed[t] = true;

        ds = DisjointSet(n);
        current_pairs = 0;
        for (int u = 0; u < n; ++u) {
            if (!removed[u]) {
                for (int v : adj[u]) {
                    if (!removed[v] && u < v) {
                        ds.unite(u, v, current_pairs);
                    }
                }
            }
        }
        ans[t] = current_pairs;
    }

    for (int x : ans) {
        cout << x << endl;
    }

    return 0;
}
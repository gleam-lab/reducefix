#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int deg[MAXN], heap[MAXN * 2];

void push(int &heap_size, int val) {
    heap[++heap_size] = val;
    for(int i = heap_size; i > 1 && heap[i] > heap[i >> 1]; i >>= 1)
        swap(heap[i], heap[i >> 1]);
}

int pop(int &heap_size) {
    if(heap_size == 0) return -1;
    int top = heap[1];
    heap[1] = heap[heap_size--];
    for(int i = 1; (i << 1) <= heap_size;) {
        int child = (i << 1);
        if(child < heap_size && heap[child] < heap[child + 1]) ++child;
        if(heap[i] >= heap[child]) break;
        swap(heap[i], heap[child]);
        i = child;
    }
    return top;
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++deg[u];
    ++deg[v];
}

void dfs(int u, int p, vector<vector<int>> &res) {
    res[u].resize(min(10, deg[u]));
    iota(res[u].begin(), res[u].end(), 1);
    sort(res[u].begin(), res[u].end());
    for(auto v : adj[u])
        if(v != p) {
            dfs(v, u, res);
            for(int i = min(10, deg[v]); i >= 1; --i) {
                while(!heap[i] || heap[i] < res[v][i - 1]) {
                    int t = pop(i);
                    if(t == -1) break;
                    push(i, t);
                }
                push(i, res[v][i - 1]);
            }
            while(heap[i]) {
                res[u].push_back(pop(i));
                if(res[u].size() == 10) break;
            }
        }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }

    vector<vector<int>> res(n + 1);
    dfs(1, -1, res);

    for(int i = 1; i <= q; ++i) {
        int type; cin >> type;
        if(type == 1) {
            int u, v; cin >> u >> v;
            addEdge(u, v);
            dfs(1, -1, res);
        } else {
            int v, k; cin >> v >> k;
            cout << res[v][k - 1] << '\n';
        }
    }

    return 0;
}
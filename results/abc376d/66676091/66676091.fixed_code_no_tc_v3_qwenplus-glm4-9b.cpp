#include<bits/stdc++.h>
using namespace std;

template<typename T> bool chmin(T &m, const T q) {
    if (m > q) {m = q; return true;} else return false;
}

template<typename T> bool chmax(T &m, const T q) {
    if (m < q) {m = q; return true;} else return false;
}

#define rep(i, l, r) for (int i = l; i < r; i++)
#define all(x) x.begin(), x.end()
#define el '\n'
#define spa " "
#define Yes cout << "YES" << el
#define No cout << "NO" << el
#define cou(i) cout << i << endl;
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

const int MAX = 1e5 + 10;

int main() {
    int N, M;
    cin >> N >> M;
    vvi G(N);
    vi dist(N, INT_MAX);
    dist[0] = 0;  // Start from node 0, distance to itself is 0

    rep(i, 0, M) {
        int s, v;
        cin >> s >> v;
        G[s].push_back(v);
    }

    // BFS to find the distance to the furthest node from node 0
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int node = que.front();
        que.pop();

        for (int child : G[node]) {
            if (dist[child] == INT_MAX) {
                dist[child] = dist[node] + 1;
                que.push(child);
            }
        }
    }

    // Find the maximum distance
    int max_dist = 0;
    for (int i = 0; i < N; i++) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
        }
    }

    if (max_dist == 0) {  // If the start node is isolated
        No;
    } else {
        cout << max_dist << el;
    }

    return 0;
}
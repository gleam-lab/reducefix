#include<bits/stdc++.h>
using namespace std;

template<typename T> bool chmax(T &m, const T q) {
    if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) {
    if (m > q) {m = q; return true;} else return false;
}

#define rep(i, l, r) for(int i=(l); i<(r); ++i)
#define all(x) x.begin(), x.end()
#define el '\n'
#define spa " "
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define cou(i) cout << i << el;
#define rrep(i, l, r) for(int i=(r); i>=(l); --i)
#define pb push_back
using pqi = priority_queue<int>;
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;

const long long INF = 1e18;
const int mod = 1e9+7;
const int MAX = 1e5+10;

int main() {
    int N, M;
    cin >> N >> M;
    vi dist(N, 1e9);  // Use a large initial value for dist
    dist[0] = 0;
    vi adj[N];
    
    for (int i = 0; i < M; ++i) {
        int s, v;
        cin >> s >> v;
        s--; v--;
        adj[s].push_back(v);
    }
    
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    int minDist = INF;
    for (int i = 0; i < N; ++i) {
        if (i != 0 && dist[i] < minDist) {
            minDist = dist[i];
        }
    }
    
    if (minDist == INF) {
        cout << -1 << el;
    } else {
        cout << minDist - 1 << el;  // Subtract 1 for the zero-based index
    }
    
    return 0;
}
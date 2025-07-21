#include <bits/stdc++.h>
using namespace std;

template<typename T> bool chmax(T &m, const T q) {
    if (m < q) { m = q; return true; } return false;
}

template<typename T> bool chmin(T &m, const T q) {
    if (m > q) { m = q; return true; } return false;
}

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define rrep(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa " "
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define pb push_back

using pqgi = priority_queue<int, vector<int>, greater<int>>;
using pqi = priority_queue<int>;
using pii = pair<int, int>;
using ll = long long;
using vs = vector<string>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvpii = vector<vector<pii>>;
using vpii = vector<pair<int, int>>;
using vtiii = vector<tuple<int, int, int>>;
using vvs = vector<vector<string>>;
const long long INF = 1e18;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 10;
const int MIN = -1e9;

int main() {
    int N, M;
    cin >> N >> M;
    vvi G(N);
    rep(i, 0, M) {
        int s, v;
        cin >> s >> v;
        s--; v--;
        G[s].pb(v);
    }

    // To find the shortest cycle length starting and ending at node 0
    int min_cycle = INT_MAX;
    vi dist(N, -1);  // Distance from node 0 to each node

    queue<int> que;
    que.push(0);
    dist[0] = 0;

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (auto v : G[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                que.push(v);
            } else if (v == 0 && dist[u] >= 0) {
                // Found a cycle back to 0
                chmin(min_cycle, dist[u] + 1);
            }
        }
    }

    if (min_cycle != INT_MAX)
        cout << min_cycle << el;
    else
        cout << -1 << el;

    return 0;
}
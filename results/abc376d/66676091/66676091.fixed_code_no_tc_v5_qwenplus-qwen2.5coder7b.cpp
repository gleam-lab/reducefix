#include<bits/stdc++.h>
using namespace std;

template<typename T> bool chmax(T &m, const T q) {
    if (m < q) { m = q; return true; } else return false;
}

template<typename T> bool chmin(T &m, const T q) {
    if (m > q) { m = q; return true; } else return false;
}

#define rep(i, l, r) for(int i = (l); (r) > i; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa " "
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define cou(i) cout << i << endl;
#define rrep(i, l, r) for(int i = (r); i >= (l); i--)
#define pb push_back
using pqgi = priority_queue<int, vector<int>, greater<int>>;
using pqi = priority_queue<int>;
using pii = pair<int, int>;
using ll = long long;
using vs = vector<string>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long long>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
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
    int N, M, len = INT_MAX;
    cin >> N >> M;
    vvi G(N);
    vi dist(N, INF); // Initialize distance to infinity
    rep(i, 0, M) {
        int s, v;
        cin >> s >> v;
        s--; v--;
        G[s].pb(v);
    }
    vb vis(N, false);
    dist[0] = 0; // Distance from source to itself is 0
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int pos = que.front();
        que.pop();
        if (vis[pos]) continue;
        vis[pos] = true;
        for (auto to : G[pos]) {
            if (!vis[to]) {
                que.push(to);
                dist[to] = dist[pos] + 1;
            } else if (to == 0 && dist[pos] + 1 < dist[to]) {
                chmin(len, dist[pos] + 1);
            }
        }
    }
    if (len != INT_MAX) cout << len << endl;
    else cout << -1 << el;
    return 0;
}
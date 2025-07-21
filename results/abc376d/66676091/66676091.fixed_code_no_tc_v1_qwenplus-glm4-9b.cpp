#include<bits/stdc++.h>
using namespace std;

template<typename T> bool chmax(T &m, const T q) {
    if (m < q) {m = q; return true;} 
    return false;
}

template<typename T> bool chmin(T &m, const T q) {
    if (m > q) {m = q; return true;}
    return false;
}

#define rep(i,l,r) for(int i=(l); i<(r); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa " "
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define cou(i) cout << i << endl;
#define rrep(i,l,r) for(int i=(r); i>=(l); i--)
#define pb push_back
using pqgi=priority_queue<int,vector<int>,greater<int>>;
using pqi=priority_queue<int>;
using pii=pair<int,int>;
using ll=long long;
using vs=vector<string>;
using vi=vector<int>;
using vb=vector<bool>;
using vl=vector<long long>;
using vc=vector<char>;
using vvi=vector<vector<int>>;
using vvl=vector<vector<long long>>;
using vvc=vector<vector<char>>;
using vvb=vector<vector<bool>>;
using vvpii=vector<vector<pii>>;
using vpii=vector<pair<int,int>>;
using vtiii=vector<tuple<int,int,int>>;
using vvs=vector<vector<string>>;
const long long INF=1e18;
const int mod=1e9+7;
const int MAX=1e5+10;
const int MIN=-1e9;

int main() {
    int N, M, src, dest;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vi dist(N, 0);
    rep(i, 0, M) {
        cin >> src >> dest;
        src--; dest--;
        G[src].emplace_back(dest);
    }
    
    vb vis(N, false);
    queue<int> que;
    que.push(0);
    dist[0] = 1;  // Start from node 0, distance to itself is 0
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        if (vis[node]) continue;
        vis[node] = true;
        for (int adj : G[node]) {
            if (!vis[adj]) {
                que.push(adj);
                dist[adj] = dist[node] + 1;
            }
        }
    }
    
    int minLen = INF;
    for (int i = 1; i < N; i++) {
        if (dist[i] < minLen && dist[i] > 0) {
            minLen = dist[i];
        }
    }
    
    if (minLen == INF) cout << -1 << el;
    else cout << minLen << el;
}
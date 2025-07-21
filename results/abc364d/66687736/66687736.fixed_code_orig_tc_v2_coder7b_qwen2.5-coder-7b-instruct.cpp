#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

vector<vector<pair<ll, ll>>> buildDistanceGraph(const vector<ll>& a, const vector<ll>& b) {
    int n = a.size();
    int q = b.size();
    vector<vector<pair<ll, ll>>> graph(q);
    
    rep(j, q) {
        ll bj = b[j];
        rep(i, n) {
            ll ai = a[i];
            ll dist = abs(ai - bj);
            graph[j].emplace_back(dist, i);
        }
    }
    
    return graph;
}

vector<ll> findKthNearest(const vector<vector<pair<ll, ll>>>& graph, const vector<ll>& k) {
    int q = graph.size();
    vector<ll> result(q);
    
    rep(j, q) {
        int kj = k[j] - 1;
        nth_element(graph[j].begin(), graph[j].begin() + kj, graph[j].end());
        result[j] = graph[j][kj].first;
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    vector<ll> b(q), k(q);
    rep(j, q) {
        cin >> b[j] >> k[j];
    }
    
    auto graph = buildDistanceGraph(a, b);
    auto results = findKthNearest(graph, k);
    
    rep(j, q) cout << results[j] << '\n';
    
    return 0;
}
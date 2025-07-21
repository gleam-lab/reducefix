#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

const int MAX = 1e8 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n), dist(n);
    set<pair<int, int>> s;
    
    rep(i, n) {
        cin >> a[i];
        s.insert({a[i], i});
    }
    
    rep(i, q) {
        int b, k;
        cin >> b >> k;
        for (auto it = s.begin(); it != s.end(); ++it) {
            dist[it->second] = abs(it->first - b);
        }
        sort(dist.begin(), dist.end());
        cout << dist[k - 1] << '\n';
    }
    
    return 0;
}
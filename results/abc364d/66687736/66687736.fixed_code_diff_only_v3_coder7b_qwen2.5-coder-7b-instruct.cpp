#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

int main() {
    int n, q; cin >> n >> q;
    
    vi a(n), dist(n);
    rep(i, n) cin >> a[i];
    
    rep(j, q) {
        int b, k; cin >> b >> k;
        
        rep(i, n) dist[i] = abs(a[i] - b);
        
        sort(dist.begin(), dist.end());
        
        cout << dist[k-1] << '\n';
    }
    
    return 0;
}
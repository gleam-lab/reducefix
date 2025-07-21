#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;

vector<ll> a(MAXN);

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<ll> b(q);
    vector<int> k(q);
    
    for(int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }
    
    for(int i = 0; i < q; ++i) {
        vector<ll> dist(n);
        
        for(int j = 1; j <= n; ++j) {
            dist[j-1] = abs(a[j] - b[i]);
        }
        
        sort(dist.begin(), dist.end());
        
        cout << dist[k[i]-1] << endl;
    }
    
    return 0;
}
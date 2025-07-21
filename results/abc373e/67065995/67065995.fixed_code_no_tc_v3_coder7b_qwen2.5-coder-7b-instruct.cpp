#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
    
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        int rank = i + 1;
        if(rank <= m) continue; // Already won or tied for win
        
        ll need = 0;
        for(int j = 0; j < n; ++j) {
            if(j == i) continue;
            need += max(0LL, a[j] + need - a[i]);
        }
        
        if(need <= k) {
            ans[i] = need;
        } else {
            ans[i] = -1;
        }
    }
    
    for(auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}
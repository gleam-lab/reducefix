#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Calculate the maximum votes needed to ensure at least one candidate has more votes than others
    ll max_needed = 0;
    for(int i=0; i<m; i++) {
        max_needed += a[i];
    }
    
    vector<ll> ans(n, -1);
    for(int i=0; i<n; i++) {
        if(a[i] >= max_needed) {
            ans[i] = 0;
        } else {
            ans[i] = max_needed - a[i];
        }
    }

    for(auto i : ans) cout << i << ' ';
    return 0;
}
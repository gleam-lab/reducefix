#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    
    for(int i = 0; i < q; i++) {
        ll b, k;
        cin >> b >> k;
        
        // Calculate the range within which b falls
        int idx = lower_bound(a.begin(), a.end(), b) - a.begin();
        int cnt = idx + 1;
        
        // If b is exactly at an element, adjust the index
        if(cnt == n || a[cnt] != b) {
            cnt--;
        }
        
        // Calculate the k-th closest element
        if(k <= cnt) {
            cout << b - a[k - 1] << endl;
        } else {
            cout << a[k - 1] - b << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for(int i = 0; i < q; ++i) {
        ll b, k;
        cin >> b >> k;
        
        auto it = lower_bound(a.begin(), a.end(), b);
        int index = it - a.begin();
        
        ll left = 0, right = 0;
        
        if(index > 0) left = abs(a[index - 1] - b);
        if(index < n) right = abs(a[index] - b);
        
        if(k == 1 && left != 0) {
            cout << left << '\n';
            continue;
        }
        
        if(k == n && right != 0) {
            cout << right << '\n';
            continue;
        }
        
        if(left != 0 && right != 0) {
            if(k <= index) {
                cout << left << '\n';
            } else {
                cout << right << '\n';
            }
        } else if(left != 0) {
            cout << left << '\n';
        } else {
            cout << right << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}
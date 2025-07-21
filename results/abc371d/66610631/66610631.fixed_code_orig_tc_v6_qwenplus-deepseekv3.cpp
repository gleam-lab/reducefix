#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<ll> prefix(n + 1, 0);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        prefix[i + 1] = prefix[i] + b[i];
    }
    
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        
        auto left_it = lower_bound(a.begin(), a.end(), l);
        auto right_it = upper_bound(a.begin(), a.end(), r);
        
        int left_idx = left_it - a.begin();
        int right_idx = right_it - a.begin();
        
        ll sum = prefix[right_idx] - prefix[left_idx];
        cout << sum << '\n';
    }
    
    return 0;
}
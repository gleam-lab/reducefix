#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    
    vector<ll> x(n + 2), p(n + 2);
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    
    // Sort positions and update prefix sums accordingly
    vector<pair<ll, ll>> pos_p(n);
    for(int i = 1; i <= n; ++i) {
        pos_p[i-1] = {x[i], p[i]};
    }
    sort(pos_p.begin(), pos_p.end());
    for(int i = 1; i <= n; ++i) {
        x[i] = pos_p[i-1].first;
        p[i] = pos_p[i-1].second;
        p[i] += p[i-1];  // build prefix sum
    }
    
    cin >> q;
    while(q--) {
        ll L, R;
        cin >> L >> R;
        
        // Find left and right indices using binary search
        int l = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.data();
        int r = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.data();
        r--;

        if(l > r) {
            cout << 0 << '\n';
        } else {
            cout << (p[r] - p[l-1]) << '\n';
        }
    }

    return 0;
}
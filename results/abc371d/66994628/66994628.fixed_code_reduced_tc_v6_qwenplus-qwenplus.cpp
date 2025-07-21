#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, q;
    cin >> n;
    
    vector<ll> x(n + 2), p(n + 2);
    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    
    // Create prefix sum of p
    vector<ll> sum(n + 2, 0);
    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        ll L, R;
        cin >> L >> R;
        
        // Find leftmost index where x[i] >= L
        int l = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();
        
        // Find rightmost index where x[i] <= R
        int r = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin() - 1;
        
        if (l > r) {
            cout << 0 << endl;
        } else {
            cout << sum[r] - sum[l - 1] << endl;
        }
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on the answer (distance)
        ll left = 0, right = 2e16; // Sufficiently large upper bound
        ll ans = right;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Count points in [b-mid, b+mid]
            ll low = b - mid;
            ll high = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low);
            auto it2 = upper_bound(a.begin(), a.end(), high);
            int count = it2 - it1;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
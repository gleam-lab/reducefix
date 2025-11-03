#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search and lower/upper bound operations
    sort(a.begin(), a.end());
    
    for (int j = 0; j < Q; j++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on the distance d
        ll left = 0, right = 2e8;
        ll ans = right;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            // Count how many points in A are within distance 'mid' from B_j
            ll low = b - mid;
            ll high = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low);
            auto it2 = upper_bound(a.begin(), a.end(), high);
            int cnt = distance(it1, it2);
            
            if (cnt >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
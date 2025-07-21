#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    // Sort the A array for binary search purposes
    sort(a.begin(), a.end());
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on distance
        ll left = 0, right = 2e8 + 1; // max possible distance is ~2*1e8
        
        while (left < right) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance <= mid from b
            int count = 0;
            int l = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int r = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
            count = r - l;
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    return 0;
}
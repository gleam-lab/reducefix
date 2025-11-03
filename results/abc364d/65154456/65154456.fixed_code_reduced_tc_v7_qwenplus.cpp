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
    sort(a.begin(), a.end());
    
    for (int q = 0; q < Q; q++) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-indexed k-th smallest distance
        
        // Binary search on the answer (distance)
        ll left = -1;
        ll right = 2e8 + 1;
        
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance `mid` from B
            auto low = lower_bound(a.begin(), a.end(), b - mid);
            auto high = upper_bound(a.begin(), a.end(), b + mid);
            int count = high - low;
            
            if (count > k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        cout << right << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
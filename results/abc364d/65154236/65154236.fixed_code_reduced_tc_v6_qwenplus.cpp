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
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    for (int j = 0; j < Q; j++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // We want to find the k-th smallest distance from b to any a[i]
        // Use binary search on the answer (distance)
        ll left = 0, right = 2e8;
        while (left < right) {
            ll mid = (left + right) / 2;
            
            // Count how many points in a are within distance `mid` from b
            // That is: b - mid <= a[i] <= b + mid
            auto low = lower_bound(a.begin(), a.end(), b - mid);
            auto high = upper_bound(a.begin(), a.end(), b + mid);
            int count = high - low;
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
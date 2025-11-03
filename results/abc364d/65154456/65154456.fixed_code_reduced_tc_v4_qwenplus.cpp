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
    
    // Sort the A points for binary search and distance computation
    sort(a.begin(), a.end());
    
    for (int q = 0; q < Q; q++) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // Convert to 0-indexed: we want the k-th smallest distance (k-1 in zero-index)

        // Binary search on the answer (distance)
        ll left = 0, right = 2e8;
        while (left < right) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance `mid` from B
            ll low_bound = b - mid;
            ll high_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
            int count = distance(it1, it2);
            
            if (count >= k + 1) { // We need at least k+1 points within this distance
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
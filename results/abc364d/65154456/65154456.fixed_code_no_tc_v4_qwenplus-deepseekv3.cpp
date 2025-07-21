#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        int left = 0, right = N - 1;
        int res = 0;
        
        // Binary search to find the k-th closest point
        // We can find the smallest distance such that there are at least k points <= b + distance
        // and at least (N - k + 1) points >= b - distance
        
        ll low = 0, high = 2e14;
        ll answer = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            
            // Count number of points in [b - mid, b + mid]
            auto it_low = lower_bound(A.begin(), A.end(), b - mid);
            auto it_high = upper_bound(A.begin(), A.end(), b + mid);
            int count = it_high - it_low;
            
            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Now, find the k-th smallest distance
        vector<ll> distances;
        auto it_low = lower_bound(A.begin(), A.end(), b - answer);
        auto it_high = upper_bound(A.begin(), A.end(), b + answer);
        for (auto it = it_low; it != it_high; ++it) {
            distances.push_back(abs(b - *it));
        }
        sort(distances.begin(), distances.end());
        
        cout << distances[k - 1] << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
        k--; // Convert to 0-based index
        
        // Binary search to find the k-th smallest distance
        ll left = 0;
        ll right = 2e18;
        ll answer = 0;
        
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            
            // Count the number of elements in A with |A_i - b| <= mid
            ll low = b - mid;
            ll high = b + mid;
            auto lower = lower_bound(A.begin(), A.end(), low);
            auto upper = upper_bound(A.begin(), A.end(), high);
            int count = upper - lower;
            
            if (count <= k) {
                left = mid + 1;
            } else {
                answer = mid;
                right = mid - 1;
            }
        }
        
        // Now, find the exact k-th smallest distance
        vector<ll> distances;
        ll low_bound = b - answer;
        ll high_bound = b + answer;
        auto lower = lower_bound(A.begin(), A.end(), low_bound);
        auto upper = upper_bound(A.begin(), A.end(), high_bound);
        
        for (auto it = lower; it != upper; ++it) {
            distances.push_back(abs(*it - b));
        }
        sort(distances.begin(), distances.end());
        
        cout << distances[k] << '\n';
    }
    
    return 0;
}
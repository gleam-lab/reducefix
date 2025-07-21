#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
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
        k--; // convert to 0-based index
        
        int left = 0, right = N - 1;
        ll res = 0;
        
        // Binary search to find the k-th closest element
        // We need to find the k-th element in the sorted list of distances
        // The distances are |A[i] - b|, sorted
        
        // Using a priority queue to find the k-th smallest distance
        // But with N and Q up to 1e5, O(Q * N log N) is too slow
        
        // Alternative approach: binary search the answer (the distance)
        // For a given distance d, count the number of elements in A with |A[i] - b| <= d
        // Binary search d to find the minimal d such that count >= k + 1
        
        ll low = 0, high = 2e14;
        while (low < high) {
            ll mid = (low + high) / 2;
            
            // Count the number of A[i] <= b + mid and >= b - mid
            ll left_val = b - mid;
            ll right_val = b + mid;
            
            auto it_left = lower_bound(A.begin(), A.end(), left_val);
            auto it_right = upper_bound(A.begin(), A.end(), right_val);
            int count = it_right - it_left;
            
            if (count <= k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        // Now, find the k-th smallest distance
        // The distances around low can be up to low
        // So collect all elements with distance <= low, sorted by distance
        vector<ll> candidates;
        ll target_d = low;
        
        auto it_left = lower_bound(A.begin(), A.end(), b - target_d);
        auto it_right = upper_bound(A.begin(), A.end(), b + target_d);
        
        for (auto it = it_left; it != it_right; ++it) {
            candidates.push_back(abs(*it - b));
        }
        
        sort(candidates.begin(), candidates.end());
        
        cout << candidates[k] << '\n';
    }
    
    return 0;
}
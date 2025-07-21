#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    vector<int> original_indices(N);
    for (int i = 0; i < N; ++i) original_indices[i] = i;
    
    sort(original_indices.begin(), original_indices.end(), [&](int i, int j) {
        return A[i] > A[j];
    });
    
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) sorted_A[i] = A[original_indices[i]];
    
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) prefix[i + 1] = prefix[i] + sorted_A[i];
    
    vector<ll> res(N, -1);
    ll remaining_votes = K - prefix[N];
    
    for (int i = 0; i < N; ++i) {
        int original_idx = original_indices[i];
        ll current_votes = sorted_A[i];
        
        // Binary search for the minimum X such that the number of candidates with > current_votes + X is < M
        ll low = 0, high = remaining_votes + (prefix[N] - prefix[i + 1]);
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current_votes + mid;
            
            // Find the first index in sorted_A where sorted_A[j] > new_votes
            // Since sorted_A is sorted in descending order, we can use upper_bound with greater<ll>
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes, greater<ll>());
            int count = it - sorted_A.begin();
            
            if (count < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (best_X != -1 && best_X <= remaining_votes + (prefix[N] - prefix[i + 1])) {
            res[original_idx] = best_X;
        } else {
            res[original_idx] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}
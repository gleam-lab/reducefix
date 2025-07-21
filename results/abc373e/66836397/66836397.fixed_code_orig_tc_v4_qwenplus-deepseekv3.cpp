#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) cin >> a;
    
    ll total_votes = accumulate(A.begin(), A.end(), 0LL);
    ll remaining = K - total_votes;
    
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<ll>());
    
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }
    
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = remaining;
        ll answer = -1;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll new_votes = current + mid;
            
            // Find the number of candidates with votes > new_votes
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes, greater<ll>());
            ll count = it - sorted_A.begin();
            
            if (count < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Check if the candidate is already elected without any additional votes
        auto it = upper_bound(sorted_A.begin(), sorted_A.end(), current, greater<ll>());
        ll count = it - sorted_A.begin();
        if (count < M) {
            answer = 0;
        }
        
        // If it's impossible to be elected even with all remaining votes
        if (answer == -1) {
            ll new_votes = current + remaining;
            it = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes, greater<ll>());
            count = it - sorted_A.begin();
            if (count < M) {
                answer = remaining;
            }
        }
        
        cout << answer << (i == N - 1 ? "\n" : " ");
    }
    
    return 0;
}
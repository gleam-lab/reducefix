#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M, K;
    cin >> N >> M >> K;
    
    vector<ll> A(N);
    ll rem = K;
    for (ll &a : A) {
        cin >> a;
        rem -= a;
    }
    
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = rem;
        ll ans = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            
            // Find the position of new_votes in the sorted array
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes);
            ll pos = it - sorted_A.begin();
            ll cnt_greater = N - pos;
            
            if (cnt_greater < M) {
                // We need to ensure that after giving mid votes, the candidate is among the top M
                // Now, check if the remaining votes can be distributed without others surpassing
                ll remaining_votes = rem - mid;
                
                // The candidates that can potentially surpass new_votes are those >= pos
                // We need to ensure that no more than (M - 1) candidates can get >= new_votes + 1
                // So the total votes given to these candidates should be limited
                ll max_possible = (new_votes + 1) * (N - pos) - (prefix[N] - prefix[pos]);
                if (remaining_votes < max_possible) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << " \n"[i == N - 1];
    }
    
    return 0;
}
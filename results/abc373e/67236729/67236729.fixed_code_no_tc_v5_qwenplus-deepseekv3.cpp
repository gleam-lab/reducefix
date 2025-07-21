#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M, K;
    cin >> N >> M >> K;
    
    vector<ll> A(N);
    for (ll &a : A) cin >> a;
    
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<ll>());
    
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; i++) {
        prefix[i+1] = prefix[i] + sorted_A[i];
    }
    
    ll remaining = K - accumulate(A.begin(), A.end(), 0LL);
    
    for (ll a : A) {
        // Binary search for minimum X
        ll low = 0, high = remaining, ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = a + mid;
            
            // Find how many candidates would have strictly more votes than total
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), total, greater<ll>());
            ll count = distance(sorted_A.begin(), it);
            
            if (count < M) {
                // Already satisfies condition
                ans = mid;
                high = mid - 1;
                continue;
            }
            
            // Need to make sure at most M-1 candidates have > total votes
            // The top (M-1) candidates must be <= total
            ll needed = 0;
            
            // The first M-1 candidates that are > total need to be reduced to total
            ll sum_top = prefix[M-1];
            ll new_sum = (M-1) * total;
            needed = max(0LL, sum_top - new_sum);
            
            // Also need to consider if 'a' is among the top M-1 or not
            if (count >= M) {
                // We need to reduce M candidates to <= total
                ll sum_top_M = prefix[M];
                ll new_sum_M = M * total;
                needed = max(0LL, sum_top_M - new_sum_M);
            }
            
            if (needed <= remaining - mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << ' ';
    }
    
    return 0;
}
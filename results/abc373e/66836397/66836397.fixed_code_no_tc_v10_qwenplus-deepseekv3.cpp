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
    
    ll remaining = K;
    for (ll a : A) remaining -= a;
    
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i];
    
    for (int i = 0; i < N; ++i) {
        ll a = A[i];
        ll low = 0, high = remaining, ans = -1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = a + mid;
            
            // Find how many candidates have > total votes
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), total);
            ll count_above = distance(it, sorted_A.end());
            
            // For candidate i to be elected, count_above must be < M
            if (count_above < M) {
                ans = mid;
                high = mid - 1;
                continue;
            }
            
            // Need to ensure no more than M-1 candidates can exceed candidate i's votes
            // even if all remaining votes go to them
            ll required = 0;
            
            // The M-th candidate from the top needs to have <= total votes
            ll pos = N - M;
            ll threshold = sorted_A[pos];
            
            if (threshold <= total) {
                ans = mid;
                high = mid - 1;
                continue;
            }
            
            // Calculate how many votes needed to push threshold down
            ll needed = (threshold - total) * (M - count_above);
            ll available = remaining - mid;
            
            if (needed > available) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        
        cout << ans << " \n"[i == N - 1];
    }
    
    return 0;
}
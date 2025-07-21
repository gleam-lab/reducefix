#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }
    ll rem = K - sum;
    
    vector<ll> B = A;
    sort(B.begin(), B.end());
    vector<ll> prefix(N + 1);
    for (ll i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }
    
    for (ll i = 0; i < N; ++i) {
        ll a_i = A[i];
        ll low = 0, high = rem;
        ll ans = -1;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll new_val = a_i + mid;
            
            // Find position in sorted array
            ll pos = upper_bound(B.begin(), B.end(), new_val) - B.begin();
            ll upper_cnt = N - pos;
            
            if (upper_cnt >= M) {
                low = mid + 1;
                continue;
            }
            
            ll needed = M - 1 - upper_cnt;
            ll left = (needed >= 0) ? max(0LL, pos - needed) : pos;
            ll sum_others = prefix[pos] - prefix[left];
            
            ll required = new_val * (pos - left) - sum_others;
            if (required <= rem - mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (ans != -1) {
            // Check if already elected
            ll cnt = 0;
            for (ll j = 0; j < N; ++j) {
                if (A[j] > A[i]) cnt++;
            }
            if (cnt < M) ans = 0;
        }
        
        cout << ans << " \n"[i == N - 1];
    }
    
    return 0;
}
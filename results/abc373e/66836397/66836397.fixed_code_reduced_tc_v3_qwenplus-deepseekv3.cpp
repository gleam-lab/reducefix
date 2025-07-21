#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (ll &a : A) {
        cin >> a;
        total += a;
    }
    ll rem = K - total;
    
    vector<ll> B = A;
    sort(B.begin(), B.end());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }
    
    for (int i = 0; i < N; ++i) {
        ll a = A[i];
        ll low = 0, high = rem;
        ll ans = -1;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll new_a = a + mid;
            
            ll pos = upper_bound(B.begin(), B.end(), new_a) - B.begin();
            ll upper_cnt = N - pos;
            
            if (upper_cnt < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (ans != -1) {
            ll new_a = a + ans;
            ll pos = upper_bound(B.begin(), B.end(), new_a) - B.begin();
            ll upper_cnt = N - pos;
            if (upper_cnt >= M) {
                ans = -1;
            } else {
                ll required = 0;
                ll left = max(0LL, pos - (M - upper_cnt));
                required += (new_a + 1) * (pos - left) - (prefix[pos] - prefix[left]);
                if (required > rem - ans) {
                    ans = -1;
                }
            }
        }
        
        cout << ans << " \n"[i == N - 1];
    }
    
    return 0;
}
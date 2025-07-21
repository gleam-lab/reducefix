#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;
vector<ll> A;

int main() {
    cin >> N >> M >> K;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<ll> B = A;
    sort(B.begin(), B.end());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }
    
    ll total = prefix[N];
    ll remaining = K - total;
    
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = A[i] + mid;
            
            int idx = upper_bound(B.begin(), B.end(), new_val) - B.begin();
            int cnt = N - idx;
            
            if (cnt < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = best;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
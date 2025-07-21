#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A = A;
    sort(all(sorted_A));
    
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    vector<ll> ans(N);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0, high = K - (prefix[N] - prefix[0]) + A[i];
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;
            
            int pos = upper_bound(all(sorted_A), total) - sorted_A.begin();
            if (pos == N) {
                best = mid;
                high = mid - 1;
                continue;
            }
            
            int needed = N - pos;
            if (needed < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (best != -1) {
            ll remaining_votes = K - (prefix[N] - prefix[0]);
            if (best <= remaining_votes) {
                ans[i] = best;
            } else {
                ans[i] = -1;
            }
        } else {
            ans[i] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
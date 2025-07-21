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
    ll total = accumulate(all(A), 0LL);
    ll remaining = K - total;
    
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        int original_index = ord[i];
        ll low = 0, high = remaining;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = sorted_A[i] + mid;
            
            int pos = upper_bound(all(sorted_A), new_votes) - sorted_A.begin();
            int needed = N - pos;
            if (needed < M) {
                ll required = 0;
                if (needed > 0) {
                    int start = pos;
                    int end = N - 1;
                    required = (new_votes + 1) * (end - start + 1) - (prefix[end + 1] - prefix[start]);
                }
                if (required <= remaining - mid) {
                    best_X = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        ans[original_index] = best_X;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
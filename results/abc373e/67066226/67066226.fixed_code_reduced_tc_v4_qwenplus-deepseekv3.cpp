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
        prefix[i + 1] = sorted_A[i] + prefix[i];
    }
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        ll original = A[ord[idx]];
        ll left = 0, right = K;
        ll best_X = -1;
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll new_votes = original + mid;
            int pos = upper_bound(all(sorted_A), new_votes) - sorted_A.begin();
            int required = N - M;
            if (pos > required) {
                best_X = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (best_X != -1) {
            ll total_used = best_X;
            ll available = K;
            if (total_used <= available) {
                ans[ord[idx]] = best_X;
            } else {
                ans[ord[idx]] = -1;
            }
        } else {
            ans[ord[idx]] = -1;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
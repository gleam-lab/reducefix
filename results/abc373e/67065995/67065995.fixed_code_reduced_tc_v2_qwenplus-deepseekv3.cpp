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
    ll total_A = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_A += A[i];
    }
    ll remaining = K - total_A;
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = sorted_A[i] + mid;
            int pos = upper_bound(all(sorted_A), new_vote) - sorted_A.begin();
            int needed = N - M;
            if (pos <= needed) {
                low = mid + 1;
                continue;
            }
            ll required = new_vote * (pos - needed - 1) - (prefix[pos] - prefix[needed + 1]);
            if (required <= remaining - mid) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[ord[i]] = best_X;
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
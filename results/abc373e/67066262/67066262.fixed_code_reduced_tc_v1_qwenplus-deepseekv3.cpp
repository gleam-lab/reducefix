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
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }
    ll remaining = K - sum;
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sortedA = A;
    sort(all(sortedA));
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = sortedA[i] + prefix[i];
    }

    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0, high = remaining, res = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;
            int pos = upper_bound(all(sortedA), total) - sortedA.begin();
            if (pos >= N - M + 1) {
                res = mid;
                high = mid - 1;
                continue;
            }
            ll needed = (N - M - pos + 1) * total - (prefix[N - M + 1] - prefix[pos]);
            if (needed <= remaining - mid) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = res;
    }

    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            cout << -1 << ' ';
        } else {
            cout << ans[i] << ' ';
        }
    }
    return 0;
}
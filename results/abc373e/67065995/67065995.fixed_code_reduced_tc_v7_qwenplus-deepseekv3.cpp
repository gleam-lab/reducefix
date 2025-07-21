#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<ll> B = A;
    sort(B.begin(), B.end());
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = K - (prefix[N] - prefix[0]);
        ll res = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;
            auto it = upper_bound(B.begin(), B.end(), total);
            int cnt = B.end() - it;
            if (cnt < M) {
                res = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                int pos = it - B.begin();
                int rc = N - pos;
                if (rc >= M) {
                    needed = (B[pos + rc - M] - total) + 1;
                    if (mid + needed > K - (prefix[N] - prefix[0])) {
                        low = mid + 1;
                        continue;
                    }
                }
                low = mid + 1;
            }
        }
        ans[i] = res;
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
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

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll a = A[i];
        ll low = 0, high = K - (prefix[N] - a), ans = -1;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll total = a + mid;
            auto it = upper_bound(sortedA.begin(), sortedA.end(), total);
            int cnt = N - (it - sortedA.begin());
            if (cnt < M) {
                ll sum = 0;
                if (cnt > 0) {
                    sum = prefix[N] - prefix[N - cnt] - (total * cnt);
                }
                if (sum <= (K - (prefix[N] - a) - mid)) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        res[i] = ans;
    }

    for (ll r : res) {
        cout << r << ' ';
    }
    cout << '\n';

    return 0;
}
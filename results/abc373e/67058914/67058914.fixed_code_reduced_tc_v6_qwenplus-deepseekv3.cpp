#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll remaining = K - prefix[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), total);
            int pos = it - sorted_A.begin();

            int cnt = N - pos;
            if (total == sorted_A[pos - 1]) {
                cnt = N - pos + 1;
            }

            if (cnt < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[i] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << (res[i] == -1 ? -1 : max(0LL, res[i])) << ' ';
    }

    return 0;
}
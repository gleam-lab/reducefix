#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    ll total = prefix[N];
    ll remaining = K - total;
    if (remaining < 0) {
        remaining = 0;
    }

    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll a = A[i];
        int pos = upper_bound(sortedA.begin(), sortedA.end(), a) - sortedA.begin();

        ll low = 0, high = remaining;
        ll ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a = a + mid;
            int new_pos = upper_bound(sortedA.begin(), sortedA.end(), new_a) - sortedA.begin();

            if (new_a == sortedA.back()) {
                new_pos = N;
            } else if (new_pos < N && sortedA[new_pos] == new_a) {
                while (new_pos < N && sortedA[new_pos] == new_a) {
                    new_pos++;
                }
            }

            int cnt_above = N - new_pos;
            if (cnt_above < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (ans != -1) {
            res[i] = ans;
        } else {
            res[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}
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

    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    vector<ll> preSum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        preSum[i + 1] = preSum[i] + sortedA[i].first;
    }

    ll totalUsed = preSum[N];
    ll remaining = K - totalUsed;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current = sortedA[i].first;
        ll low = 0;
        ll high = remaining;

        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newCurrent = current + mid;

            int idx = upper_bound(sortedA.begin(), sortedA.end(), make_pair(newCurrent, N)) - sortedA.begin();

            int cnt = N - idx;
            if (cnt >= M) {
                low = mid + 1;
                continue;
            }

            ll sum = 0;
            if (idx > i) {
                sum = preSum[idx] - preSum[i + 1];
                ll needed = newCurrent * (idx - i - 1) - sum;
                if (needed <= remaining - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        res[sortedA[i].second] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}
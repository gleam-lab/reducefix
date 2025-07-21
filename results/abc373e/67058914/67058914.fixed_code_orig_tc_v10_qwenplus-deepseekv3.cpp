#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
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

    vector<ll> preSum(N + 1);
    for (int i = 0; i < N; ++i) {
        preSum[i + 1] = preSum[i] + sortedA[i].first;
    }

    ll remaining = K - preSum[N];
    if (remaining < 0) {
        remaining = 0;
    }

    vector<ll> ans(N, -1);

    for (int i = 0; i < N; ++i) {
        ll original_votes = sortedA[i].first;
        ll low = 0, high = remaining;
        ll min_x = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = original_votes + mid;

            int pos = upper_bound(sortedA.begin(), sortedA.end(), make_pair(new_votes, N)) - sortedA.begin();
            int cnt = N - pos;

            if (cnt < M) {
                min_x = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (min_x != -1) {
            ans[sortedA[i].second] = min_x;
        } else {
            ans[sortedA[i].second] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
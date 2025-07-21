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

    vector<pair<ll, int>> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = {A[i], i};
    }
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> pre_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        pre_sum[i + 1] = pre_sum[i] + sorted_A[i].first;
    }

    ll total_remaining = K - pre_sum[N];
    vector<ll> res(N, -1);

    for (int pos = 0; pos < N; ++pos) {
        ll original_votes = sorted_A[pos].first;
        int original_idx = sorted_A[pos].second;

        ll low = 0, high = total_remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = original_votes + mid;

            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(new_votes, N));
            int greater = sorted_A.end() - it;

            if (greater < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (answer != -1) {
            res[original_idx] = answer;
        } else {
            res[original_idx] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }

    return 0;
}
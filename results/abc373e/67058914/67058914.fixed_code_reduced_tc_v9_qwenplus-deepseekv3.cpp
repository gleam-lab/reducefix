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

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i].first;
    }

    ll total_used = prefix_sum[N];
    ll remaining = K - total_used;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current_votes = sorted_A[i].first;
        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current_votes + mid;

            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(new_votes, N)) - sorted_A.begin();
            int over = N - pos;

            if (over < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[sorted_A[i].second] = answer;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }

    return 0;
}
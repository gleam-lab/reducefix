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
    sort(sorted_A.begin(), sorted_A.end(), greater<ll>());

    vector<ll> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    ll total_votes = accumulate(A.begin(), A.end(), 0LL);
    ll remaining_votes = K - total_votes;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current_votes = A[i];
        ll low = 0;
        ll high = remaining_votes;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current_votes + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes, greater<ll>()) - sorted_A.begin();

            if (pos < M) {
                answer = mid;
                high = mid - 1;
            } else {
                ll sum_needed = 0;
                int cnt = pos - (sorted_A[pos - 1] == new_votes ? 1 : 0);
                if (cnt >= M) {
                    low = mid + 1;
                    continue;
                }
                int start = M - 1;
                if (start >= N) {
                    start = N - 1;
                }
                sum_needed = new_votes * (start + 1 - cnt) - (prefix_sum[start + 1] - prefix_sum[cnt]);
                if (sum_needed <= remaining_votes - mid) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        if (answer != -1 && answer <= remaining_votes) {
            res[i] = answer;
        } else {
            res[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }

    return 0;
}
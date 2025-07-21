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

    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&A](int i, int j) {
        return A[i] > A[j];
    });

    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[indices[i]];
    }

    vector<ll> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    ll total_used = prefix_sum[N];
    ll remaining = K - total_used;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        int rank_upper = i + 1;
        if (rank_upper <= M) {
            res[indices[i]] = 0;
            continue;
        }

        ll low = 0, high = remaining;
        ll answer = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = sorted_A[i] + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes, greater<ll>()) - sorted_A.begin();
            if (pos < M) {
                answer = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                if (pos > M) {
                    needed = new_votes * (pos - M) - (prefix_sum[pos] - prefix_sum[M]);
                }
                if (needed <= remaining - mid) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        res[indices[i]] = answer;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}
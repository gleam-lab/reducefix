#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
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

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll total_votes = prefix[N];
    ll remaining_votes = K - total_votes;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = remaining_votes;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_current = current + mid;

            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_current, greater<ll>()) - sorted_A.begin();
            ll sum = 0;

            if (pos > 0) {
                sum = prefix[pos];
                if (sorted_A[pos - 1] == new_current) {
                    sum -= sorted_A[pos - 1];
                    pos--;
                }
            }

            ll worst_case = (N - pos) + (mid > 0 ? 0 : 0);

            if (new_current == 0) {
                worst_case = N;
            } else {
                int equal_or_less = lower_bound(sorted_A.begin(), sorted_A.end(), new_current, greater<ll>()) - sorted_A.begin();
                int equal = upper_bound(sorted_A.begin(), sorted_A.end(), new_current, greater<ll>()) - sorted_A.begin();
                int more = equal_or_less;
                int less_or_equal = N - more;

                if (sorted_A[more - 1] == new_current) {
                    more--;
                }

                worst_case = more;
            }

            if (worst_case < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[i] = answer;
    }

    for (int i = 0; i < N; ++i) {
        if (res[i] == -1) {
            ll new_current = A[i] + remaining_votes;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_current, greater<ll>()) - sorted_A.begin();
            int worst_case = pos;
            if (worst_case < M) {
                res[i] = remaining_votes;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (res[i] != -1 && res[i] > remaining_votes) {
            res[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (res[i] == -1) {
            cout << "-1 ";
        } else {
            cout << res[i] << " ";
        }
    }

    return 0;
}
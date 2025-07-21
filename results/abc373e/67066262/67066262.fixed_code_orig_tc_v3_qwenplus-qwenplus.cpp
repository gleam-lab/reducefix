#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll& x : A) {
        cin >> x;
        K -= x;
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return A[i] < A[j]; });

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N+1);
    for (int i = 0; i < N; ++i) {
        prefix[i+1] = prefix[i] + sorted_A[i];
    }

    vector<ll> result(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        ll low = 0, high = K;
        ll target = A[ord[idx]];

        // Check if already guaranteed victory
        ll count = 0;
        for (int j = 0; j < N; ++j) {
            if (j != ord[idx] && A[j] >= A[ord[idx]]) {
                count++;
            }
        }
        if (count < M) {
            result[ord[idx]] = 0;
            continue;
        }

        while (low < high) {
            ll mid = (low + high) / 2;
            ll new_vote = target + mid;

            // Find first index in sorted_A where value > new_vote
            ll pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_vote) - sorted_A.begin();

            // How many candidates can be made to have more than new_vote?
            ll max_candidates_above = N - pos;
            ll need = 0;

            if (max_candidates_above >= M) {
                // We cannot save this candidate unless we reduce those above to < M
                need = 1;
            } else {
                // Distribute remaining votes to make sure at most M-1 candidates can have > new_vote
                ll extra = K - mid;
                ll limit = M - max_candidates_above;

                for (int j = N - 1; j >= 0 && limit > 0; --j) {
                    if (j == ord[idx]) continue;
                    if (A[j] <= new_vote) continue;

                    ll diff = A[j] - new_vote;
                    ll take = min(diff + 1, extra);
                    extra -= take;
                    A[j] -= take;
                    limit--;
                }

                bool possible = true;
                ll temp_count = 0;
                for (int j = 0; j < N; ++j) {
                    if (j == ord[idx]) continue;
                    if (A[j] > new_vote) {
                        temp_count++;
                    }
                }
                if (temp_count < M) {
                    possible = true;
                } else {
                    possible = false;
                }

                // Restore temporary changes
                for (int j = 0; j < N; ++j) {
                    if (j == ord[idx]) continue;
                    if (A[j] < sorted_A[j]) {
                        A[j] = sorted_A[j];
                    }
                }

                if (possible) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
        }

        ll final_X = low;
        ll new_total = A[ord[idx]] + final_X;

        ll cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (j != ord[idx] && A[j] > new_total) {
                cnt++;
            }
        }

        if (cnt < M) {
            result[ord[idx]] = final_X;
        } else {
            result[ord[idx]] = -1;
        }
    }

    for (ll val : result) {
        cout << val << ' ';
    }
    cout << '\n';
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

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

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    ll remaining_votes = K;
    for (int i = 0; i < N; ++i) {
        remaining_votes -= A[i];
    }

    vector<ll> result(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining_votes;
        ll min_votes = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = A[i] + mid;

            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_val) - sorted_A.begin();
            if (pos == N) {
                pos = N;
            }

            int rank = N - pos;
            if (rank < M) {
                ll required = 0;
                if (pos > N - M) {
                    int start_pos = N - M;
                    required = new_val * (pos - start_pos) - (prefix_sum[pos] - prefix_sum[start_pos]);
                } else {
                    required = new_val * M - (prefix_sum[N] - prefix_sum[N - M]);
                }

                if (required <= remaining_votes - mid) {
                    min_votes = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }

        if (min_votes != -1) {
            result[i] = min_votes;
        } else {
            result[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
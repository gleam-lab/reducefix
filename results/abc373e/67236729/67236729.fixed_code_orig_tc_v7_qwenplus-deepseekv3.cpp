#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    i64 K;
    cin >> N >> M >> K;

    vector<i64> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<i64> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<i64> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    for (int i = 0; i < N; ++i) {
        i64 a = A[i];
        i64 low = 0, high = K, ans = -1;

        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_a = a + mid;

            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_a) - sorted_A.begin();
            int cnt = N - pos;

            if (cnt < M) {
                i64 total = prefix_sum[N] - prefix_sum[pos];
                i64 needed = new_a * (M - cnt) - total;

                if (needed <= K - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }

        cout << ans << " ";
    }
    cout << "\n";

    return 0;
}
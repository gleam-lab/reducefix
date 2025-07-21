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
    sort(sorted_A.begin(), sorted_A.end(), greater<i64>());

    vector<i64> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    for (int i = 0; i < N; ++i) {
        i64 a_i = A[i];
        i64 low = 0, high = K, answer = -1;

        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_a_i = a_i + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_a_i, greater<i64>()) - sorted_A.begin();

            if (pos == 0) {
                answer = mid;
                high = mid - 1;
                continue;
            }

            int cnt = pos;
            if (sorted_A[pos - 1] == new_a_i) {
                cnt = pos;
            } else {
                cnt = pos;
            }

            if (cnt <= M - 1) {
                answer = mid;
                high = mid - 1;
                continue;
            }

            i64 sum = prefix_sum[M - 1];
            if (pos - 1 >= M - 1) {
                sum = prefix_sum[M - 1];
            } else {
                sum = prefix_sum[pos];
                sum += (M - 1 - pos) * new_a_i;
            }

            if (sum <= K - mid) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << " ";
    }

    cout << endl;

    return 0;
}
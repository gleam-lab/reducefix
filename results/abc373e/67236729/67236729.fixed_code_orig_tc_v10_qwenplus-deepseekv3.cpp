#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M, K;
    cin >> N >> M >> K;
    vector<i64> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<i64> B = A;
    sort(B.begin(), B.end());
    vector<i64> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }

    for (int i = 0; i < N; ++i) {
        i64 current = A[i];
        i64 low = 0, high = K, ans = -1;
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_votes = current + mid;

            // Find the first element in B greater than new_votes
            auto it = upper_bound(B.begin(), B.end(), new_votes);
            int cnt = B.end() - it;

            if (cnt < M) {
                // Need to check if remaining votes can't push more than M-1 candidates above new_votes
                i64 remaining = K - mid;
                i64 total = 0;

                if (cnt > 0) {
                    // Sum the top cnt elements and see if they can be increased to new_votes + 1
                    i64 sum = prefix[N] - prefix[N - cnt];
                    i64 needed = cnt * (new_votes + 1) - sum;
                    if (needed <= remaining) {
                        ans = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    ans = mid;
                    high = mid - 1;
                }
            } else {
                low = mid + 1;
            }
        }
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
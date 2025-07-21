#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e5 + 9;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N + 1), B(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
        }
        for (int i = 1; i <= N; ++i) {
            cin >> B[i];
        }

        long long ans = LLONG_MAX;
        if (K == 1) {
            for (int i = 1; i <= N; ++i) {
                ans = min(ans, (long long)A[i] * B[i]);
            }
        } else {
            vector<pair<long long, long long>> p(N + 1);
            for (int i = 1; i <= N; ++i) {
                p[i] = {A[i], B[i]};
            }
            sort(p.begin() + 1, p.end());

            long long sum = 0, best_sum = 0;
            for (int i = 1; i <= N; ++i) {
                sum += p[i].second;
                best_sum += p[i].first * p[i].second;
                if (i >= K) {
                    best_sum -= p[i - K].first * p[i - K].second;
                }
                if (i >= K - 1) {
                    ans = min(ans, best_sum);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
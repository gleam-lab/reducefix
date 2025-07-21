#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].second;
        }
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
        }
        sort(A.begin(), A.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        int sum = 0, maxB = 0, ans = INT_MAX;
        int count = 0;
        for (const auto& p : A) {
            sum += p.second;
            count++;
            if (count > K) {
                sum -= A[count - K].second;
            }
            if (count == K) {
                maxB = max(maxB, p.second);
            }
            if (count == K) {
                ans = min(ans, maxB * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
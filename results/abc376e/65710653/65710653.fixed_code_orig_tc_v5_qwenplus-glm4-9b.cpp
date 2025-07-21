#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;

        vector<pair<ll, ll>> A(N);
        vector<ll> B(N);

        for (ll i = 0; i < N; ++i) {
            cin >> A[i].first >> B[i];
        }

        // Sort pairs by second element (B) descending, then first element (A) descending
        sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        });

        // Calculate initial value
        ll ans = A[0].first * (K * A[0].second);
        ll sum_B = K * A[0].second;

        // Iterate over the rest of the elements to find the minimum value
        for (ll i = 1; i < N; ++i) {
            sum_B += B[i];
            if (sum_B >= K) {
                ans = min(ans, A[i].first * sum_B);
                break; // Once sum_B is >= K, any further additions will not reduce the maximum A_i
            }
        }

        cout << ans << endl;
    }
    return 0;
}
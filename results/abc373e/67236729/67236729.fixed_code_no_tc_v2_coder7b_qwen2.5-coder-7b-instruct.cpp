#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N + 1);
    vector<ll> B(N + 1);
    vector<ll> prefix_sum(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        B[i] = A[i];
        K -= A[i];
    }

    sort(B.begin() + 1, B.end());

    for (int i = N; i >= 1; --i) {
        prefix_sum[i] = prefix_sum[i + 1] + B[i];
    }

    auto check = [&](ll x, ll d) -> bool {
        int p = upper_bound(B.begin() + 1, B.end(), x + d) - B.begin();
        int up = N - p + 1;
        if (up >= M) return false;
        
        ll S = (prefix_sum[p - (M - up)] - prefix_sum[p]);
        if (B[p - (M - up)] <= x && x <= B[p - 1]) {
            S -= x;
            S += B[p - (M - up) - 1];
        }
        return (x + d + 1) * (M - up) > K - d;
    };

    for (int i = 1; i <= N; ++i) {
        ll l = 0, r = K, ans = -1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (check(A[i], mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << " ";
    }

    return 0;
}
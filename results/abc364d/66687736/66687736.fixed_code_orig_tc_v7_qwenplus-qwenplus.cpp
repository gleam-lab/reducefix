#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back

const int MAX = 2e5 + 10;

ll N, Q;
vi A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;

    A.resize(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b, k;
        cin >> b >> k;

        // Binary search on answer: the k-th smallest distance
        auto valid = [&](ll d) {
            ll cnt = 0;
            // For each a in A, check if |a - b| <= d
            cnt = upper_bound(A.begin(), A.end(), b + d) - lower_bound(A.begin(), A.end(), b - d);
            return cnt >= k;
        };

        ll low = 0, high = 2e8 + 10;
        ll ans = high;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (valid(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
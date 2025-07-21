#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    // Create sorted version of A
    vector<pair<ll, int>> SA(N);
    for (int i = 0; i < N; ++i)
        SA[i] = {A[i], i};
    sort(all(SA));

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + SA[i].first;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll ai = A[i];

        // Binary search on minimum X to guarantee election
        ll low = 0, high = K;
        ll ans = K + 1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll required = 0;
            ll target = ai + mid;

            // We need to ensure that at most M-1 candidates can have more votes than us
            // So we find the number of candidates with current votes > target
            // and how many we need to cap them
            int idx = upper_bound(SA.begin(), SA.end(), make_pair(target, N)) - SA.begin();

            // Need to limit top (N - M) candidates above us
            int limit_from = max(0, N - M + 1);
            int limit_to = idx;

            if (limit_to >= limit_from) {
                ll needed = (target + 1) * (limit_to - limit_from + 1);
                needed -= (prefix[limit_to] - prefix[limit_from - 1]);
                required = needed;
            }

            if (required <= K - mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (ans <= K)
            res[i] = ans;
        else
            res[i] = -1;
    }

    for (ll x : res)
        cout << x << ' ';
    cout << '\n';
}
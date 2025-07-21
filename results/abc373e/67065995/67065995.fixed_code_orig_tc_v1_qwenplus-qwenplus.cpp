#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define all(x) x.begin(), x.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }

    ll remaining = K - total;
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> result(N, -1);

    for (int i = 0; i < N; ++i) {
        ll l = 0, r = remaining;
        ll my_votes = A[i];

        auto check = [&](ll x) {
            ll new_vote = my_votes + x;

            // Find how many candidates can have more than this
            // Use upper_bound to count how many candidates have > new_vote
            int cnt = N - (upper_bound(all(sorted_A), new_vote) - sorted_A.begin());

            return cnt < M;
        };

        if (check(0)) {
            result[i] = 0;
            continue;
        }

        ll ans = -1;
        ll lo = 0, hi = remaining;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (check(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        result[i] = ans;
    }

    for (auto v : result)
        cout << v << " ";
    cout << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }

    // Remaining votes
    ll rem = K - total;

    vector<ll> sorted_A(A);
    sort(sorted_A.begin(), sorted_A.end());

    // Prefix sum array
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i];

    vector<ll> result(N);

    for (int i = 0; i < N; ++i) {
        ll my_votes = A[i];

        // Binary search over required additional votes
        ll low = 0, high = rem, ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll cur_total = my_votes + mid;

            // Find how many candidates could have more votes than cur_total
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), cur_total) - sorted_A.begin();

            // Count how many candidates have more than cur_total
            ll needed = max(0LL, N - pos);
            if (needed >= M) {
                high = mid - 1;
                continue;
            }

            // Now we must make sure at most (M - 1) candidates can get more than cur_total
            // So we cap all others to at most cur_total
            ll available = rem - mid;

            // Number of candidates above us: N - pos
            // Those candidates must be reduced to at most cur_total
            ll need_more = max(0LL, N - pos - (my_votes + mid == cur_total ? 0 : 1));

            ll required = cur_total * need_more - (prefix[N] - prefix[pos]);

            if (required <= available) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        result[i] = ans;
    }

    for (ll x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}
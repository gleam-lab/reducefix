#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, x, limit) for (int i = (x); i < (limit); i++)

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;

    // Create a sorted copy of A to use for binary search purposes
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    // Prefix sums of sorted_A
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];

    vector<ll> result(N);

    for (int i = 0; i < N; ++i) {
        ll base = A[i];
        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll modified = base + mid;

            // Binary search to find how many candidates have votes > modified
            int idx = upper_bound(sorted_A.begin(), sorted_A.end(), modified) - sorted_A.begin();
            ll strictly_more = N - idx;

            if (strictly_more < M) {
                // Already satisfies the condition, can try with less X
                answer = mid;
                high = mid - 1;
            } else {
                // Need more votes, increase X
                low = mid + 1;
            }
        }

        if (answer <= remaining)
            result[i] = (answer == -1 ? 0 : answer);
        else
            result[i] = -1;
    }

    for (int i = 0; i < N; ++i)
        cout << result[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
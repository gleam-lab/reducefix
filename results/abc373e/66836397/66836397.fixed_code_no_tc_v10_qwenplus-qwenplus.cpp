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

    // Create a sorted copy of A to use in binary search logic
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    // Prefix sum of sorted_A
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i];

    vector<ll> result(N);

    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = remaining;

        auto is_win_possible = [&](ll x) {
            ll new_vote = current + x;
            // Find how many candidates have strictly more votes than new_vote
            // r = first index where sorted_A[r] > new_vote
            ll r = upper_bound(sorted_A.begin(), sorted_A.end(), new_vote) - sorted_A.begin();
            ll stronger_candidates = N - r;

            if (stronger_candidates >= M)
                return false; // Already too many ahead

            // Need at least (M - stronger_candidates) candidates with <= new_vote
            // These candidates must be among the top (r) ones
            ll needed = M - stronger_candidates;
            if (needed <= 0)
                return true;

            if (r < needed)
                return false; // Not enough candidates below or equal

            // We can force (r - needed) candidates to stay below new_vote by increasing this candidate
            // The cost is to raise those (r - needed) candidates to new_vote
            ll l = r - needed;
            ll required_sum = new_vote * (r - l) - (prefix[r] - prefix[l]);
            return required_sum <= (remaining - x);
        };

        // Binary search on minimal number of votes
        ll left = 0, right = remaining;
        ll answer = -1;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (is_win_possible(mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        result[i] = (answer != -1) ? answer : -1;
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
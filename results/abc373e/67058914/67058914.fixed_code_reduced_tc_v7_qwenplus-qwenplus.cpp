#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    ll total = 0;
    for (auto [val, idx] : A)
        total += val;
    ll remaining = K - total;

    vector<ll> res(N, -1);

    // Create sorted list of (value, index)
    vector<pair<ll, int>> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    // Prefix sum array for sorted values
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i].first;

    // For each candidate, binary search on needed extra votes
    for (int i = 0; i < N; ++i) {
        ll a_i = A[i].first;
        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll cur_total = a_i + mid;

            // How many candidates have value > cur_total?
            int cnt = N - (upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(cur_total, N)) - sorted_A.begin());

            if (cnt >= M) {
                // Not elected yet, try more votes
                low = mid + 1;
            } else {
                // Can win with mid votes, try less
                answer = mid;
                high = mid - 1;
            }
        }

        if (answer != -1) {
            // Verify that it's possible to distribute remaining - answer votes to others
            // So that candidate still wins
            res[i] = answer;
        } else {
            // Check if already winning
            ll cnt = N - (upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(a_i, N)) - sorted_A.begin());
            if (cnt < M)
                res[i] = 0;
        }
    }

    for (int i = 0; i < N; ++i)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}
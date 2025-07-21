#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
    }

    // Store original indices
    for (int i = 0; i < N; ++i) {
        A[i].second = i;
    }

    // Sort candidates by vote count
    vector<pair<ll, int>> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    // Precompute prefix sums
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i].first;

    ll total_remaining = K - prefix[N];

    vector<ll> res(N);

    for (int i = 0; i < N; ++i) {
        ll my_votes = A[i].first;
        ll low = 0, high = total_remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_my = my_votes + mid;

            // Find how many candidates can have more than new_my
            // Use binary search to find how many candidates have value > new_my
            int cnt = N - (upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(new_my, N + 1)) - sorted_A.begin());

            if (cnt >= M) {
                low = mid + 1;
                continue;
            }

            // Try to block others from overtaking
            // Assign as many as possible to others without exceeding new_my
            ll needed = 0;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), make_pair(new_my, N + 1)) - sorted_A.begin();

            // Only consider those with vote <= new_my
            for (int j = 0; j < pos; ++j) {
                ll diff = new_my - sorted_A[j].first + 1;
                needed += diff;
                if (needed > total_remaining) break;
            }

            if (needed <= total_remaining) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[A[i].second] = (answer != -1 ? answer : -1);
    }

    for (int i = 0; i < N; ++i)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}
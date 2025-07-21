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
    }

    // Save original indices for final output
    vector<ll> res(N);
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[i].first;
    }
    sort(sorted_A.begin(), sorted_A.end());

    ll total_current = accumulate(sorted_A.begin(), sorted_A.end(), 0LL);
    ll remaining = K - total_current;

    auto get_required = [&](ll my_vote) -> ll {
        ll lo = 0, hi = remaining;
        ll ans = -1;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll new_my_vote = my_vote + mid;

            // Binary search to find how many candidates have more than new_my_vote
            int cnt_more = N - (upper_bound(sorted_A.begin(), sorted_A.end(), new_my_vote - 1) - sorted_A.begin());

            if (cnt_more < M) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    };

    for (int i = 0; i < N; ++i) {
        ll base = A[i].first;
        res[i] = get_required(base);
    }

    // Output in original order
    vector<ll> final_res(N);
    for (int i = 0; i < N; ++i) {
        final_res[A[i].second] = res[i];
    }

    for (int i = 0; i < N; ++i) {
        cout << final_res[i] << " ";
    }
    cout << "\n";

    return 0;
}
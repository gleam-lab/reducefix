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
        A[i].second = i;
    }

    // Store original indices to reconstruct output order
    vector<int> original_index(N);
    for (int i = 0; i < N; ++i)
        original_index[A[i].second] = i;

    sort(A.begin(), A.end());

    vector<ll> prefix(N + 1);
    for (int i = 1; i <= N; ++i)
        prefix[i] = prefix[i - 1] + A[i - 1].first;

    ll total_remaining = K - prefix[N];

    vector<ll> res(N);

    for (int i = 0; i < N; ++i) {
        ll lo = 0, hi = total_remaining;
        ll answer = -1;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll cur_vote = A[i].first + mid;

            // Find how many candidates have votes > cur_vote
            int cnt = N - (int)(upper_bound(A.begin(), A.end(), make_pair(cur_vote, N)) - A.begin());

            // Subtract 1 if current candidate is counted in upper_bound
            if (A[i].first + mid > cur_vote)
                cnt--;

            if (cnt >= M) {
                lo = mid + 1;
            } else {
                answer = mid;
                hi = mid - 1;
            }
        }

        res[A[i].second] = answer;
    }

    for (int i = 0; i < N; ++i)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}
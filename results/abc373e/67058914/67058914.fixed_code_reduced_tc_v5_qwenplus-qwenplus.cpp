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

    // Sort by vote count descending, keeping original index
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    // Prefix sum of sorted values
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + A[i].first;

    // For each candidate, binary search on needed votes
    for (int i = 0; i < N; ++i) {
        auto [cur_votes, idx] = A[i];

        // Binary search on additional votes needed
        ll low = 0, high = remaining;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = cur_votes + mid;

            // We need to ensure that at most M-1 candidates have more votes than this candidate
            // So find how many candidates can get strictly more than new_vote
            // and make sure we can limit those to < M

            ll sum_needed = 0;
            int l = 0, r = N;
            while (l < r) {
                int m = (l + r) / 2;
                if (A[m].first > new_vote) l = m + 1;
                else r = m;
            }

            int cnt = l; // Number of candidates with > new_vote
            if (cnt < M) {
                // This candidate is already elected with these additional votes
                ans = mid;
                high = mid - 1;
            } else {
                // Need to increase votes
                low = mid + 1;
            }
        }

        if (ans == 0) {
            // Check if already elected
            ll cnt = 0;
            for (int j = 0; j < N; ++j)
                if (A[j].first > cur_votes)
                    ++cnt;
            if (cnt < M)
                res[idx] = 0;
            else
                res[idx] = -1;
        } else if (ans != -1) {
            res[idx] = ans;
        } else {
            // Try zero first
            ll cnt = 0;
            for (int j = 0; j < N; ++j)
                if (A[j].first > cur_votes)
                    ++cnt;
            if (cnt < M)
                res[idx] = 0;
            else
                res[idx] = -1;
        }
    }

    for (int i = 0; i < N; ++i)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
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
    for (auto &a : A)
        total += a.first;
    ll remaining = K - total;

    vector<ll> res(N, -1);

    // Sort by vote count ascending + keep track of original indices
    sort(A.begin(), A.end());

    // For each candidate, binary search on minimum X additional votes needed
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        bool possible = false;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll cur_votes = A[i].first + mid;

            // Count how many candidates can have strictly more votes than this one
            int cnt = N - (upper_bound(A.begin(), A.end(), make_pair(cur_votes, N)) - A.begin());

            if (cnt < M) {
                // This candidate is guaranteed to be elected
                res[A[i].second] = mid;
                low = mid + 1;
                possible = true;
            } else {
                // Not guaranteed election, need more votes
                low = mid + 1;
            }
        }

        // If not even with all remaining votes we can guarantee win
        if (!possible && (A[i].first + remaining + M - 1 >= A.back().first)) {
            ll need = max(0LL, A[N - M + 1].first - A[i].first + 1);
            if (need <= remaining)
                res[A[i].second] = need;
        }
    }

    for (auto &r : res)
        cout << r << " ";
    cout << endl;

    return 0;
}
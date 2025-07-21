#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M >> K;
    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    vector<ll> res(N);
    vector<ll> sorted_A(N);

    // Sort the candidates by current votes
    sort(A.begin(), A.end());

    // Prepare prefix sums of the sorted votes
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + A[i].first;
        sorted_A[i] = A[i].first;
    }
    ll remaining_votes = K - prefix[N];

    auto solve_for = [&](int idx) -> ll {
        ll a_i = A[idx].first;

        int l = 0, r = remaining_votes + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            ll my_total = a_i + mid;
            ll need = 0;

            // Binary search to find how many candidates below can be surpassed
            int lo = 0, hi = idx;
            while (lo < hi) {
                int mi = (lo + hi) / 2;
                if (A[mi].first + remaining_votes - mid <= my_total)
                    hi = mi;
                else
                    lo = mi + 1;
            }
            int cnt = idx - lo;

            // Need to make sure at most M-1 candidates have more than me
            int max_more_allowed = M - 1 - cnt;
            if (max_more_allowed < 0) {
                l = mid + 1;
                continue;
            }

            // Try to raise top M candidates just above me
            int L = 0, R = N - idx - 1;
            while (L < R) {
                int MID = (L + R + 1) / 2;
                int pos = idx + 1 + MID;
                ll target = my_total + 1;
                ll sum = prefix[pos] - prefix[idx + 1];
                ll needed = target * MID - sum;
                if (needed > remaining_votes - mid)
                    R = MID - 1;
                else
                    L = MID;
            }

            if (L >= max_more_allowed)
                r = mid;
            else
                l = mid + 1;
        }

        // Check if solution is possible
        if (l > remaining_votes)
            return -1LL;
        return max(0LL, l);
    };

    vector<pair<ll, int>> ans(N);
    for (int i = 0; i < N; ++i) {
        ans[i].second = A[i].second;
        ll win = solve_for(i);
        ans[i].first = win;
    }

    sort(ans.begin(), ans.end(), [](const pair<ll, int>& a, const pair<ll, int>& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < N; ++i)
        cout << ans[i].first << " ";
    cout << endl;

    return 0;
}
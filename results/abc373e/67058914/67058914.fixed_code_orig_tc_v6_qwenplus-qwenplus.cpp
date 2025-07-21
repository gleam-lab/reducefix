#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M, K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    // We will sort A by current vote count
    sort(A.begin(), A.end());

    // Prefix sum array
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + A[i].first;

    // Total votes already assigned
    ll total_assigned = prefix[N];
    ll remaining_votes = K - total_assigned;

    vector<ll> res(N);

    // Prepare answer array
    vector<pair<ll, int>> ans(N);
    for (int i = 0; i < N; ++i)
        ans[i].second = A[i].second;

    auto count_needed = [&](ll add, int idx) -> ll {
        ll cur = A[idx].first + add;
        int l = 0, r = N - 1;

        // Find how many candidates have more votes than current after adding 'add'
        while (l < r) {
            int m = (l + r) / 2;
            if (A[m].first > cur)
                l = m + 1;
            else
                r = m;
        }
        while (l > 0 && A[l - 1].first == cur) --l;

        // Count how many people currently have more or equal votes
        int cnt = N - l;

        // If candidate already has enough votes to be in top (N-M+1), no need
        if (cnt < M)
            return 0;

        // Binary search on the number of extra votes needed
        ll low = 0, high = remaining_votes;
        ll result = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            cur = A[idx].first + mid;

            // Count how many candidates can get more than cur
            int pos = N;
            int left = 0, right = N - 1;
            while (left <= right) {
                int m = (left + right) / 2;
                if (A[m].first > cur)
                    pos = m, right = m - 1;
                else
                    left = m + 1;
            }

            ll needed = 0;
            int limit = min(N, idx + M - 1);
            for (int i = N - 1; i >= pos && i > limit; --i) {
                needed += max(0LL, cur - A[i].first + 1);
            }

            if (needed <= remaining_votes - mid) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    };

    for (int i = 0; i < N; ++i) {
        ll val = A[i].first;
        ll cur = val;
        int cnt = 0;
        for (int j = N - 1; j >= 0 && j != i && cnt < M; --j, ++cnt)
            if (A[j].first > cur)
                cnt++;
        if (cnt >= M)
            ans[i].first = 0;
        else {
            ll x = count_needed(0, i);
            if (x == -1)
                ans[i].first = -1;
            else
                ans[i].first = x;
        }
    }

    // Reorder answers
    sort(ans.begin(), ans.end(), [](auto &a, auto &b) { return a.second < b.second; });

    for (int i = 0; i < N; ++i)
        cout << ans[i].first << " ";
    cout << "\n";

    return 0;
}
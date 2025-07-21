#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    // Sort by votes ascending
    sort(A.begin(), A.end());

    // Prefix sum of sorted votes
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + A[i].first;

    // Remaining unassigned votes
    ll total_remaining = K - prefix[N];

    vector<ll> res(N);
    for (int i = 0; i < N; ++i)
        res[A[i].second] = 0; // Initially assume no votes needed

    // Process each candidate
    for (int i = 0; i < N; ++i) {
        int idx = A[i].second;
        ll orig_vote = A[i].first;

        auto check = [&](ll X) -> bool {
            ll new_vote = orig_vote + X;
            ll remaining = total_remaining - X;

            // Binary search: find first index where votes > new_vote
            int low = i + 1, high = N;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mid == N || A[mid].first > new_vote)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            int cnt_better = N - max(i + 1, high + 1);

            // Now distribute remaining votes greedily to top (N - cnt_better - 1) candidates
            int available = (N - cnt_better - 1);
            if (available >= M) return false;

            // Compute how much is needed to prevent more than (M - 1) candidates from overtaking
            int left = 0, right = available;
            int count = 0;

            while (left <= right && remaining > 0) {
                int mid = (left + right) / 2;
                ll need = new_vote * mid;
                for (int j = 0; j < mid; ++j)
                    need += (new_vote - A[N - j - 1].first);
                if (need <= remaining) {
                    count = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            return (cnt_better + count) < M;
        };

        // Binary search over possible additional votes
        ll l = 0, r = total_remaining + 1;
        while (l < r) {
            ll mid = (l + r) / 2;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }

        if (!check(l)) {
            res[idx] = -1;
        } else {
            res[idx] = l;
        }
    }

    for (int i = 0; i < N; ++i)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}
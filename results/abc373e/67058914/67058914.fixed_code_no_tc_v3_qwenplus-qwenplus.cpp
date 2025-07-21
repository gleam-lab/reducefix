#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum_A = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum_A += A[i];
    }

    // Remaining votes
    ll rem = K - sum_A;
    vector<ll> res(N, -1);

    // We will sort the candidates' current votes
    vector<pair<ll, int>> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = {A[i], i};
    }
    sort(sorted_A.begin(), sorted_A.end());

    // Precompute prefix sums of sorted_A
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i].first;
    }

    // For each candidate, binary search on minimum X
    for (int i = 0; i < N; ++i) {
        int idx = sorted_A[i].second;
        ll cur_votes = sorted_A[i].first;

        // Binary search over additional votes needed
        ll low = 0, high = rem;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = cur_votes + mid;
            ll remaining = rem - mid;

            // Find how many candidates are strictly greater than total in the sorted list
            int left = 0, right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (sorted_A[m].first > total)
                    right = m;
                else
                    left = m + 1;
            }

            // Now we need to make sure that at most M-1 candidates can get more than cur_votes + mid
            // So we try to raise top (N - (left)) candidates and see if we can give them enough
            // to have at least one vote more than current candidate

            // At most `left` candidates can be below or equal to current
            // So up to `M - 1` candidates can be above

            // The number of candidates strictly greater than total is (N - left)
            // So we want: (number of candidates who can beat us) < M
            // That is: (N - left) < M
            // If already satisfied, no need to do anything
            if ((N - left) < M) {
                ans = mid;
                high = mid - 1;
                continue;
            }

            // Else, we need to increase those who are above us.
            // We must increase at least (N - left - (M - 1)) candidates so that only (M - 1) remain above us.

            int need_to_increase = (N - left) - (M - 1);
            if (need_to_increase <= 0) {
                ans = mid;
                high = mid - 1;
                continue;
            }

            // These candidates are from index left to N-1
            ll required = 0;
            for (int j = left; j < left + need_to_increase; ++j) {
                ll diff = total - sorted_A[j].first + 1;
                required += diff;
            }

            if (required <= remaining) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (ans == -1) {
            // Try full brute-force fallback: check if even giving all remaining votes helps
            ll total = cur_votes + rem;
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (j != idx && A[j] > total)
                    cnt++;
            }
            if (cnt < M)
                res[idx] = rem;
            else
                res[idx] = -1;
        } else {
            res[idx] = ans;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (res[i] == -1) cout << -1 << " ";
        else cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
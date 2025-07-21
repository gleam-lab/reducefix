#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    
    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
    }

    vector<ll> res(N);
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);

    // Sort candidates by current vote count
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return A[i].first < A[j].first;
    });

    // Prefix sum of sorted votes
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + A[indices[i]].first;
    }

    auto compute_min_votes = [&](int idx) {
        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll my_vote = A[idx].first + mid;
            // Binary search to find how many have strictly more than my_vote
            int l = 0, r = N;
            while (l < r) {
                int m = (l + r) / 2;
                if (A[indices[m]].first > my_vote)
                    r = m;
                else
                    l = m + 1;
            }
            int stronger = N - l;

            // We need to make sure at most M-1 candidates have more votes than us
            // So we might need to increase some of the ones equal to us to be above us
            int remaining = N - max(0, l - 1);
            int can_invalidate = min(remaining, M - 1 - stronger);
            if (can_invalidate < 0) can_invalidate = 0;

            // These are the number of candidates that could be made to have <= my_vote
            int target = remaining - can_invalidate;
            ll required = my_vote * target - (prefix[N] - prefix[l]);
            if (required <= K - mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low <= K ? low : -1LL;
    };

    for (int i = 0; i < N; ++i) {
        ll ans = compute_min_votes(i);
        res[i] = max(0LL, ans);
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << '\n';

    return 0;
}
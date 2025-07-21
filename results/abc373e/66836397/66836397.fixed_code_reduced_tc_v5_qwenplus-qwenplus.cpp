#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (auto& x : A) cin >> x;

    ll total = accumulate(A.begin(), A.end(), 0LL);
    ll rem = K - total;

    vector<pair<ll, int>> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = {A[i], i};
    }
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i].first;
    }

    vector<ll> ans(N);

    for (int i = 0; i < N; ++i) {
        ll a_i = A[i];

        // Binary search on required votes
        ll low = 0;
        ll high = rem + 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll current = a_i + mid;

            // Find how many candidates have strictly more votes than current
            int l = 0, r = N;
            while (l < r) {
                int m = (l + r) / 2;
                if (sorted_A[m].first > current)
                    r = m;
                else
                    l = m + 1;
            }
            int better = l;

            // We need to ensure that at most M-1 candidates have more votes than us
            // So we can allow up to (M-1 - better) additional candidates to get more votes
            int need_to_block = max(0, better - (M - 1));
            if (need_to_block == 0) {
                high = mid;
                continue;
            }

            // Try to block these `need_to_block` top candidates by making them <= current
            // Take the smallest `need_to_block` candidates from the top

            int idx = N - need_to_block;
            ll sum = prefix_sum[N] - prefix_sum[idx];
            ll needed = sum - need_to_block * current;

            if (needed <= rem - mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        if (low > rem)
            ans[i] = -1;
        else
            ans[i] = low;
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) {
        cin >> a;
        K -= a;
    }

    // ord[i] = original index of the candidate with i-th smallest current votes
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int x, int y) { return A[x] < A[y]; });

    // sortedA[i] = current votes of candidate in sorted order
    vector<ll> sortedA = A;
    sort(all(sortedA));

    // prefix sum of sortedA
    vector<ll> pref(N + 1);
    for (int i = 0; i < N; ++i) {
        pref[i + 1] = pref[i] + sortedA[i];
    }

    vector<ll> res(N, -1); // result for each candidate

    for (int idx = 0; idx < N; ++idx) {
        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;

            ll target_vote = sortedA[idx] + mid;

            // Find how many candidates have strictly more than target_vote
            // Binary search to find first index where vote > target_vote
            ll cnt = N - (upper_bound(all(sortedA), target_vote) - sortedA.begin());

            if (cnt >= M) {
                // Still not enough, try higher X
                low = mid + 1;
            } else {
                // Might be enough, try lower X
                high = mid;
            }
        }

        // Check if we can actually guarantee win with X = low
        ll required_votes = sortedA[idx] + low;
        ll cnt_above = N - (upper_bound(all(sortedA), required_votes) - sortedA.begin());

        if (cnt_above < M && low <= K)
            res[ord[idx]] = low;
        else
            res[ord[idx]] = -1;
    }

    for (ll val : res)
        cout << (val == -1 ? -1 : val) << ' ';
    cout << '\n';

    return 0;
}
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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    // Create index array to sort while keeping track of original indices
    vector<int> ord(N);
    iota(all(ord), 0);

    // Sort candidates by current votes
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sortedA = A;
    sort(all(sortedA));

    // Compute prefix sums of sorted votes
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> result(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        int orig_idx = ord[idx];
        ll low = 0, high = K + 1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = sortedA[idx] + mid;

            // Find how many candidates have strictly more votes than target
            // in the worst case scenario
            int pos = upper_bound(all(sortedA), target) - sortedA.begin();

            // We want at most M-1 candidates with more votes than ours
            int need_to_increase = max(0, (N - (M - 1)) - pos);

            if (need_to_increase > idx) {
                // Our candidate is among those who need to overtake
                need_to_increase--;
            }

            ll extra_votes_needed = 0;
            if (need_to_increase > 0) {
                ll threshold = target + 1;
                ll sum = threshold * need_to_increase - (prefix[pos + need_to_increase] - prefix[pos]);
                extra_votes_needed = sum;
            }

            if (extra_votes_needed <= K) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (low > K)
            result[orig_idx] = -1;
        else
            result[orig_idx] = low;
    }

    for (ll val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
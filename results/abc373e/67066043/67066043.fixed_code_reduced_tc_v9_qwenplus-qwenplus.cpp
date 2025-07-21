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

    // Create sorted version of A
    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i)
        sortedA[i] = {A[i], i};
    sort(all(sortedA));

    // Prepare prefix sums
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sortedA[i].first;

    vector<ll> result(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        ll ai = sortedA[idx].first;
        int pos = idx; // position in sorted array

        // Binary search for minimum X
        ll low = 0, high = K;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = ai + mid;

            // We want to ensure that at most M-1 candidates have more than target votes
            // So find how many candidates can have >= target+1 votes
            // and compute how many extra votes are needed to push them above target

            // Use binary search to find the first candidate with votes >= target+1
            int j = lower_bound(sortedA.begin(), sortedA.end(), make_pair(target + 1, -1)) - sortedA.begin();

            // If less than M candidates can have more votes than us, we're safe
            if (N - j >= M) {
                // Need to increase our votes further
                low = mid + 1;
                continue;
            }

            // Calculate how many extra votes are needed to prevent others from having > target
            ll needed = (target + 1) * (M - (N - j)) - (prefix[j] - prefix[j - (M - (N - j))]);

            // Check if we can afford it
            if (needed <= K - mid) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        result[sortedA[idx].second] = (answer == -1 ? -1 : answer);
    }

    for (ll val : result)
        cout << val << " ";
    cout << "\n";

    return 0;
}
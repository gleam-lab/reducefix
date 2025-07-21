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

    // Create sorted copy of A to use for binary search and prefix sums
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    // Precompute prefix sums of sorted_A
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> result(N, -1);

    // For each candidate, perform binary search on required additional votes
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = K;
        ll current_votes = A[i];
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = current_votes + mid;

            // Find how many candidates have votes > target in the final state
            // We need to ensure that fewer than M candidates have more votes than target

            // Binary search to find how many candidates could potentially have > target
            int idx = upper_bound(all(sorted_A), target) - sorted_A.begin();

            // We want at most M-1 candidates to have more votes than target
            // So we protect top M-1 candidates below idx
            int protect = max(0, idx - (M - 1));
            ll needed = 0;

            // Protect top (M-1) candidates who might exceed target
            if (protect > 0) {
                needed = protect * (target + 1) - (prefix[protect]);
            }

            if (needed <= K - mid) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // If answer is still -1, it means it's not possible
        if (answer == -1) {
            result[i] = -1;
        } else if (answer == 0 && A[i] + answer >= sorted_A[N - M]) {
            // Already secure
            result[i] = 0;
        } else {
            result[i] = answer;
        }
    }

    for (ll val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
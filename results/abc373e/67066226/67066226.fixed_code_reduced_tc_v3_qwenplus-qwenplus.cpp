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
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });

    vector<ll> sortedA = A;
    sort(all(sortedA));

    vector<ll> prefix(n+1);
    for (int i = 0; i < N; ++i)
        prefix[i+1] = prefix[i] + sortedA[i];

    vector<ll> result(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        ll left = 0, right = K;
        ll ans = -1;

        while (left <= right) {
            ll mid = (left + right) / 2;
            ll target = A[ord[idx]] + mid;

            // We want to find how many candidates can have >= target votes
            // We must ensure at most M-1 candidates have more than this one

            // Number of candidates that can potentially have > target votes
            int count = N - (upper_bound(all(sortedA), target) - sortedA.begin());

            if (count < M) {
                // Already good, no need for more votes
                ans = mid;
                right = mid - 1;
                continue;
            }

            // Need to cap other candidates to <= target
            // Find the number of candidates that currently have > target
            int pos = upper_bound(all(sortedA), target) - sortedA.begin();
            int numAbove = N - pos;

            // Try to reduce those above by limiting their votes to target
            ll needed = 0;
            for (int i = pos; i < N && needed <= K; ++i) {
                if (i == idx) continue; // skip self
                needed += (sortedA[i] - target);
                if (needed > K - mid) break;
            }

            if (needed <= K - mid) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        result[ord[idx]] = (ans == -1 ? -1 : ans);
    }

    for (ll val : result) {
        cout << (val == -1 ? -1 : max(0LL, val)) << ' ';
    }
}
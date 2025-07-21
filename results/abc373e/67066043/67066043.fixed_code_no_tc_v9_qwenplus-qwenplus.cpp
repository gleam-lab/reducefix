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

    // ord[i] = original index of sorted candidates by current votes
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return A[i] < A[j]; });

    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> result(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx]; // original index
        ll lo = 0, hi = K + 1;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll target = A[i] + mid;

            // Find how many candidates have more votes than target
            // using binary search on sorted_A
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), target) - sorted_A.begin();

            // Need to ensure at most M-1 candidates have strictly more
            // So we need: at least (N - (M - 1)) candidates with ≤ target votes
            // That means the (M)th highest candidate must be ≥ target

            if (N - pos >= M) {
                // Already enough votes to be in top M
                hi = mid - 1;
            } else {
                // We need to raise this candidate's vote so that at least
                // M candidates are below them

                // We need to increase votes of the top (N - M) candidates
                // to be > target
                int left = N - M;
                ll need = 0;

                if (idx >= left) {
                    // This candidate might be in the top group
                    // We need to exclude their own votes from the calculation
                    int cnt = lower_bound(sorted_A.begin(), sorted_A.end(), target + 1) - sorted_A.begin();
                    ll total = cnt * (target + 1) - (prefix[cnt]);
                    if (cnt > idx && cnt - 1 == idx) total -= (target + 1 - A[i] - mid);
                    need = total;
                } else {
                    // This candidate is in the top group, skip them
                    ll total = (left - 1) * (target + 1) - (prefix[left - 1]);
                    need = total;
                }

                if (need <= K - mid) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }

        if (lo > K)
            result[i] = -1;
        else
            result[i] = lo;
    }

    for (ll val : result)
        cout << val << ' ';
    cout << '\n';

    return 0;
}
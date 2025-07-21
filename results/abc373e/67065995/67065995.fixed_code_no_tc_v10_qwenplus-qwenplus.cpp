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

    // ord[i] = original index of the candidate with the i-th smallest current votes
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int x, int y) { return A[x] < A[y]; });
    
    // sorted copy of A
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    // prefix sum of sorted_A
    vector<ll> pref(N + 1);
    for (int i = 0; i < N; ++i) {
        pref[i + 1] = pref[i] + sorted_A[i];
    }

    vector<ll> res(N, -1); // result array

    for (int idx = 0; idx < N; ++idx) {
        ll lo = 0, hi = K;
        ll target_votes = sorted_A[idx] + 1;
        ll ans = -1;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;

            // Find how many candidates currently have more than A[ord[idx]] + mid
            int pos = upper_bound(all(sorted_A), A[ord[idx]] + mid) - sorted_A.begin();

            // Need to make sure that at most M-1 candidates have more votes than this one
            int need_to_increase = max(0, pos - (M - 1));
            if (need_to_increase == 0) {
                ans = mid;
                hi = mid - 1;
            } else {
                // These `need_to_increase` candidates must be increased to at least A[ord[idx]] + mid + 1
                int l = N - need_to_increase;
                ll required_votes = need_to_increase * (A[ord[idx]] + mid + 1) - (pref[N] - pref[l]);
                if (required_votes <= K - mid) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }

        res[ord[idx]] = (ans <= K) ? ans : -1;
    }

    for (ll val : res) {
        cout << val << ' ';
    }
    cout << '\n';

    return 0;
}
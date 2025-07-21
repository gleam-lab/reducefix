#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    ll total = accumulate(all(A), 0LL);
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sortedA = A;
    sort(all(sortedA));
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = sortedA[i] + prefix[i];
    }
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll original = A[ord[i]];
        ll low = 0, high = K - (total - original);
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = original + mid;
            int pos = upper_bound(all(sortedA), new_votes) - sortedA.begin();
            int needed_pos = N - M + 1;
            if (pos >= needed_pos) {
                best = mid;
                high = mid - 1;
            } else {
                ll sum_after = prefix[needed_pos] - prefix[pos];
                ll required = sum_after - (needed_pos - pos) * new_votes;
                if (mid + required <= K - (total - original)) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[ord[i]] = best;
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
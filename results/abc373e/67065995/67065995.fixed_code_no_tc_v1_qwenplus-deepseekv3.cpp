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
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;
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
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0, high = remaining, best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newVotes = A[i] + mid;
            int pos = upper_bound(all(sortedA), newVotes) - sortedA.begin();
            int needed = N - pos;
            if (needed < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1) {
            ans[i] = best;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
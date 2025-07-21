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
    }
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sortedA = A;
    sort(all(sortedA));
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll current = A[i];
        ll low = 0, high = K;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = current + mid;
            // Find the first position in sortedA where the value is > new_val
            ll pos = upper_bound(all(sortedA), new_val) - sortedA.begin();
            ll candidates_above = N - pos;
            if (candidates_above < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1) {
            // Need to check if total required votes is <= remaining votes
            if (best <= K) {
                ans[i] = best;
            } else {
                ans[i] = -1;
            }
        } else {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
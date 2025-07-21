#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b, k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        // We will use binary search to find the k-th closest element
        // The idea is to find the k-th smallest |A[i] - b|
        // To do this efficiently, we can use binary search on the possible distances
        // But a better approach is to find the k-th smallest in the sorted differences
        // Since the array A is sorted, the closest elements to b will be near the position where b would be inserted in A
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        // Now, we need to consider elements around pos to find the k-th closest
        // We can use a two-pointer approach to find the k smallest distances
        int l = pos - 1;
        int r = pos;
        vector<ll> distances;
        while (k > 0 && (l >= 0 || r < N)) {
            ll dl = (l >= 0) ? abs(A[l] - b) : LLONG_MAX;
            ll dr = (r < N) ? abs(A[r] - b) : LLONG_MAX;
            if (dl <= dr) {
                distances.push_back(dl);
                l--;
            } else {
                distances.push_back(dr);
                r++;
            }
            k--;
        }
        cout << distances[k-1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
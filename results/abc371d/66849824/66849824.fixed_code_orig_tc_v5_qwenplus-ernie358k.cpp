#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1, 0), X(N);
    rep(i, N) cin >> X[i];
    sort(X.begin(), X.end()); // Sorting X for binary search to work correctly

    // Create an unordered_map to store the index of each element in sorted X
    unordered_map<int, int> x_to_ptr;
    rep(i, N) {
        x_to_ptr[X[i]] = i;
    }

    rep(i, N) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;

        // Find the leftmost index >= L
        auto it_l = x_to_ptr.lower_bound(L);
        int l = (it_l != x_to_ptr.end()) ? it_l->second : N;

        // Find the rightmost index < R (use upper_bound and decrement the iterator)
        auto it_r = x_to_ptr.upper_bound(R);
        int r = (it_r != x_to_ptr.begin()) ? prev(it_r)->second : -1;
        if (r == -1) r = N; // If R is smaller than all elements, r should be N

        // Calculate the sum using prefix sums array P
        ll ans = (l <= r) ? P[r + 1] - P[l] : 0;
        cout << ans << endl;
    }

    return 0;
}
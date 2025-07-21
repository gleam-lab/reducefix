#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) {
        ll p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }
    map<ll, int> x_to_ptr;
    rep(i, N) {
        x_to_ptr.emplace(X[i], i);
    }

    int Q;
    cin >> Q;
    rep(q, Q) {
        ll L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        if (X_l == x_to_ptr.begin() && (*X_l).first > L) {
            // If L is less than the smallest X[i], l should be 0
            X_l = prev(x_to_ptr.end()); // Move to the last element temporarily
            X_l = prev(X_l); // Move to the second last element (or the largest less than all keys)
            int last_index = (*X_l).second;
            ll last_value = X[last_index];
            // Since there's no X[i] <= L, we use the last index (with largest X[i] < L) + 1 as a placeholder
            // But since we use prefix sums, P[0] is the start, so we don't need to adjust the index for P
            // We just need to ensure we use P[0] correctly if l would be out of bounds
        } else if (X_l != x_to_ptr.end()) {
            X_l--; // Move to the correct position since lower_bound gives the first element >= L
        } else {
            // This case should not happen due to the map's properties and our input range
            // But to be safe, if lower_bound returns end(), it means all elements are greater than L
            // We should use the largest index (i.e., N which represents the end of the prefix sums)
            X_l = prev(x_to_ptr.end());
        }
        int l = (*X_l).second;

        auto X_r = x_to_ptr.upper_bound(R);
        if (X_r == x_to_ptr.end()) {
            // If R is greater than the largest X[i], r should be N (end of the array)
            r = N;
        } else {
            // Since upper_bound gives the first element > R, we need the previous element
            X_r--;
            r = (*X_r).second + 1; // +1 because we want the index after the last valid index <= R
            if (r > N) r = N; // In case R is exactly the largest X[i], we don't want r to go out of bounds
        }

        ll ans = P[r] - P[l];
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> X(N), P(N);
    for(int i = 0; i < N; ++i) cin >> X[i];
    for(int i = 0; i < N; ++i) cin >> P[i];

    // Calculate prefix sum array
    for(int i = 1; i < N; ++i) P[i] += P[i-1];

    int Q;
    cin >> Q;
    while(Q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the position of the first element greater than or equal to L
        auto it_L = lower_bound(begin(X), end(X), L);
        // Find the position just past the last element less than or equal to R
        auto it_R = upper_bound(begin(X), end(X), R);
        
        // Calculate the number of elements in range [it_L, it_R)
        int count = distance(it_L, it_R);
        
        // If the entire range [L, R] is within the valid positions
        if(count == it_R - begin(X)) {
            cout << P[count-1] << '\n';
        } else {
            // Otherwise, calculate using prefix sums
            int ans = P[it_R - begin(X) - 1] - (it_L == begin(X) ? 0 : P[it_L - begin(X) - 1]);
            cout << ans << '\n';
        }
    }

    return 0;
}
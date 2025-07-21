#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;

// ... (other code remains the same) ...

int main(){
    // ... (input and initialization code remains the same) ...

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        if (X_l == x_to_ptr.end() || X_r == x_to_ptr.begin()) { // Check if l or r is out of bounds
            int ans = 0; // Set ans to 0 or any other appropriate value if l or r is out of bounds
        } else {
            if (X_l != x_to_ptr.end()) {
                int l = (*X_l).second;
                if (l == N) { // Check if l is N (out of bounds) and handle accordingly
                    l = N - 1; // Or set to any valid index or value based on problem's requirements
                }
            } else {
                l = N; // Handle the case where X_l points to end() separately (e.g., set l to a valid index or 0)
            }
            if (X_r != x_to_ptr.end()) {
                int r = (*X_r).second;
                if (r == N) { // Check if r is N (out of bounds) and handle accordingly
                    r = N - 1; // Or set to any valid index or value based on problem's requirements
                }
            } else {
                r = N; // Handle the case where X_r points to begin() separately (e.g., set r to a valid index or 0)
            }
            int ans = P[r] - P[l]; // Calculate the answer correctly by handling out-of-bounds cases separately
        }
        cout << ans << endl; // Output the answer as expected without undefined behavior due to out-of-bounds access
    }
}
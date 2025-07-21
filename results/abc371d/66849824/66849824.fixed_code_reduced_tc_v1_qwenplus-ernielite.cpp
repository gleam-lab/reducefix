#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// ... (Your other includes and macros)

int main() {
    int N;
    cin >> N;
    vector<ll> P(N + 1), X(N); // Initialize P to store prefix sums of X
    P[0] = 0; // Initialize prefix sum with 0
    for (int i = 0; i < N; ++i) {
        cin >> X[i]; // Read X values into the array
        P[i + 1] = X[i]; // Set P[i+1] to be the current value of X[i] (or some other appropriate value)
    }
    // ... (Your other code)

    // Now, when you calculate the answer for a query [L, R], you can simply use P[R+1] - P[L] as the prefix sum difference.
    // The rest of your code can remain as it is, since you're using the map `x_to_ptr` correctly to find the indices l and r.

    // ... (Your rest of the code)
}
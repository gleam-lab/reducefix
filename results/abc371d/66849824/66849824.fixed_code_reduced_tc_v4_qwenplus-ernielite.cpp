#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

// ... (other definitions remain the same) ...

int main() {
    // ... (input handling remains the same) ...

    // ... (code for finding L and R remains the same) ...

    int ans = P[r + 1] - P[l]; // Corrected line: subtracting value at l+1 from value at r+1 in P
    cout << ans << endl;
}
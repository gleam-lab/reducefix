#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];

// To store prefix sums of population count up to each village
long long sum[200005]; 

int main() {
    cin >> n;
    
    // Read positions of villages and their populations
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        
        // Calculate prefix sum of population counts
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    
    while (q--) {
        int L, R;
        cin >> L >> R;

        // Find the index of the first village greater than or equal to L
        auto it_l = lower_bound(x + 1, x + n + 1, L);
        
        // Find the index of the first village strictly greater than R
        auto it_r = upper_bound(x + 1, x + n + 1, R);

        // Adjust indices because upper_bound returns one past the last element
        if (it_l != x + n + 1) --it_l;
        if (it_r != x + n + 1) --it_r;

        // Calculate the total number of villagers in the range [L, R]
        int l = it_l - x;
        int r = it_r - x;

        cout << sum[r] - sum[l] << endl;
    }
    return 0;
}
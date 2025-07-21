#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
long long sum[200005]; // Changed to long long to handle larger sums

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i]; // Read x values into array x
    }
    for(int i = 1; i <= n; i++){
        cin >> p[i]; // Read p values into array p, but they are not used here. Only sum is needed.
        sum[i] = sum[i - 1] + p[i]; // Calculate prefix sum of p values (although not strictly necessary)
    }
    cin >> q; // Read number of queries q
    while(q--){ // Process each query
        int L,R; // Read L and R for each query
        cin >> L >> R; // Read L and R for current query
        // Use lower_bound and upper_bound to find indices of L and R in sorted array x. Then calculate sum.
        auto l = lower_bound(x + 1, x + n + 1, L) - x; // Find index of L (inclusive)
        auto r = upper_bound(x + 1, x + n + 1, R) - x; // Find index of R (exclusive)
        // Output the sum of values in range [L, R) (inclusive L, exclusive R) using sum array.
        cout << (sum[r - 1] - sum[l - 1]) << endl; // Corrected calculation for sum in range.
    }
}
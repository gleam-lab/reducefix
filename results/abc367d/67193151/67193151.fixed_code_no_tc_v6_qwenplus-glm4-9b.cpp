#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, sum, cnt, a[N], b[N], d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    
    // Extend array 'a' by mirroring it for circular behavior
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    // Initialize the frequency array and prefix sum array
    b[0] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        if (i >= n) {
            // Decrement the count of the current modulo result
            b[d[i - n] % m]--;
        }
        
        // Update the prefix sum
        d[i] = d[i - 1] + a[i];
        
        // Add the count of the current modulo result to the sum
        sum += b[d[i] % m];
        
        if (i < n) {
            // Increment the count of the current modulo result
            b[d[i] % m]++;
        }
    }
    
    // Output the final sum
    cout << sum;
    return 0;
}
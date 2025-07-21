#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, sum, cnt, a[N], b[N], d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    
    // Initialize the array 'a' and the array 'd' to store prefix sums
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1) d[i] = d[i - 1] + a[i];
        else d[i] = a[i];
    }
    
    // Initialize the count array 'b'
    b[0] = 1;
    
    // Process and update counts and prefix sums
    for (int i = 1; i <= 2 * n; i++) {
        sum += (i >= n ? b[d[i - n] % m] : 0); // Accumulate sum based on counts of prefix sums modulo m
        
        if (i >= n) {
            b[d[i - n] % m]--; // Decrement the count of the prefix sum
        }
        d[i] = d[i - 1] + a[i % n]; // Update the prefix sum
        
        if (i < n) {
            b[d[i] % m]++; // Increment the count of the prefix sum
        }
    }
    
    cout << sum;
    return 0;
}
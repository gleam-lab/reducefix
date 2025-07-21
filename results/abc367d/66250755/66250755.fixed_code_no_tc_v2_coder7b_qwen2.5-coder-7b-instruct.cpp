#include<bits/stdc++.h>
using namespace std;

int n, m, a[400005], t[1000005], an, w[400005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[n + i] = a[i];
    }
    
    // Initialize the prefix sum array
    memset(w, 0, sizeof(w));
    
    // Iterate through the array to calculate prefix sums modulo m
    for (int i = 1; i < 2 * n; ++i) {
        w[i + 1] = (w[i] + a[i]) % m;
        
        // Adjust the count of previous prefix sums
        if (i > n) t[w[i - n]]--;
        
        // Update the answer with the current count of the prefix sum
        if (i >= n) an += t[w[i]];
        
        // Increment the count of the current prefix sum
        t[w[i]]++;
    }
    
    cout << an;
    return 0;
}
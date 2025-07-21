#include<bits/stdc++.h>
using namespace std;

int n, m, a[400005], t[1000005], an;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        // Extend the array cyclically
        a[i + n] = a[i];
    }
    // Initialize the frequency array and prefix sum array
    t[0] = 1; // There is one prefix sum (0) before the start
    int prefix_sum = 0;

    // Calculate the number of valid subarrays
    for (int i = 1; i <= 2 * n; i++) {
        // Update the prefix sum
        prefix_sum = (prefix_sum + a[i]) % m;

        // Increase the count of prefix sums with a remainder of 0
        if (prefix_sum == 0) an++;

        // If the prefix sum was seen before, we have found a subarray
        if (t[prefix_sum] > 0) an += t[prefix_sum];

        // Update the frequency array
        t[prefix_sum]++;
    }

    cout << an;
    return 0;
}
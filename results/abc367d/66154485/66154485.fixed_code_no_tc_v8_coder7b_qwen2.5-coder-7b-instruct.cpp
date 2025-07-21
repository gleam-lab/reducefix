#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Iterate over each starting point
    for (int i = 0; i < n; i++) {
        int sum = 0;
        // Iterate over each possible length of subarray starting from i
        for (int len = 1; len <= n; len++) {
            sum += arr[(i + len - 1) % n]; // Correctly calculate the index using modulo operation
            if (sum % m == 0) {
                ans++; // Increment count if sum is divisible by m
            }
        }
    }
    cout << ans << endl;
    return 0;
}
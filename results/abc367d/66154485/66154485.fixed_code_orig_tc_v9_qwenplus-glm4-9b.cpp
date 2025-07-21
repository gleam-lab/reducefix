#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, arr[200004];
    long long int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Compute prefix sums
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }
    
    // Calculate the number of times the sum of the subarray modulo m is zero
    for (int i = 0; i < n; i++) {
        long long int total = arr[i] % m;
        ans += total == 0 ? 1 : 0;
    }
    
    cout << ans;
    return 0;
}
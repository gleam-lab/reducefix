#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long ans = 0;
    
    // Check all possible contiguous subarrays
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[(i + j) % n];
            if (sum % m == 0) {
                ans++;
            }
            // Early termination if we've completed a full cycle
            if (j == n - 1) break;
        }
    }
    
    cout << ans;
    return 0;
}
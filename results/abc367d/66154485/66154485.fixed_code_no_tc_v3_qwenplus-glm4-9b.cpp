#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0, arr[200005];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Using a prefix sum approach to optimize the inner loop
    int prefixSum = 0;
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Using a sliding window approach to find all subarrays with sum % m == 0
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum = (sum + arr[j]) % m;
            if (sum == 0) {
                ans++;
            }
        }
    }
    
    cout << ans;
    return 0;
}
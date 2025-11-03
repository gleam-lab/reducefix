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
    
    // Use prefix sums to efficiently calculate subarray sums modulo m
    for (int start = 0; start < n; start++) {
        long long sum = 0;
        for (int end = 1; end <= n - 1; end++) {
            sum += arr[(start + end) % n];
            if (sum % m == 0) {
                ans++;
            }
        }
    }
    
    cout << ans;
    return 0;
}
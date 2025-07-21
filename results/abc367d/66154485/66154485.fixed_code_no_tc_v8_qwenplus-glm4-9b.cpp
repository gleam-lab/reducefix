#include <iostream>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    int arr[n];
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Compute prefix sums
    int prefixSum[n + 1];
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }
    
    // Count sums divisible by m
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            int sum = prefixSum[(i + j) % n + 1] - prefixSum[i];
            if (sum % m == 0) {
                ans++;
            }
        }
    }
    
    cout << ans;
    return 0;
}
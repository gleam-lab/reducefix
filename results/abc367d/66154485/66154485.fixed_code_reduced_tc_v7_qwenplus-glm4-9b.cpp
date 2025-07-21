#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ans = 0;
    vector<int> prefixSum(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        } else {
            prefixSum[i] = arr[i];
        }
        
        // Calculate the remainder of the current prefix sum
        int remainder = prefixSum[i] % m;
        remainder = (remainder < 0) ? remainder + m : remainder;
        
        // The number of valid subarrays starting from index i is the count of elements in prefixSum
        // which have a remainder the same as `remainder`
        for (int j = 0; j <= i; ++j) {
            int preRemainder = (prefixSum[j] < 0) ? prefixSum[j] + m : prefixSum[j];
            if (preRemainder % m == remainder) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
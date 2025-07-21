#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Use prefix sums to calculate the sum of subarrays ending at each index
    int prefixSum[n] = {0};
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    
    int ans = 0;
    
    // Use a hashmap to store the frequency of each remainder
    unordered_map<int, int> remainderCount;
    for (int i = 0; i < n; i++) {
        // Calculate the remainder of the prefix sum at index i
        int remainder = (prefixSum[i] % m + m) % m; // Adjust for negative remainders
        
        // Increment the count of this remainder
        remainderCount[remainder]++;
        
        // The number of valid subarrays ending at index i is equal to the number of times
        // the same remainder appeared before index i
        ans += remainderCount[remainder];
    }
    
    cout << ans;
    return 0;
}
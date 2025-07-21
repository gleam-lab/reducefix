#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Extend the array to handle circular wrap-around
    vector<long long> doubleArr(arr.begin(), arr.end());
    doubleArr.insert(doubleArr.end(), arr.begin(), arr.end());

    long long ans = 0;
    long long prefixSum = 0;
    map<long long, long long> modCount;
    modCount[0] = 1; // Initial condition: prefix sum 0 occurs once

    for (int i = 0; i < 2 * n; ++i) {
        prefixSum = (prefixSum + arr[i % n]) % m;
        ans += modCount[prefixSum];
        modCount[prefixSum]++;
        
        // To prevent counting full circular subarrays of length > n
        if (i >= n - 1) {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
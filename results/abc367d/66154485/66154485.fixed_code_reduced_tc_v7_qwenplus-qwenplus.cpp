#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // To handle circular arrays, duplicate the array
    vector<int> doubleArr(arr.begin(), arr.end());
    doubleArr.insert(doubleArr.end(), arr.begin(), arr.end());

    long long ans = 0;
    long long prefixSum = 0;
    unordered_map<int, int> modCount;
    modCount[0] = 1; // base case: prefix sum mod m = 0

    for (int i = 0; i < 2 * n; ++i) {
        prefixSum += doubleArr[i];
        int mod = ((prefixSum % m) + m) % m; // ensure non-negative
        ans += modCount[mod];
        modCount[mod]++;
    }

    cout << ans << endl;
    return 0;
}
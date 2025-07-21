#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long prefix = 0, ans = 0;
    unordered_map<long long, int> remainderCount;
    remainderCount[0] = 1; // To account for subarrays starting from index 0

    for (int i = 0; i < n; i++) {
        prefix += arr[i];
        long long rem = (prefix % m + m) % m; // Ensure positive remainder
        ans += remainderCount[rem];
        remainderCount[rem]++;
    }

    cout << ans;
    return 0;
}
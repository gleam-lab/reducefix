#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Iterate over each starting point
    for (int i = 0; i < n; i++) {
        int sum = 0;
        // Iterate over each possible length of subarray
        for (int j = 1; j <= n; j++) {
            sum += arr[(i + j - 1) % n]; // Adjust index to handle circular array
            if (sum % m == 0) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) { // Start from 0 to include all possible subarrays
            sum += arr[(i + j) % n];
            if (sum % m == 0)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
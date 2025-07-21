#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array to easily find the minimum and maximum values after removal
    sort(a.begin(), a.end());

    // Calculate the difference between the largest and smallest possible values of B
    int result = INT_MAX;
    for(int i = 0; i <= n - k; ++i) {
        result = min(result, a[i + k - 1] - a[i]);
    }

    // Print the minimum possible value
    cout << result << '\n';

    return 0;
}
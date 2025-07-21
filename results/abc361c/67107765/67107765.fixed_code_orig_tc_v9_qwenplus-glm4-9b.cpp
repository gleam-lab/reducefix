#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // Calculate the difference when removing K/2 smallest and K/2 largest elements
    int diff1 = a[n - k] - a[k];
    
    // Calculate the difference when removing one more smallest element
    int diff2 = a[n - k - 1] - a[k + 1];

    // Calculate the difference when removing one more largest element
    int diff3 = a[n - k - 1] - a[k];

    // The result is the minimum of the three calculated differences
    cout << min({diff1, diff2, diff3}) << endl;

    return 0;
}
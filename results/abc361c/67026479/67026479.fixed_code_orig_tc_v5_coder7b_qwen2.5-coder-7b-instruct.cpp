#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Sort the array to facilitate finding the minimum difference
    sort(a.begin(), a.end());

    // The minimum possible value of the maximum value of B minus the minimum value of B
    // is achieved by removing the largest k elements and the smallest k elements
    // because we want the difference between the maximum and minimum of the remaining elements to be minimized
    long long result = a[n - 1 - k] - a[k];

    cout << result << endl;
    return 0;
}
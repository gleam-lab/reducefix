#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // Sort the array
    sort(num.begin(), num.end());

    // Calculate the initial difference
    int diff = num[n - 1] - num[k];

    // Use sliding window to find the minimum difference
    for (int i = k; i < n; i++) {
        diff = min(diff, num[i] - num[i - k]);
    }

    cout << diff << endl;

    return 0;
}
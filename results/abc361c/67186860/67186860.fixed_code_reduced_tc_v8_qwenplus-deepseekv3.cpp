#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int min_diff = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        int j = i + (n - k) - 1;
        if (j >= n) break;
        min_diff = min(min_diff, A[j] - A[i]);
    }
    cout << min_diff << endl;
    return 0;
}
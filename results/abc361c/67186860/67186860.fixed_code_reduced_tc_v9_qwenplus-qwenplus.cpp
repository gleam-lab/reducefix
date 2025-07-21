#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We need to remove exactly K elements
    // So we will keep N - K elements in B
    int m = n - k;
    
    // To minimize the difference between max and min in B,
    // we sort A first, and then check all windows of size m.
    sort(A.begin(), A.end());
    
    long long min_diff = numeric_limits<long long>::max();
    for (int i = 0; i + m - 1 < n; ++i) {
        min_diff = min(min_diff, (long long)(A[i + m - 1] - A[i]));
    }
    
    cout << min_diff << endl;
    return 0;
}
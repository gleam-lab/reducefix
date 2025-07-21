#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long min_diff = numeric_limits<long long>::max();
    for (int i = 0; i + (n - k) <= n; ++i) {
        min_diff = min(min_diff, A[i + (n - k)] - A[i]);
    }

    cout << min_diff << endl;
    return 0;
}
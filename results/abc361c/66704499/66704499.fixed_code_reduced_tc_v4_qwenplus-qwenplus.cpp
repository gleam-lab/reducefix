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

    long long result = LLONG_MAX;
    for (int i = 0; i + (n - k) <= n; ++i) {
        result = min(result, A[i + (n - k)] - A[i]);
    }

    cout << result << endl;
    return 0;
}
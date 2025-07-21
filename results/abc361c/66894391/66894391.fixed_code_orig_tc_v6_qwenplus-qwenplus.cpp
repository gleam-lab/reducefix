#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long result = numeric_limits<long long>::max();
    for (int i = 0; i + (n - k) <= n; ++i) {
        result = min(result, A[i + (n - k)] - A[i]);
    }

    cout << result << endl;
    return 0;
}
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

    long long min_diff = numeric_limits<long long>::max();
    int window_size = n - k;

    for (int i = 0; i + window_size <= n; ++i) {
        min_diff = min(min_diff, A[i + window_size - 1] - A[i]);
    }

    cout << min_diff << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We need to remove exactly K elements to minimize the difference between
    // max and min in the remaining N-K elements

    // Try all windows of size L = N - K in the sorted array and find min difference
    int l = n - k;
    sort(A.begin(), A.end());
    int ans = A[l - 1] - A[0];

    for (int i = 1; i + l - 1 < n; ++i) {
        ans = min(ans, A[i + l - 1] - A[i]);
    }

    cout << ans << endl;
    return 0;
}
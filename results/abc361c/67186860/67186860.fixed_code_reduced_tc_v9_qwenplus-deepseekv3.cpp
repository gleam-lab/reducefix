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
        int left = i;
        int right = n - 1 - (k - i);
        if (left <= right) {
            min_diff = min(min_diff, A[right] - A[left]);
        }
    }
    cout << min_diff << endl;
    return 0;
}
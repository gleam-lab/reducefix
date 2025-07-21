#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    int window_size = n - k;
    int min_diff = INT_MAX;
    
    for (int i = 0; i + window_size <= n; i++) {
        int current_diff = A[i + window_size - 1] - A[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    
    cout << min_diff << endl;
    return 0;
}
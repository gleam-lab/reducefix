#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int needed_x = -1;
    int possible = true;
    
    // We need to match the largest N-1 toys to the largest N-1 boxes (B)
    // The remaining toy must fit into the new box x.
    // The smallest x is the size of the remaining toy (if it's the largest, otherwise we might need larger x)
    
    vector<int> unmatched_toys;
    int i = n - 1, j = n - 2;
    
    while (i >= 0 && j >= 0) {
        if (A[i] <= B[j]) {
            --i;
            --j;
        } else {
            unmatched_toys.push_back(A[i]);
            --i;
        }
    }
    
    while (i >= 0) {
        unmatched_toys.push_back(A[i]);
        --i;
    }
    
    if (unmatched_toys.size() > 1) {
        possible = false;
    } else {
        if (unmatched_toys.empty()) {
            // All toys fit into existing boxes; we can buy any box (best is min A)
            needed_x = A[0];
        } else {
            needed_x = unmatched_toys[0];
        }
    }
    
    if (!possible) {
        cout << -1 << endl;
    } else {
        cout << needed_x << endl;
    }
    
    return 0;
}
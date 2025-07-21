#include <bits/stdc++.h>
using namespace std;

bool canFit(vector<int>& A, vector<int>& B, int x) {
    vector<bool> used(B.size() + 1, false);
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] <= x && !used[B[i]]) {
            used[B[i]] = true;
        } else {
            return false;
        }
    }
    return true;
}

int minBoxSize(vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int l = 0, r = 1e9;
    while (l < r) {
        int m = (l + r) / 2;
        if (canFit(A, B, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return canFit(A, B, l) ? l : -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }
    cout << minBoxSize(A, B) << endl;
    return 0;
}
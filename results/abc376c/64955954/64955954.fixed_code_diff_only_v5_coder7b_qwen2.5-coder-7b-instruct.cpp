#include <bits/stdc++.h>
using namespace std;

bool canFit(int x, vector<int>& A, vector<int>& B) {
    vector<bool> used(A.size(), false);
    for (int i = 0; i < B.size(); ++i) {
        if (x >= B[i]) {
            int j = i + 1;
            while (j < A.size() && A[j] <= x && !used[j]) {
                used[j++] = true;
            }
        }
    }
    for (int i = 0; i < A.size(); ++i) {
        if (!used[i] && A[i] > x) return false;
    }
    return true;
}

int minBoxSize(vector<int>& A, vector<int>& B) {
    int left = 0, right = 1e9, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canFit(mid, A, B)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n-1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n-1; ++i) cin >> B[i];
    
    cout << minBoxSize(A, B) << endl;
    return 0;
}
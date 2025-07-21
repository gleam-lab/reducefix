#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
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
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int x = -1;
    vector<bool> used(n - 1, false);
    int j = 0;
    bool possible = true;
    
    for (int i = 0; i < n; ++i) {
        while (j < n - 1 && (used[j] || B[j] < A[i])) {
            ++j;
        }
        if (j < n - 1) {
            used[j] = true;
        } else {
            if (x == -1) {
                x = A[i];
            } else {
                possible = false;
                break;
            }
        }
    }
    
    if (!possible) {
        cout << -1 << '\n';
    } else {
        cout << (x == -1 ? 1 : x) << '\n';
    }
    
    return 0;
}
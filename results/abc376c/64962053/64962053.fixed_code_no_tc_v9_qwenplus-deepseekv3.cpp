#include <bits/stdc++.h>
using namespace std;

int main() {
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
    
    int additional = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (j < n - 1 && B[j] >= A[i]) {
            ++j;
        } else {
            additional = max(additional, A[i]);
        }
    }
    
    if (j + 1 >= n) {
        cout << additional << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
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
    
    vector<int> unmatched;
    int i = 0, j = 0;
    
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            unmatched.push_back(A[i]);
            ++i;
        }
    }
    
    while (i < n) {
        unmatched.push_back(A[i]);
        ++i;
    }
    
    if (unmatched.size() > 1) {
        cout << -1 << endl;
    } else if (unmatched.size() == 1) {
        cout << unmatched[0] << endl;
    } else {
        cout << A.back() << endl;
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N - 1);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> mismatch;
    int i = N - 1, j = N - 2;
    
    while (i >= 0 && j >= 0) {
        if (A[i] <= B[j]) {
            --i;
            --j;
        } else {
            mismatch.push_back(A[i]);
            --i;
        }
    }
    
    while (i >= 0) {
        mismatch.push_back(A[i]);
        --i;
    }
    
    if (mismatch.size() == 1) {
        cout << mismatch[0] << endl;
    } else if (mismatch.size() > 1) {
        cout << -1 << endl;
    } else {
        // All toys fit into existing boxes, so the new box can be of size 1 (or any <= smallest B)
        cout << 1 << endl;
    }
    
    return 0;
}
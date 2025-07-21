#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0, unmatched = 0;
    int max_unmatched = 0;
    
    while (i < N && j < N - 1) {
        if (B[j] >= A[i]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    
    if (i < N) {
        if (N - i > 1) {
            cout << -1 << endl;
            return 0;
        }
        max_unmatched = A.back();
    }
    
    cout << max_unmatched << endl;
    return 0;
}
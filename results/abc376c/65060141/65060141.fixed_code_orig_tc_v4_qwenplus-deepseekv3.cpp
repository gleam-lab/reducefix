#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int cnt = 0;
    int x = 0;
    int i = N - 1, j = N - 2;
    
    while (i >= 0 && j >= 0) {
        if (B[j] >= A[i]) {
            --i;
            --j;
        } else {
            ++cnt;
            x = max(x, A[i]);
            --i;
        }
    }
    
    while (i >= 0) {
        ++cnt;
        x = max(x, A[i]);
        --i;
    }
    
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
    
    return 0;
}
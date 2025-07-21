#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if it's possible to assign toys to boxes without the new box
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    // Find the minimal x needed
    long long x = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i + 1] > B[i]) {
            x = max(x, B[i]);
        }
    }

    x = max(x, A[0]);

    cout << x << endl;
    return 0;
}
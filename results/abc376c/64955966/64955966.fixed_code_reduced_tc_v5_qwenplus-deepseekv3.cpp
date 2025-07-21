#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int i = 0, j = 0;
    int count = 0;
    int x_candidate = -1;
    
    while (i < N && j < N-1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            if (x_candidate == -1) {
                x_candidate = A[i];
                ++i;
            } else {
                // More than one toy cannot be placed in existing boxes
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (i < N) {
        if (x_candidate == -1) {
            x_candidate = A[i];
            ++i;
        } else {
            // More than one toy left
            cout << -1 << endl;
            return;
        }
    }
    
    if (i == N && x_candidate != -1) {
        cout << x_candidate << endl;
    } else {
        // All toys are placed in existing boxes; x can be 1
        cout << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
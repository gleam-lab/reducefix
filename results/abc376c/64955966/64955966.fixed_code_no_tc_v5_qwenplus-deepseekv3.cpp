#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int j = 0;
    int x = -1;
    for (int i = 0; i < N; ++i) {
        if (j < N - 1 && A[i] <= B[j]) {
            ++j;
        } else {
            if (x == -1) {
                x = A[i];
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
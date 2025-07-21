#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());
    
    int i = 0, j = 0;
    long long x = -1;
    
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            if (x == -1) {
                x = A[i];
                ++i;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (i < N) {
        if (x == -1) {
            x = A[i];
            ++i;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    if (x != -1) {
        cout << x << endl;
    } else {
        cout << 1 << endl; // All toys fit in existing boxes, but we need at least one box, so x can be any >=1, minimal is 1.
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
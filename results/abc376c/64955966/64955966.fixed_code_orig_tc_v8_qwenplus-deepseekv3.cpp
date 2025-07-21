#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    long long x = -1;
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            if (x != -1) {
                cout << -1 << endl;
                return;
            }
            x = A[i];
            ++i;
        }
    }
    
    if (i < N) {
        if (x != -1) {
            cout << -1 << endl;
            return;
        }
        x = A.back();
    }
    
    if (x == -1) {
        // All toys fit in existing boxes, need to pick x to be any value, but since no toy is left, x can be 1
        // But the problem says x must be a positive integer, and we need to minimize x.
        // So in this case, the minimal x is 1.
        x = 1;
    } else {
        // Need to check if existing boxes can accommodate the remaining toys when x is placed
        // But since we've already processed all toys except possibly the last one, x is the minimal required.
    }
    
    // Now, verify that with x, all toys can be placed
    vector<long long> boxes = B;
    boxes.push_back(x);
    sort(boxes.begin(), boxes.end());
    
    i = 0; j = 0;
    while (i < N && j < N) {
        if (A[i] <= boxes[j]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    
    if (i == N) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
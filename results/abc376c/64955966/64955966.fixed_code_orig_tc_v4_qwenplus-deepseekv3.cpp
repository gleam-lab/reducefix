#include <bits/stdc++.h>
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
    
    multiset<int> boxes(B.begin(), B.end());
    int x_needed = -1;
    
    for (int a : A) {
        auto it = boxes.lower_bound(a);
        if (it != boxes.end()) {
            boxes.erase(it);
        } else {
            if (x_needed == -1) {
                x_needed = a;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (x_needed != -1) {
        cout << x_needed << endl;
    } else {
        // All toys fit in existing boxes. x can be 1 (since any positive x works, smallest is 1)
        cout << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
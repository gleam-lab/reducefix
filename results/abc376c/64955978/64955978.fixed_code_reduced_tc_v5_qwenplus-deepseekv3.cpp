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
    int x = -1;
    int count_new_box = 0;
    
    while (i < N && j < N-1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            if (x == -1) {
                x = A[i];
                ++i;
                ++count_new_box;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (i < N) {
        if (x == -1) {
            x = A[i];
            ++count_new_box;
            ++i;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    if (count_new_box > 1) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
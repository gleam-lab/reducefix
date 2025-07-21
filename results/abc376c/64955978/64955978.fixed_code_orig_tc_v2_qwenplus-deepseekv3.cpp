#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());
    
    int toy_ptr = 0;
    int box_ptr = 0;
    long long x = -1;
    
    while (toy_ptr < N && box_ptr < N - 1) {
        if (A[toy_ptr] <= B[box_ptr]) {
            toy_ptr++;
            box_ptr++;
        } else {
            if (x == -1) {
                x = A[toy_ptr];
                toy_ptr++;
            } else {
                // More than one toy can't be placed, so it's impossible
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (toy_ptr < N) {
        if (x == -1) {
            x = A[toy_ptr];
        } else {
            // More than one toy can't be placed, so it's impossible
            cout << -1 << endl;
            return;
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
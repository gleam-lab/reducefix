#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    int i = 0, j = 0;
    int required_x = -1;
    
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            if (required_x == -1) {
                required_x = A[i];
                ++i;
            } else {
                // More than one toy needs the new box, impossible
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    if (i < N) {
        if (required_x == -1) {
            required_x = A.back();
        } else {
            // More than one toy needs the new box, impossible
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << required_x << endl;
    return 0;
}
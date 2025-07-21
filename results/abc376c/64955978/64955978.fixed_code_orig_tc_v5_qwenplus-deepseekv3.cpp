#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    long long x = -1;
    int i = 0, j = 0;
    vector<bool> used(N - 1, false);
    
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            used[j] = true;
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    
    if (i < N) {
        if (i == N - 1) {
            x = A.back();
        } else {
            x = -1;
        }
    } else {
        x = -1;
    }
    
    if (x != -1) {
        bool possible = true;
        for (int k = 0; k < N - 1; ++k) {
            if (!used[k] && B[k] < x) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            x = -1;
        }
    }
    
    cout << x << endl;
    
    return 0;
}
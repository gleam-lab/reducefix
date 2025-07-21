#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N - 1);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    int needed_x = -1;
    int count_missing = 0;
    
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            needed_x = A[i];
            ++i;
            ++count_missing;
        }
    }
    
    while (i < N) {
        needed_x = A[i];
        ++i;
        ++count_missing;
    }
    
    if (count_missing == 1) {
        cout << needed_x << endl;
    } else if (count_missing == 0) {
        cout << -1 << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
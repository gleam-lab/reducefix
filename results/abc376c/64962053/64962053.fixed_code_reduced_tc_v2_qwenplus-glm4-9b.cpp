#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n-1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n-1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int i = 0, j = 0;
    while (j < n) { // iterate through toys
        while (i < n-1 && A[j] <= B[i]) i++; // find the smallest box that can fit the toy
        if (i == n-1) { // if no box can fit the toy
            cout << -1 << endl;
            return 0;
        }
        j++;
    }
    
    cout << B[i] << endl;
    return 0;
}
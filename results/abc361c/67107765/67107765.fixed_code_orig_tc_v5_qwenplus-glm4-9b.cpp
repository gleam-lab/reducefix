#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    int maxDiff = INT_MAX;
    
    for (int i = 0; i <= n - k; i++) {
        int minVal = A[i];
        int maxVal = A[i + k - 1];
        int diff = maxVal - minVal;
        maxDiff = min(maxDiff, diff);
    }
    
    cout << maxDiff << endl;
    return 0;
}
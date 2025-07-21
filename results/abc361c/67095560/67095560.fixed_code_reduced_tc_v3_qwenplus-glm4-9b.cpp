#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    int minRange = INT_MAX;
    
    // Calculate the range after removing K elements
    for (int i = 0; i <= N - K; ++i) {
        // Maximum value in the resulting sequence after removing K elements
        int maxVal = A[N - K + i];
        // Minimum value in the resulting sequence after removing K elements
        int minVal = A[i];
        minRange = min(minRange, maxVal - minVal);
    }
    
    cout << minRange << endl;
    
    return 0;
}
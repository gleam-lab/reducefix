#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    vector<int> A;
    
    // Read inputs
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Sort the array
    sort(A.begin(), A.end());
    
    // Calculate the minimum possible value of the maximum and minimum of the remaining sequence
    // after removing exactly K elements
    for (int i = K; i < N; i++) {
        // The minimum possible value of the maximum and minimum of the remaining sequence
        // is A[i], as we remove the last K elements from the sorted array
        cout << A[i] << endl;
        break;
    }
    
    return 0;
}
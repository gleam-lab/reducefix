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
    
    // The minimum possible value of the maximum minus the minimum of the new sequence B
    // is achieved by removing K elements that are the most out-of-range relative to each other.
    // We can do this by removing the K smallest or the K largest elements.
    // In both cases, we get the same result because we are minimizing the range.
    
    // Removing K smallest elements
    int min_val = A[K];
    int max_val = A[N - K - 1];
    
    // Output the result
    cout << max_val - min_val << endl;
    
    return 0;
}
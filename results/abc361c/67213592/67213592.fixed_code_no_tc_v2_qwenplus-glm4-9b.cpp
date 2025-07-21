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
    
    // Clone the original array to preserve the original order for final comparison
    vector<int> B = A;
    
    // Sort the array to easily find the minimum and maximum values
    sort(B.begin(), B.end());
    
    // If we remove k elements, we must consider that we might remove the smallest or largest k elements
    // We calculate the difference for two cases: ignoring the smallest k elements and the largest k elements
    int remove_min_k = B[0] - B[n-k-1]; // ignore the smallest k elements
    int remove_max_k = B[n-k] - B[n-1]; // ignore the largest k elements
    
    // The answer is the minimum of these two cases
    cout << min(remove_min_k, remove_max_k);
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Step 1: Create two sets to hold the largest and smallest elements separately.
    set<int> largest(A.begin() + K, A.end());  // Holds the largest K elements.
    set<int> smallest(A.begin(), A.begin() + N - K);  // Holds the smallest K elements.
    
    // Step 2: Calculate the maximum and minimum of the remaining elements after removing the first smallest and first largest element.
    // Since we know the input is sorted, we can directly access them.
    int remaining_max = *(largest.begin());
    int remaining_min = *(smallest.begin());
    
    // Step 3: Calculate the result as the difference between the remaining maximum and minimum.
    int result = remaining_max - remaining_min;
    
    // Output the result.
    cout << result << endl;
    
    return 0;
}
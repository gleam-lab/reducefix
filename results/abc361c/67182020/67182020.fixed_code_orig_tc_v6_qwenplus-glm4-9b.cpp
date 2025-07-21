#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    // Get the K smallest and largest elements to remove
    vector<int> to_remove;
    to_remove.insert(to_remove.end(), A.begin(), A.begin() + K / 2); // Smallest
    to_remove.insert(to_remove.end(), A.begin() + N - K / 2, A.end()); // Largest

    // If K is odd, add the middle element to the remove list
    if (K % 2 == 1) {
        to_remove.push_back(A[K / 2]);
    }

    // Calculate the minimum possible value of the difference
    // after removing the elements in 'to_remove'
    int min_diff = numeric_limits<int>::max();
    for (int i = 0; i <= N - K; ++i) {
        int diff = A[i + K - 1] - A[i];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    
    return 0;
}
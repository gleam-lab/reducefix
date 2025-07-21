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
    
    // Initialize the answer with the difference between the largest and smallest elements
    int answer = A[N - 1] - A[0];
    
    // Iterate over possible splits of the array
    for (int i = 0; i <= N - K; ++i) {
        int max_val = 0;
        int min_val = INT_MAX;
        
        // Calculate the max and min for the current split
        for (int j = i; j < i + K; ++j) {
            max_val = max(max_val, A[j]);
            min_val = min(min_val, A[j]);
        }
        
        // Update the answer if the current split gives a smaller difference
        answer = min(answer, max_val - min_val);
    }
    
    cout << answer << endl;
    
    return 0;
}
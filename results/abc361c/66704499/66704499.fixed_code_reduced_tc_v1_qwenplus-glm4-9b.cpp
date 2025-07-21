#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    // We will use prefix min and suffix max to calculate the min-max difference efficiently
    vector<int> prefix_min(N);
    vector<int> suffix_max(N);
    
    prefix_min[0] = A[0];
    for (int i = 1; i < N; i++) {
        prefix_min[i] = min(prefix_min[i-1], A[i]);
    }
    
    suffix_max[N-1] = A[N-1];
    for (int i = N-2; i >= 0; i--) {
        suffix_max[i] = max(suffix_max[i+1], A[i]);
    }
    
    int min_difference = INT_MAX;
    // Check all possible combinations of removing i smallest and K-i largest elements
    for (int i = 0; i <= K; i++) {
        if (K - i <= N - i) {
            int max_val = suffix_max[K-i];
            int min_val = prefix_min[i-1];
            min_difference = min(min_difference, max_val - min_val);
        }
    }
    
    cout << min_difference << endl;
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());

    int min_val = A[0];
    int max_val = A[N-1];
    int min_range = max_val - min_val;
    
    int remaining_to_remove = K;
    
    // We need to remove 'remaining_to_remove' elements to form the new sequence
    for (int i = 0; i < N && remaining_to_remove > 0; i++) {
        // Calculate the new range after removing A[i]
        int new_min = min_val;
        int new_max = max_val;
        
        // If we remove the element at index i
        if (i > 0) new_min = min(new_min, A[i-1]);
        if (i < N - 1) new_max = max(new_max, A[i+1]);
        
        int new_range = new_max - new_min;
        min_range = min(min_range, new_range);
        
        // Decrease the count of remaining elements to remove
        remaining_to_remove--;
    }
    
    cout << min_range << endl;
    return 0;
}
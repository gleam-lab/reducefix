#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    
    // Read input values
    for(int i=0; i<N; ++i) cin >> A[i];
    for(int i=0; i<N-1; ++i) cin >> B[i];
    
    // Sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // Check if we can place all toys into existing boxes without exceeding their sizes
    bool canPlace = true;
    for(int i=0; i<N-1; ++i){
        if(A[i] > B[i]){
            canPlace = false;
            break;
        }
    }
    
    // If we cannot place all toys, we need to buy a new box
    if(!canPlace){
        cout << -1 << '\n';
        return 0;
    }
    
    // The minimum size of the new box should be at least the largest toy size
    int minBoxSize = A[N-1];
    
    // Also check if any box can hold the largest toy
    for(int i=0; i<N-1; ++i){
        if(minBoxSize <= B[i]){
            minBoxSize = B[i];
            break;
        }
    }
    
    cout << minBoxSize << '\n';

    return 0;
}
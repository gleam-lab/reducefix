#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N-1; ++i) cin >> B[i];
    
    sort(A.rbegin(), A.rend()); // Sort sizes of toys in descending order
    sort(B.rbegin(), B.rend()); // Sort sizes of boxes in descending order
    
    // Check if we can place all toys into boxes
    for(int i = 0; i < N-1; ++i) {
        if(A[i] > B[i]) {
            cout << "-1" << endl; // Not possible to place all toys
            return 0;
        }
    }
    
    // Find the minimum box size needed to accommodate the largest toy
    int minBoxSize = A[0]; // The largest toy must fit into some box
    
    cout << minBoxSize << endl; // Output the minimum required box size
    
    return 0;
}
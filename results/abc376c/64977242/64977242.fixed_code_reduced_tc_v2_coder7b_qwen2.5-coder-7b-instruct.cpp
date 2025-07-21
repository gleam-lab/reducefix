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
    
    // Sort both arrays in descending order
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    // Find the maximum toy size that cannot fit into any box
    int minBoxSize = 0;
    for(int i = 0; i < N-1; ++i) {
        if(A[i] > B[i]) {
            minBoxSize = A[i];
            break;
        }
    }
    
    // If no such toy exists, use the largest box minus one
    if(minBoxSize == 0) minBoxSize = A[0] - 1;
    
    cout << minBoxSize << endl;
    
    return 0;
}
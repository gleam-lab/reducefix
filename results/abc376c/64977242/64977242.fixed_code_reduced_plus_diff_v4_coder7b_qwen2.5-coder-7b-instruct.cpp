#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> B(N - 1);
    
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];
    
    // Sort toy sizes and box sizes
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // Check if the largest toy can fit into the largest available box
    if (A[N - 1] <= B[N - 2]) {
        cout << B[N - 2] << endl;
    } else {
        cout << "-1" << endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);

    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.rbegin(), A.rend()); // Sort in descending order
    sort(B.begin(), B.end());    // Sort in ascending order

    int minBoxSize = -1;

    for(int i = 0; i < N - 1; ++i) {
        if(A[i] <= B[i]) { // Check if current toy can fit in the current box
            if(minBoxSize == -1 || B[i] < minBoxSize) 
                minBoxSize = B[i]; // Update the minimum box size needed
        } else {
            break; // If any toy cannot fit, we need a larger box
        }
    }

    cout << minBoxSize << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for(int i=0; i<N; ++i) cin >> A[i];
    for(int i=0; i<N-1; ++i) cin >> B[i];

    // Sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can place all toys in existing boxes
    bool canPlace = true;
    for(int i=0; i<N-1; ++i) {
        if(A[i] > B[i]) {
            canPlace = false;
            break;
        }
    }

    if(canPlace) {
        // If yes, we don't need any additional box
        cout << 0 << endl;
    } else {
        // If not, we need at least as big a box as the largest remaining toy
        int neededBoxSize = *max_element(A.begin(), A.end());
        cout << neededBoxSize << endl;
    }

    return 0;
}
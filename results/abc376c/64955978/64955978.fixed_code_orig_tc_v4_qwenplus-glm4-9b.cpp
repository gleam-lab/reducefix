#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.rbegin(), A.rend()); // Sort toys in descending order
    sort(B.rbegin(), B.rend()); // Sort boxes in descending order
    
    bool possible = true;
    int min_x = -1;
    
    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i] && A[i] > B[i + 1]) {
            // If the current toy cannot fit in the next two boxes, it's impossible
            possible = false;
            break;
        }
        // Update the minimum box size x that could fit this toy
        min_x = max(min_x, A[i]);
    }
    
    if (possible) {
        cout << min_x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
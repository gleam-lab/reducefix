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
    
    // Find the largest toy size
    int max_toy_size = *max_element(A.begin(), A.end());
    
    // Find the smallest box that can fit the largest toy
    bool found = false;
    for (int i = 0; i < N - 1; ++i) {
        if (B[i] >= max_toy_size) {
            cout << max_toy_size << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        // If no existing box can fit the largest toy, x must be at least the size of the largest toy
        cout << max_toy_size << endl;
    }
    
    return 0;
}
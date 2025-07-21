#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    
    // Read toy sizes
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    // Read box sizes
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }
    
    // Find the maximum toy size
    int maxToySize = *max_element(A.begin(), A.end());
    
    // Check if any box can fit the largest toy
    bool boxCanFit = false;
    for (int size : B) {
        if (size >= maxToySize) {
            cout << maxToySize << endl;
            return 0;
        }
        // Check if at least one box can fit any toy
        if (!boxCanFit && size > 0) {
            boxCanFit = true;
        }
    }
    
    // If no box can fit any toy, the minimum box size to buy is the size of the largest toy
    if (!boxCanFit) {
        cout << maxToySize << endl;
    } else {
        // Otherwise, any size >= maxToySize will work, so min box size is maxToySize
        cout << maxToySize << endl;
    }
    
    return 0;
}
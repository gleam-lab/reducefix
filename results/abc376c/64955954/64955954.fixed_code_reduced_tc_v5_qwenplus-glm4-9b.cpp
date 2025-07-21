#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> vb[i];
    }
    
    // Sort both lists
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    // Find the largest toy size and the smallest box size
    int max_A = va[n - 1];
    int min_B = vb[0];
    
    // If the largest toy is larger than the smallest box, it's impossible
    if (max_A > min_B) {
        cout << "-1" << endl;
        return 0;
    }
    
    // Otherwise, find the smallest box that can fit the largest toy
    for (int i = 0; i < n - 1; ++i) {
        if (vb[i] >= max_A) {
            cout << max_A << endl;
            return 0;
        }
    }
    
    // If no suitable box is found, it's impossible
    cout << "-1" << endl;
    return 0;
}
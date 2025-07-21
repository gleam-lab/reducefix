#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n - 1);
    
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }
    
    // We need to find the smallest size x such that x >= va[i] for all i and x >= vb[i] for all i.
    // This means x should be at least the maximum of all toy sizes and all box sizes.
    int required_x = *max_element(vb.begin(), vb.end());
    for (int& size : va) {
        required_x = max(required_x, size);
    }
    
    cout << required_x << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }
    
    int max_a = *max_element(va.begin(), va.end());
    int max_b = *max_element(vb.begin(), vb.end());
    
    if (max_a <= max_b) {
        cout << -1 << endl;
    } else {
        cout << max_a + 1 << endl;
    }
    
    return 0;
}
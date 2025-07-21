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

    // Find the maximum size among the existing boxes
    int max_box_size = *max_element(vb.begin(), vb.end());

    // The minimum possible size of x is either the size of the largest toy or max_box_size + 1
    int x = max_element(vb.begin(), vb.end()) - vb.begin() + 1;
    if (max_box_size < max_element(va.begin(), va.end())) {
        x = max(x, *max_element(va.begin(), va.end()) + 1);
    }

    cout << (x > max_box_size ? x : max_box_size + 1) << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; ++i) {
        cin >> b[i];
    }

    // Get the maximum size of all toys
    int max_size = *max_element(a.begin(), a.end());

    // Check if there is at least one box that can fit the maximum size
    bool can_fit = false;
    for (int size : b) {
        if (size >= max_size) {
            can_fit = true;
            break;
        }
    }

    // Print the answer
    if (can_fit) {
        cout << max_size << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
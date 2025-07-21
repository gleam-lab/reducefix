#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    int x = 0; // This will store the minimum size of the new box needed

    // We start from the largest toy and find the minimum size of the new box needed
    for (int i = n - 1; i >= 0; i--) {
        // We need to find the smallest box size that can contain this toy
        int min_box_size = b[i] + 1; // Start by considering the largest existing box size plus 1
        if (min_box_size >= a[i]) {
            x = min_box_size;
            break; // If we find a box that can fit the toy, we can stop
        }
    }

    // Check if we have a valid x
    if (x > 0) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
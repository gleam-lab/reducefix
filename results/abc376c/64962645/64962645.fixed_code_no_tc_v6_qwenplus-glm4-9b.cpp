#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> toy_sizes(n);
    vector<int> box_sizes(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> toy_sizes[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> box_sizes[i];
    }
    
    // Sort both the toy sizes and box sizes in descending order
    sort(toy_sizes.begin(), toy_sizes.end(), greater<int>());
    sort(box_sizes.begin(), box_sizes.end(), greater<int>());

    // We need to find the smallest box size that allows all toys to be placed
    // We will compare the largest box size with the smallest toy size that hasn't been placed yet
    for (int i = 0; i < n - 1; ++i) {
        if (toy_sizes[i] > box_sizes[i]) {
            cout << toy_sizes[i] << endl;
            return 0;
        }
    }
    
    // If all toys can fit in the existing boxes, we need to find the smallest box size that is not less than the largest toy size
    // This is because we need to purchase at least one more box to fit the last toy
    cout << toy_sizes[0] << endl;
    
    return 0;
}
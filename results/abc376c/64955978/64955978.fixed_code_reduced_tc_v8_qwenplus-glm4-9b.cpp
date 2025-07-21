#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N - 1);
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> b[i];
    }
    
    // Find the smallest box that can fit the smallest toy
    int min_box_size = *min_element(b.begin(), b.end());
    if (a[0] > min_box_size) {
        // If the smallest toy cannot fit into any of the existing boxes
        cout << -1 << endl;
        return 0;
    }
    
    // Check if this box size is sufficient for all toys
    for (int i = 1; i < N; i++) {
        if (a[i] > min_box_size) {
            // If any toy is larger than this box size
            cout << -1 << endl;
            return 0;
        }
    }
    
    // This box size is sufficient for all toys
    cout << min_box_size << endl;
    return 0;
}
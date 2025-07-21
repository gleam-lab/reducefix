#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> toy_sizes(N);
    for (int i = 0; i < N; ++i) {
        cin >> toy_sizes[i];
    }
    
    sort(toy_sizes.begin(), toy_sizes.end());
    
    int max_toy_size = toy_sizes[N-1];
    int current_box_size = 0;
    bool can_store_all = true;
    
    for (int i = 0; i < N; ++i) {
        if (toy_sizes[i] > max_toy_size) {
            // This toy cannot be stored in any existing box, we need a new box
            current_box_size = toy_sizes[i];
        }
        // Check if this new box can accommodate all subsequent toys
        if (current_box_size < toy_sizes[i]) {
            can_store_all = false;
            break;
        }
    }
    
    if (can_store_all) {
        cout << current_box_size << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
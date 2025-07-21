#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N], b[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; ++i) {
        cin >> b[i];
    }
    
    // Use a set to store box sizes to allow for efficient searching
    set<int> box_sizes(b + 1, b + n);
    
    int min_x = 0; // This will be the minimum x we can use
    bool can_store_all_toys = true;
    
    for (int i = 1; i <= n; ++i) {
        auto it = box_sizes.lower_bound(a[i]); // Find the first box that can contain the toy
        
        if (it == box_sizes.end() || *it < a[i]) {
            // If no box can contain the toy, or the smallest box that can contain the toy is smaller than the toy's size
            min_x = a[i]; // We need a box of size at least 'a[i]'
            can_store_all_toys = false;
            break;
        }
        
        // Remove the box that we've used
        box_sizes.erase(it);
    }
    
    if (can_store_all_toys) {
        cout << min_x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
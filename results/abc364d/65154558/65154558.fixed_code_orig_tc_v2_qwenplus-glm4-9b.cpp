#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_A = 200000005; // Maximum value offseted by 100000000

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(MAX_A, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x += 100000000; // Offset the coordinate
        a[x]++;
    }
    
    for (int i = 1; i < MAX_A; ++i) {
        a[i] += a[i - 1];
    }
    
    while (q--) {
        int x, kj;
        cin >> x >> kj;
        x += 100000000; // Offset the coordinate
        int l = 0, r = 1e8;
        
        while (l < r) {
            int mid = l + r + 1;
            if (a[mid + x] - a[x] < kj) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        
        cout << l << endl;
    }
    
    return 0;
}
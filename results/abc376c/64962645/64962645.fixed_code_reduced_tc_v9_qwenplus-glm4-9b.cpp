#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Check if the largest toy can fit into one of the existing boxes
    bool canFitInExisting = false;
    for (int i = 0; i < n - 1; ++i) {
        if (a[n - 1] <= b[i]) {
            canFitInExisting = true;
            break;
        }
    }
    
    if (!canFitInExisting) {
        cout << -1 << endl;
        return 0;
    }
    
    // Check if the smallest possible box can fit all toys
    int minBoxSize = INT_MAX;
    for (int x : a) {
        bool valid = true;
        for (int size : b) {
            if (size < x) {
                valid = false;
                break;
            }
        }
        if (valid) {
            minBoxSize = min(minBoxSize, x);
        }
    }
    
    if (minBoxSize == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minBoxSize << endl;
    }
    
    return 0;
}
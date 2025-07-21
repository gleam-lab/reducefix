#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100005; // Slightly larger than N to handle edge cases
int point[MAX_N], count[MAX_N];

int main() {
    int n, q;
    cin >> n >> q;
    
    // Read all the points A_i on the number line
    for (int i = 1; i <= n; i++) {
        cin >> point[i];
        count[i] = 1; // Initialize count array with 1
    }
    
    // Sort the points to prepare for distance calculation
    sort(point + 1, point + 1 + n);
    
    // Process each query
    for (int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;

        // Find the k-th closest point A_i to B_j
        int l = 0, r = n, mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (k <= count[mid]) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        
        // Calculate the distance between the k-th closest point and B_j
        int distance = abs(point[l] - b);
        cout << distance << endl;
    }
    
    return 0;
}
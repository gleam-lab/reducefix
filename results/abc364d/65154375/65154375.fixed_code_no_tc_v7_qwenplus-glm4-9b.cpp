#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 200010; // Sufficiently large to handle the coordinate shifts

vector<int> points;

// Function to calculate the distance between two points
int distance(int a, int b) {
    return abs(points[a] - points[b]);
}

void solve() {
    int n, q;
    cin >> n >> q;
    points.resize(n + 1);
    
    // Read points coordinates, shifting them to a non-negative range and storing them
    for (int i = 0; i < n; ++i) {
        cin >> points[i + 1];
    }
    
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        // Binary search for the k-th closest point to b
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (distance(mid, b) <= distance(mid + 1, b)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        // Output the k-th closest distance
        cout << distance(left, b) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; // Uncomment this line to accept multiple test cases
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
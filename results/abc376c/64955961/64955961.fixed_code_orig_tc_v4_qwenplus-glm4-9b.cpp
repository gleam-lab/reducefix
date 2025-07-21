#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    
    // Sort toy and box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    // Binary search to find the first box that can fit toy i
    vector<int> min_box(n, n+1); // Initialize to a size larger than possible
    int j = 0; // Index for box array
    for (int i = 0; i < n; ++i) {
        while (j < n-1 && b[j] < a[i]) j++;
        if (j < n && b[j] >= a[i]) {
            min_box[i] = min(min_box[i], b[j]);
        } else {
            // No box can fit toy i, so it needs a new box
            min_box[i] = a[i];
        }
    }

    // Find the minimum box size that can fit all toys
    int answer = n+1; // Initialize to a size larger than possible
    for (int i = 0; i < n; ++i) {
        answer = min(answer, min_box[i]);
    }

    if (answer > n) {
        cout << -1 << endl;
    } else {
        cout << answer << endl;
    }

    return 0;
}
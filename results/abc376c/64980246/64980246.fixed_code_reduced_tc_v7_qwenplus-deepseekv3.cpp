#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a) cin >> tt;
    for (auto &tt : b) cin >> tt;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<int> candidates;
    // The new box can be used to accommodate the largest unplaced toy
    // We need to find the minimal x such that all toys can be placed
    // The possible x are the toys that cannot be placed in the existing boxes
    // So, we need to find the minimal x that is >= the largest unplaced toy
    
    // Case 1: Try to place all toys except one in the existing boxes, and the last one in the new box
    // The new box must be at least the size of the unplaced toy
    // We can try to exclude each toy once and see if the remaining toys can be placed in the existing boxes
    
    // But for large N, this is O(N^2), which is not feasible
    // Instead, we can use a multiset or similar structure to efficiently check
    
    // Alternative approach:
    // Sort both arrays
    // The minimal x is the maximum of the toys that cannot be placed in the boxes
    // So, we can try to match the largest N-1 toys to the boxes, and the remaining toy is x
    
    // But we need to ensure that after excluding one toy, the remaining N-1 toys can be matched to the boxes
    // That can be checked by comparing a[i] <= b[i] for all i in 0..N-2
    
    // So, for each possible excluded toy, we can check if the remaining toys can be matched to the boxes
    
    // However, for N=2e5, this is still O(N^2)
    // Need a smarter way
    
    // The correct approach is to find the minimal x such that:
    // The new box can be used to accommodate the largest toy that cannot be placed in the existing boxes
    // And the remaining toys can be placed in the boxes
    
    // The minimal x is the smallest possible value that is >= the largest unplaced toy
    // So, we can sort the toys and boxes, and then find the first toy that cannot be placed in any box
    
    // But we need to consider that the new box can be used to place one toy
    
    // The correct approach is:
    // Sort both a and b in ascending order
    // For each i from 0 to N-1, check if a[i] can be placed in b[i] (if i < N-1)
    // If any a[i] > b[i] (with i < N-1), then this toy must be placed in the new box
    // Otherwise, the new box can be used to place the largest toy (a[N-1])
    
    // So, the minimal x is the maximum of:
    // 1. The largest toy that cannot be placed in any box (i.e., a[k] where a[k] > b[k])
    // 2. The largest toy if all others can be placed
    
    // Let's implement this logic
    
    bool possible = true;
    int cnt = 0;
    int max_unplaced = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > b[i]) {
            cnt++;
            max_unplaced = max(max_unplaced, a[i]);
        }
    }
    if (cnt > 1) {
        possible = false;
    } else if (cnt == 1) {
        // x must be at least max_unplaced
        // Check if the remaining toys can be placed with x = max_unplaced
        // But since only one toy is unplaced, and we have a new box, it's possible
        x = max_unplaced;
    } else {
        // All toys except possibly the last one can be placed
        // The new box can be used for the last toy
        x = a.back();
    }
    
    if (possible) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
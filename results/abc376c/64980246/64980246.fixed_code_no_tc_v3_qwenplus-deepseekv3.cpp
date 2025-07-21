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
    
    // We need to find the smallest x such that:
    // The new box can cover the largest A_i not covered by existing boxes,
    // and the remaining toys can be covered by the remaining boxes (including the new one if needed).
    
    // Binary search over possible x values.
    // The minimal x is the maximum of the A_i that cannot be matched to any B_i.
    // But we need to ensure that all other A_i can be matched to other B_i or the new box.
    
    // The optimal x is the largest A_i that is not matched to any B_i.
    // So, we can check for the minimal x by finding the largest A_i not matched in the optimal matching.
    
    // Let's perform a matching where we try to match as many A_i to B_i as possible.
    // The largest A_i not matched will be the candidate for x.
    
    int low = 1, high = 1e9;
    int answer = -1;
    
    // Function to check if x is feasible.
    auto isFeasible = [&](int x) {
        vector<int> boxes = b;
        boxes.push_back(x);
        sort(boxes.begin(), boxes.end());
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (a[i] <= boxes[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == n;
    };
    
    // Binary search to find the minimal x.
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isFeasible(mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << answer << endl;
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
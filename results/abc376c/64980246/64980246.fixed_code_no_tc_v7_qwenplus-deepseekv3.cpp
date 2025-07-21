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
    // The new box must be at least as large as the largest toy not fitting in any existing box
    // We need to find the minimal x such that when added to the boxes, all toys can be matched
    
    // Possible candidates for x are the largest A_i that cannot be matched to any B_i
    // We can try to find the minimal x by checking the necessary conditions
    
    int i = 0, j = 0;
    int unmatched = -1;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (unmatched == -1) {
                unmatched = a[i];
                i++;
            } else {
                // More than one toy cannot be matched, so it's impossible
                cout << -1 << endl;
                return;
            }
        }
    }
    // If there's an unmatched toy left
    if (i < n) {
        if (unmatched == -1) {
            unmatched = a[i];
        } else {
            // More than one toy cannot be matched
            cout << -1 << endl;
            return;
        }
    }
    
    // If all toys are matched, then x can be any value >=1, but the minimal is 1
    if (unmatched == -1) {
        cout << 1 << endl;
        return;
    }
    
    // Now, check if the remaining toys (excluding unmatched) can be matched to the boxes when x is 'unmatched'
    // Since we've already matched all except possibly one, the answer is 'unmatched'
    cout << unmatched << endl;
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
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    long long ans = 0;
    vector<int> counts;
    int current_count = 1;
    
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            current_count++;
        } else {
            counts.push_back(current_count);
            current_count = 1;
        }
    }
    counts.push_back(current_count);
    
    // Calculate initial answer
    for (int cnt : counts) {
        ans += cnt / 2;
    }
    
    // Additional optimization if needed
    if (counts.size() >= 3) {
        for (int i = 1; i < counts.size()-1; ++i) {
            if (counts[i] == 1 && counts[i-1] % 2 == 1 && counts[i+1] % 2 == 1) {
                ans++;
                i++;  // Skip next as we've merged
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
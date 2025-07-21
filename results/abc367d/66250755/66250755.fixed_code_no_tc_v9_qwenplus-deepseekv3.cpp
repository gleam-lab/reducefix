#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> prefix(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    for (int i = 1; i <= 2 * n; i++) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }
    
    unordered_map<int, int> count;
    count[0] = 1;  // Empty prefix sum
    int result = 0;
    
    for (int i = 1; i <= 2 * n; i++) {
        if (i > n) {
            // Remove the prefix sum that's now out of window
            int out_window = prefix[i - n - 1];
            count[out_window]--;
            if (count[out_window] == 0) {
                count.erase(out_window);
            }
        }
        
        // Check if current prefix sum exists in count
        result += count[prefix[i]];
        
        // Add current prefix sum to count
        count[prefix[i]]++;
    }
    
    cout << result << endl;
    return 0;
}
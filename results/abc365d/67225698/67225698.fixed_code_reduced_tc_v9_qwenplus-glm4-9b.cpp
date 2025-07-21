#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> counts;
        int count = 1, prev_char = s[0];
        
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                counts.push_back(count);
                count = 1;
                prev_char = s[i];
            }
        }
        counts.push_back(count);
        
        int ans = 0;
        for (int i = 0; i < counts.size(); ++i) {
            ans += (counts[i] + 1) / 2;
        }
        
        // Adjust for the middle element in odd counts
        ans = ans - (counts.size() % 2 == 1 ? 1 : 0);
        
        cout << ans << '\n';
    }
    return 0;
}
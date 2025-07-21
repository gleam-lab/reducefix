#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s(n + 1), t(n + 1);
    cin >> s;
    
    // Convert the input string to lowercase for uniformity
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    // Create a copy of the original string
    t = s;
    
    // Replace all 'p' with 's', 'r' with 'p', and 's' with 'r'
    replace(t.begin(), t.end(), 'p', 't');
    replace(t.begin(), t.end(), 'r', 'p');
    replace(t.begin(), t.end(), 's', 'r');
    
    // Initialize variables to count the maximum number of moves
    int cnt = 0, ans = 0;
    
    // Iterate through the string to find pairs that can be swapped
    for (int i = 1; i <= n; ++i) {
        if (s[i] != t[i]) {
            ++cnt;
            while (i < n && s[i + 1] == t[i]) {
                ++i;
            }
        }
    }
    
    // The maximum number of moves is half the number of mismatched pairs
    ans = cnt / 2;
    
    cout << ans << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int countPalindromes(const string &s) {
    int n = s.length();
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        // Odd length palindromes
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        
        // Even length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
    
    return count;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << countPalindromes(s) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
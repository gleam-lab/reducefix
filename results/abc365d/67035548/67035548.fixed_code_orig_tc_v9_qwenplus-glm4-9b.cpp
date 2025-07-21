#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 1; // At least one move can be made as the initial move
    int sub = 1; // Subsequence will also have at least one move
    
    // Determine the length of the string since we are using it
    int len = s.length();

    // Go through the string to find the longest increasing and decreasing subsequences
    for (int i = 1; i < len; ++i) {
        if (s[i - 1] == 'P' && s[i] == 'R') {
            ++ans;
        } else if (s[i - 1] == 'S' && s[i] == 'P') {
            ++ans;
        } else if (s[i - 1] == 'R' && s[i] == 'S') {
            ++ans;
        }
    }
    
    // Reverse the string to find the longest increasing and decreasing subsequences from the end
    for (int i = len - 2; i >= 0; --i) {
        if (s[i] == 'P' && s[i + 1] == 'R') {
            ++sub;
        } else if (s[i] == 'S' && s[i + 1] == 'P') {
            ++sub;
        } else if (s[i] == 'R' && s[i + 1] == 'S') {
            ++sub;
        }
    }
    
    // Output the maximum of the two subsequences
    cout << max(ans, sub);
    return 0;
}
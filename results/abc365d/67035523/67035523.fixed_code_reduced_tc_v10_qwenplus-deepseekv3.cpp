#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int changes = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            changes++;
            // Change s[i] to a different character
            if (s[i] == 'R') {
                s[i] = 'P';
            } else if (s[i] == 'P') {
                s[i] = 'S';
            } else {
                s[i] = 'R';
            }
            // Ensure the next character is also different if it's the same as the new s[i]
            if (i + 1 < n && s[i] == s[i + 1]) {
                if (s[i + 1] == 'R') {
                    s[i + 1] = 'P';
                } else if (s[i + 1] == 'P') {
                    s[i + 1] = 'S';
                } else {
                    s[i + 1] = 'R';
                }
            }
        }
    }
    
    cout << changes << endl;
    return 0;
}
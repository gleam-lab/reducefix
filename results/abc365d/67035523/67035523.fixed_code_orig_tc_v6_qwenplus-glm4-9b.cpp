#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cmp(char x, char y) {
    if(x == 'P') return y == 'P' ? 0 : (y == 'R' ? 1 : -1);
    if(x == 'R') return y == 'P' ? -1 : (y == 'R' ? 0 : 1);
    if(x == 'S') return y == 'P' ? -1 : (y == 'R' ? 1 : 0);
    return -100;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char prev = 'A'; // Initialize to a character that won't be in the input.

    for (int i = 0; i < n; ++i) {
        if (prev != s[i]) {
            ans++;
        }
        prev = s[i];
    }

    cout << ans << endl;
    return 0;
}
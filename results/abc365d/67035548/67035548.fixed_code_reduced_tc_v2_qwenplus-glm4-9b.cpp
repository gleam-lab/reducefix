#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') return y == 'S' ? 1 : (y == 'P' ? 0 : -1);
    if (x == 'R') return y == 'P' ? 1 : (y == 'R' ? 0 : -1);
    if (x == 'S') return y == 'R' ? 1 : (y == 'S' ? 0 : -1);
    return -100; // This case won't occur as 'X' is not used for comparison
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    return 'S';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<char> v(s.begin(), s.end());

    int ans = 0;
    char prev = 'X'; // Start with 'X' to handle the edge case where the first element in the string wins

    for (int i = 0; i < n; i++) {
        if (prev != win(v[i])) {
            ans++;
            prev = win(v[i]);
        }
    }

    cout << ans;
    return 0;
}
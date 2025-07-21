#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    char last = 'N'; // Indicates no previous move
    int ans = 0;
    for (char c : S) {
        if (c == 'R') {
            if (last != 'P') {
                ans++;
                last = 'P';
            } else {
                last = 'R';
            }
        } else if (c == 'P') {
            if (last != 'S') {
                ans++;
                last = 'S';
            } else {
                last = 'P';
            }
        } else if (c == 'S') {
            if (last != 'R') {
                ans++;
                last = 'R';
            } else {
                last = 'S';
            }
        }
    }
    cout << ans << endl;
    return 0;
}
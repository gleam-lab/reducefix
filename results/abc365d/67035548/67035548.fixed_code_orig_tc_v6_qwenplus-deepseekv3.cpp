#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    char prev = 'X';

    for (int i = 0; i < n; ++i) {
        char current = s[i];
        char optimal = win(current);
        if (optimal != prev) {
            ++ans;
            prev = optimal;
        } else {
            if (i + 1 < n) {
                char next = s[i + 1];
                char next_optimal = win(next);
                if (next_optimal != optimal) {
                    prev = next_optimal;
                } else {
                    prev = current;
                }
            }
        }
    }

    prev = 'X';
    int ans2 = 0;

    for (int i = n - 1; i >= 0; --i) {
        char current = s[i];
        char optimal = win(current);
        if (optimal != prev) {
            ++ans2;
            prev = optimal;
        } else {
            if (i - 1 >= 0) {
                char next = s[i - 1];
                char next_optimal = win(next);
                if (next_optimal != optimal) {
                    prev = next_optimal;
                } else {
                    prev = current;
                }
            }
        }
    }

    cout << max(ans, ans2) << endl;
    return 0;
}
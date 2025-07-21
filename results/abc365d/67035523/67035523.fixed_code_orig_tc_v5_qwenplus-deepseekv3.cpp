#include <iostream>
#include <string>

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

    for (int i = 0; i < n; ) {
        char current = s[i];
        char w = win(current);
        if (w != prev) {
            ans++;
            prev = w;
            i++;
        } else {
            // Look ahead to find the next different move to decide whether to switch or not
            int j = i + 1;
            while (j < n && s[j] == current) {
                j++;
            }
            if (j < n) {
                char next = s[j];
                char next_w = win(next);
                if (next_w != prev) {
                    prev = next_w;
                    ans += (j - i);
                    i = j;
                } else {
                    prev = current;
                    i = j;
                }
            } else {
                i = j;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // fallback, shouldn't happen
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> forward(n, 0);
    char prev_forward = win(s[0]);
    forward[0] = 1;
    for (int i = 1; i < n; ++i) {
        char current_win = win(s[i]);
        if (current_win != prev_forward) {
            forward[i] = forward[i - 1] + 1;
            prev_forward = current_win;
        } else {
            forward[i] = forward[i - 1];
        }
    }

    vector<int> backward(n, 0);
    char prev_backward = win(s[n - 1]);
    backward[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        char current_win = win(s[i]);
        if (current_win != prev_backward) {
            backward[i] = backward[i + 1] + 1;
            prev_backward = current_win;
        } else {
            backward[i] = backward[i + 1];
        }
    }

    int max_wins = max(forward[n - 1], backward[0]);
    for (int i = 0; i < n - 1; ++i) {
        max_wins = max(max_wins, forward[i] + backward[i + 1]);
    }

    cout << max_wins << endl;
    return 0;
}
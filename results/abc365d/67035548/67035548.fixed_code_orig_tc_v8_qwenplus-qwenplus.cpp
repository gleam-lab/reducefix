#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return 'X'; // Placeholder, should not be reached
}

int compute_max_wins(const string& s) {
    int n = s.size();
    int count1 = 0, count2 = 0;
    char last1 = 'X', last2 = 'X';

    // Forward pass
    for (int i = 0; i < n; ++i) {
        char win_move = winning_move(s[i]);
        if (win_move != last1) {
            ++count1;
            last1 = win_move;
        } else {
            last1 = s[i];
        }
    }

    // Backward pass
    for (int i = n - 1; i >= 0; --i) {
        char win_move = winning_move(s[i]);
        if (win_move != last2) {
            ++count2;
            last2 = win_move;
        } else {
            last2 = s[i];
        }
    }

    return max(count1, count2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    cout << compute_max_wins(s) << endl;

    return 0;
}
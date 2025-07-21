#include <iostream>
#include <string>

int cmp(char x, char y) {
    if (x == 'P') {
        if (y == 'P') return 0;
        if (y == 'R') return 1;
        if (y == 'S') return -1;
    }
    if (x == 'R') {
        if (y == 'P') return -1;
        if (y == 'R') return 0;
        if (y == 'S') return 1;
    }
    if (x == 'S') {
        if (y == 'P') return 1;
        if (y == 'R') return -1;
        if (y == 'S') return 0;
    }
    return -100; // 'X' loses
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // 'X' cannot win
}

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int max_streak = 0;
    int current_streak = 0;

    for (int i = 0; i < n; ++i) {
        // Calculate winning streak
        if (s[i] == 'X') {
            current_streak = 0;
        } else {
            char next_char = (i == n - 1) ? 'X' : s[i + 1];
            if (cmp(s[i], next_char) == 1) { // current wins against next
                ++current_streak;
                max_streak = std::max(max_streak, current_streak);
            } else {
                current_streak = 0;
            }
        }
    }

    std::cout << max_streak << std::endl;
    return 0;
}
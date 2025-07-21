#include <iostream>
#include <string>
using namespace std;

// Function to determine the winner based on the game rules
char getWinner(char x, char y) {
    if (x == 'P') {
        if (y == 'P') return 'D'; // Draw
        if (y == 'R') return 'W'; // Rock wins against Paper
        if (y == 'S') return 'L'; // Scissors win against Paper
    }
    if (x == 'R') {
        if (y == 'P') return 'L'; // Paper wins against Rock
        if (y == 'R') return 'D'; // Draw
        if (y == 'S') return 'W'; // Rock wins against Scissors
    }
    if (x == 'S') {
        if (y == 'P') return 'W'; // Scissors win against Paper
        if (y == 'R') return 'L'; // Rock wins against Scissors
        if (y == 'S') return 'D'; // Draw
    }
    return 'N'; // Invalid input
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (getWinner(s[i-1], s[i]) != 'D') {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
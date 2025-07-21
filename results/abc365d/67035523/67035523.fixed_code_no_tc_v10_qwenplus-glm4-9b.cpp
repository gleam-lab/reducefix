#include <iostream>
#include <string>

using namespace std;

int cmp(char x, char y) {
    if (x == 'R') return y == 'P' ? -1 : 1;
    if (x == 'P') return y == 'S' ? -1 : 1;
    if (x == 'S') return y == 'R' ? -1 : 1;
    return -100; // Non-playable character
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'P') return 'R';
    if (x == 'S') return 'S';
    return 'X'; // Non-playable character
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int answer = 1; // Initialize to 1 because the first character starts a new sequence
    char previous = s[0]; // Start with the first character

    for (int i = 1; i < n; ++i) { // Start from the second character
        if (cmp(previous, s[i]) != 0) { // If the characters do not have the same outcome
            answer++; // Increment the answer
            previous = s[i]; // Update the previous character to the current
        }
    }

    cout << answer;
    return 0;
}
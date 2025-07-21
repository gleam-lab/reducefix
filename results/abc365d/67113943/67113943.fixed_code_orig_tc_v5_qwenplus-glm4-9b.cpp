#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;

    int wins = 0;
    char prev = 'a';

    for (char c : S) {
        // Determine the winning move
        if (prev == 'R' && c == 'S') {
            wins++;
        } else if (prev == 'S' && c == 'P') {
            wins++;
        } else if (prev == 'P' && c == 'R') {
            wins++;
        }
        // Update previous character
        prev = c;
    }

    cout << wins;

    return 0;
}
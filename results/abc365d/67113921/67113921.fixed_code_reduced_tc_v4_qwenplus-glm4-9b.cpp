#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev = 'a';
    for (char c : S) {
        if (prev == 'R' && c == 'P') {
            wins++;
            prev = 'P';
        } else if (prev == 'P' && c == 'S') {
            wins++;
            prev = 'S';
        } else if (prev == 'S' && c == 'R') {
            wins++;
            prev = 'R';
        } else if (prev == c) {
            prev = 'a'; // Reset to 'a' if the same move appears consecutively
        } else {
            prev = c;
        }
    }
    cout << wins;
    return 0;
}
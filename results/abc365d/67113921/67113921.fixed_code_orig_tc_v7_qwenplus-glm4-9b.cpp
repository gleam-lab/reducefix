#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N; // Read the length of the string (not used in the code)
    cin >> S;

    int wins = 0;
    char winmove, prev = 'a';
    for (char c : S) {
        if (c == 'R') {
            winmove = 'S';
        } else if (c == 'P') {
            winmove = 'R';
        } else if (c == 'S') {
            winmove = 'P';
        }
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            prev = c;
        }
    }
    cout << wins;
}
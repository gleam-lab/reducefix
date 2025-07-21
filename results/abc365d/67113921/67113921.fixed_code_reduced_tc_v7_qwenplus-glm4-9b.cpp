#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char winmove, prev = 'a';
    for (char c : S) {
        if (c == 'R' && prev != 'S') {
            winmove = 'P';
        } else if (c == 'P' && prev != 'R') {
            winmove = 'S';
        } else if (c == 'S' && prev != 'P') {
            winmove = 'R';
        } else {
            continue;
        }
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            prev = c;
        }
    }
    cout << wins;
    return 0;
}
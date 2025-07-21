#include <iostream>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;

    int wins = 0;
    char winmove, prev = 'a';
    for (char c : S) {
        switch (c) {
            case 'R': winmove = 'P'; break;
            case 'P': winmove = 'S'; break;
            case 'S': winmove = 'R'; break;
        }
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            prev = c;
        }
    }
    cout << wins << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;

    int wins = 0;
    char winmove = 'R';
    char prev = 'a';
    for (char c : S) {
        if (prev == 'R' && c == 'P') {
            wins++;
        } else if (prev == 'P' && c == 'R') {
            wins++;
        } else if (prev == 'S' && c == 'P') {
            wins++;
        }
        prev = c;
    }

    cout << wins;

    return 0;
}
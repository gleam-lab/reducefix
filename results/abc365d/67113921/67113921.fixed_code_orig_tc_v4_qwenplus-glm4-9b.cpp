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
        if (c == 'R') {
            if (prev == 'S') {
                wins++;
            } else {
                prev = 'R';
            }
        } else if (c == 'P') {
            if (prev == 'R') {
                wins++;
            } else {
                prev = 'P';
            }
        } else if (c == 'S') {
            if (prev == 'P') {
                wins++;
            } else {
                prev = 'S';
            }
        }
    }
    cout << wins;
}
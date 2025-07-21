#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N; // Read the number of moves, but this is not used in the logic
    cin >> S;

    int wins = 0;
    char prev = 'a';
    for (char c : S) {
        if (c == 'R') {
            if (prev == 'P') wins++;
            prev = 'R';
        } else if (c == 'P') {
            if (prev == 'S') wins++;
            prev = 'P';
        } else if (c == 'S') {
            if (prev == 'R') wins++;
            prev = 'S';
        }
    }

    cout << wins;
    return 0;
}
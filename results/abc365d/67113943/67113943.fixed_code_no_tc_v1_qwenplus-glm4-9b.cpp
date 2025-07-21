#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;

    int wins = 0;
    char last_move = 'a', current_move = 'a';

    for (int i = 0; i < N - 1; i++) {
        if (S[i] == 'R' && S[i + 1] == 'P') {
            wins++;
        } else if (S[i] == 'P' && S[i + 1] == 'S') {
            wins++;
        } else if (S[i] == 'S' && S[i + 1] == 'R') {
            wins++;
        }
    }

    cout << wins;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev = S[0];
    for (int i = 1; i < N; ++i) {
        char c = S[i];
        if ((prev == 'R' && c == 'P') || (prev == 'P' && c == 'S') || (prev == 'S' && c == 'R')) {
            wins++;
        }
        prev = c;
    }
    cout << wins;
}
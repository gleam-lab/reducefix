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

    for (int i = 1; i < S.length(); i++) {
        if ((S[i] == 'R' && S[i-1] == 'P') ||
            (S[i] == 'P' && S[i-1] == 'S') ||
            (S[i] == 'S' && S[i-1] == 'R')) {
            wins++;
        }
    }

    cout << wins;

    return 0;
}
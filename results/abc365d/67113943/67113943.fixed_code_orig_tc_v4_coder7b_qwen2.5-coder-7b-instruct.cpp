#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev = 'A'; // Initialize with a character not present in 'RPS'
    
    for (char c : S) {
        char winmove;
        if (c == 'R') winmove = 'P';
        else if (c == 'P') winmove = 'S';
        else winmove = 'R';

        if (winmove != prev) {
            wins++;
            prev = winmove;
        }
    }

    cout << wins << endl;
    return 0;
}
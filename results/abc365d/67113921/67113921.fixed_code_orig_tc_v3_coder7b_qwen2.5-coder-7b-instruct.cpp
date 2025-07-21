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
    char winmove, prev = 'A'; // Initialize prev with a character that is not 'R', 'P', or 'S'
    
    for (char c : S) {
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }
        
        // Check if the current move beats the previous one
        if ((prev == 'R' && c == 'P') || (prev == 'P' && c == 'S') || (prev == 'S' && c == 'R')) {
            wins++;
        }
        prev = c;
    }

    cout << wins << endl;
    return 0;
}
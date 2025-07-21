#include <iostream>
#include <string>
using namespace std;

char winning_move(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int max_wins = 0;
    char current_move = 'X'; // initialize with invalid move
    
    for (int i = 0; i < n; i++) {
        char optimal = winning_move(s[i]);
        if (optimal != current_move) {
            max_wins++;
            current_move = optimal;
        }
    }
    
    cout << max_wins << endl;
    return 0;
}
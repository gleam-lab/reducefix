#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char getWinningMove(char move) {
    switch (move) {
        case 'R': return 'P';
        case 'P': return 'S';
        case 'S': return 'R';
        default: return move;
    }
}

int calculateMaxWins(const string& s) {
    if (s.empty()) return 0;
    
    int count = 1;
    char current = getWinningMove(s[0]);
    
    for (size_t i = 1; i < s.size(); ++i) {
        if (getWinningMove(s[i]) != current) {
            count++;
            current = getWinningMove(s[i]);
        }
    }
    
    return count;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int forwardWins = calculateMaxWins(s);
    reverse(s.begin(), s.end());
    int backwardWins = calculateMaxWins(s);
    
    cout << max(forwardWins, backwardWins) << endl;
    
    return 0;
}
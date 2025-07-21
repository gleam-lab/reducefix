#include <iostream>
#include <string>
using namespace std;

char getWinner(char x) {
    if (x == 'R') return 'P';
    if (x == 'P') return 'S';
    if (x == 'S') return 'R';
    return 'X'; // default case, though input is expected to be R, P, or S
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int changes = 0;
    
    for (int i = 1; i < n; ++i) {
        if (getWinner(s[i-1]) != s[i]) {
            changes++;
            s[i] = getWinner(s[i-1]);
        }
    }
    
    cout << changes << endl;
    return 0;
}
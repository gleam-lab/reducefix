#include <iostream>
#include <string>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // placeholder for invalid input
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int changes = 0;
    char prev = win(s[0]);
    
    for (int i = 1; i < n; ++i) {
        char current = s[i];
        char optimal = win(prev);
        
        if (current != optimal) {
            changes++;
            prev = optimal;
        } else {
            prev = current;
        }
    }
    
    cout << changes << endl;
    return 0;
}
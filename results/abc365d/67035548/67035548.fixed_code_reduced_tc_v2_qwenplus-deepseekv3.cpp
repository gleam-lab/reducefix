#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int switches = 0;
    char current = win(s[0]);
    
    for (int i = 1; i < n; ++i) {
        if (win(s[i]) != current) {
            switches++;
            current = win(s[i]);
        }
    }
    
    cout << switches + 1 << endl;
    return 0;
}
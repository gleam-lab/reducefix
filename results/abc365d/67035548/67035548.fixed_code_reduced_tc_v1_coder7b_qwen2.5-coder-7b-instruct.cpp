#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int wins = 0;
    char last_move = 'A'; // Initialize with a value not present in the set {R, P, S}
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R' && last_move != 'P' || s[i] == 'P' && last_move != 'S' || s[i] == 'S' && last_move != 'R') {
            wins++;
        }
        last_move = s[i];
    }
    
    cout << wins << endl;
    return 0;
}
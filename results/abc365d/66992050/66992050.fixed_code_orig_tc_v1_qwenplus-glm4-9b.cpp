#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    char current = 'N'; // Initial state should be 'N' which is not 'P', 'R', or 'S'
    int ans = 0;
    
    for(char c : S) {
        if (c == 'P') {
            if (current == 'N' || current == 'R') {
                ans++;
                current = 'P';
            }
        } else if (c == 'R') {
            if (current == 'N' || current == 'S') {
                ans++;
                current = 'R';
            }
        } else if (c == 'S') {
            if (current == 'N' || current == 'P') {
                ans++;
                current = 'S';
            }
        }
    }
    
    cout << ans;
    return 0;
}
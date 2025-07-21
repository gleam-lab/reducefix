#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int count = 0;
    bool last_was_S = false;
    
    for (char c : s) {
        if (c == 'P' && !last_was_S) {
            count++;
            last_was_S = true;
        } else if (c == 'R') {
            count++;
            last_was_S = false;
        } else if (c == 'S' && last_was_S) {
            count++;
            last_was_S = false;
        }
    }
    
    cout << count << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Forward pass: start with first character's winner
    vector<char> forward_seq;
    char last = win(s[0]);
    forward_seq.push_back(last);
    
    for (int i = 1; i < n; i++) {
        char desired = win(s[i]);
        if (desired != last) {
            last = desired;
            forward_seq.push_back(last);
        }
    }
    
    // Backward pass: start from end with last character's winner
    vector<char> backward_seq;
    last = win(s[n-1]);
    backward_seq.push_back(last);
    
    for (int i = n-2; i >= 0; i--) {
        char desired = win(s[i]);
        if (desired != last) {
            last = desired;
            backward_seq.push_back(last);
        }
    }
    
    // Answer is the maximum length of the two sequences
    cout << max(forward_seq.size(), backward_seq.size()) << endl;
    
    return 0;
}
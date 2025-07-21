#include <iostream>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    
    int wins = 0;
    char prev = 'a';
    for (int i = 0; i < N; ++i) {
        char c = S[i];
        if (prev == 'R') {
            if (c == 'P') wins++;
        } else if (prev == 'P') {
            if (c == 'S') wins++;
        } else if (prev == 'S') {
            if (c == 'R') wins++;
        }
        prev = c;
    }
    
    cout << wins;
    return 0;
}
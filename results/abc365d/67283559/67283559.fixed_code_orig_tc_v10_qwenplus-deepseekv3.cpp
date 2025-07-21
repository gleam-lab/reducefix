#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int total = 0;
    char prev = '\0';
    
    for (int i = 0; i < N; i++) {
        char current = S[i];
        if (prev != current) {
            if (current == 'R') {
                total += (S[i+1] == 'S');
            } else if (current == 'P') {
                total += (S[i+1] == 'R');
            } else if (current == 'S') {
                total += (S[i+1] == 'P');
            }
            prev = current;
        } else {
            prev = '\0';
        }
    }
    
    cout << total << endl;
    return 0;
}
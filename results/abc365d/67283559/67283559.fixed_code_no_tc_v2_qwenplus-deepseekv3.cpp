#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int total1 = 0;
    char prev1 = '\0';
    for (int i = 0; i < N; i++) {
        char current;
        if (prev1 == '\0') {
            // First move, choose any winning move if possible
            if (S[i] == 'R') current = 'P';
            else if (S[i] == 'P') current = 'S';
            else if (S[i] == 'S') current = 'R';
            else current = S[i]; // shouldn't happen
        } else {
            // Choose any winning move except previous
            if (S[i] == 'R' && prev1 != 'P') current = 'P';
            else if (S[i] == 'P' && prev1 != 'S') current = 'S';
            else if (S[i] == 'S' && prev1 != 'R') current = 'R';
            else current = S[i]; // no winning move available that's not previous
        }
        
        if ((current == 'R' && S[i] == 'S') || 
            (current == 'P' && S[i] == 'R') || 
            (current == 'S' && S[i] == 'P')) {
            total1++;
        }
        prev1 = current;
    }
    
    int total2 = 0;
    char prev2 = '\0';
    for (int i = 0; i < N; i++) {
        char current;
        if (prev2 == '\0') {
            // For alternative strategy, choose different first move
            if (S[i] == 'R') current = 'S'; // different from first strategy
            else if (S[i] == 'P') current = 'R';
            else if (S[i] == 'S') current = 'P';
            else current = S[i];
        } else {
            // Choose any winning move except previous
            if (S[i] == 'R' && prev2 != 'P') current = 'P';
            else if (S[i] == 'P' && prev2 != 'S') current = 'S';
            else if (S[i] == 'S' && prev2 != 'R') current = 'R';
            else current = S[i];
        }
        
        if ((current == 'R' && S[i] == 'S') || 
            (current == 'P' && S[i] == 'R') || 
            (current == 'S' && S[i] == 'P')) {
            total2++;
        }
        prev2 = current;
    }
    
    cout << max(total1, total2);
    return 0;
}
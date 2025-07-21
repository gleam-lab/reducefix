#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int total = 0;
    char last = '\0';
    
    for (int i = 0; i < N; i++) {
        char current = S[i];
        char choice;
        
        if (last != 'R' && (current == 'S')) {
            choice = 'R';
        } else if (last != 'P' && (current == 'R')) {
            choice = 'P';
        } else if (last != 'S' && (current == 'P')) {
            choice = 'S';
        } else {
            // Choose any valid move that doesn't match last, prioritizing winning moves
            if (last != 'R') choice = 'R';
            else if (last != 'P') choice = 'P';
            else choice = 'S';
        }
        
        if ((choice == 'R' && current == 'S') || 
            (choice == 'P' && current == 'R') || 
            (choice == 'S' && current == 'P')) {
            total++;
        }
        
        last = choice;
    }
    
    cout << total;
    return 0;
}
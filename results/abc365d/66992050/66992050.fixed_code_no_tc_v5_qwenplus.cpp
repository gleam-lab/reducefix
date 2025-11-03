#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    char last_throw = 'N'; // Last throw in the sequence we're building
    int changes = 0;       // Number of changes needed
    
    for (char c : S) {
        if (c == 'P') {
            // Paper beats Rock, so previous should be Rock ('R')
            if (last_throw != 'R') {
                changes++;
                last_throw = 'R';
            } else {
                last	throw = 'P';
            }
        }
        else if (c == 'R') {
            // Rock beats Scissors, so previous should be Scissors ('S')
            if (last_throw != 'S') {
                changes++;
                last_throw = 'S';
            } else {
                last_throw = 'R';
            }
        }
        else if (c == 'S') {
            // Scissors beats Paper, so previous should be Paper ('P')
            if (last_throw != 'P') {
                changes++;
                last_throw = 'P';
            } else {
                last_throw = 'S';
            }
        }
    }
    
    cout << changes;
    return 0;
}
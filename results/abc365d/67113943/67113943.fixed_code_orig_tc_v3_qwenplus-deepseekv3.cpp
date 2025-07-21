#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char prev = '\0';
    
    for (int i = 0; i < N; ++i) {
        char current = S[i];
        char counter;
        
        if (current == 'R') {
            counter = 'P';
        } else if (current == 'P') {
            counter = 'S';
        } else { // 'S'
            counter = 'R';
        }
        
        if (counter != prev) {
            wins++;
            prev = counter;
        } else {
            // Check the next move to decide if we should change the counter
            if (i + 1 < N) {
                char next = S[i + 1];
                char next_counter;
                
                if (next == 'R') {
                    next_counter = 'P';
                } else if (next == 'P') {
                    next_counter = 'S';
                } else { // 'S'
                    next_counter = 'R';
                }
                
                if (next_counter != counter) {
                    prev = '\0'; // Reset to allow a change in the next step
                } else {
                    prev = counter; // Stay the same to maximize future wins
                }
            }
        }
    }
    
    cout << wins << endl;
    return 0;
}
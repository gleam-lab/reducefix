#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev = 'a';
    char move = 'a'; // This keeps track of the current winning move

    for (char c : S){
        if (c == 'R') move = 'P';
        else if (c == 'P') move = 'S';
        else if (c == 'S') move = 'R';
        
        if (c != move) { // A non-winning move is when the current move does not win against the previous move
            wins++;
            prev = move; // Update previous winning move
        } else {
            prev = c; // Update previous move to the current move if it is a winning move
        }
    }   
    cout << wins;
}
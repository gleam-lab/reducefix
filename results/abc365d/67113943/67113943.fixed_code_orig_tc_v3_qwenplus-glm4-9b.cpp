#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char winmove = 'a', prev = 'a';
    bool start_of_sequence = true; // New variable to track start of a sequence

    for (char c : S){
        if (c == 'R') winmove = 'P';
        else if (c == 'P') winmove = 'S';
        else if (c == 'S') winmove = 'R';

        if (start_of_sequence || winmove != prev){
            wins++; // Increment `wins` when a new sequence starts or when a new character is encountered
            start_of_sequence = false; // Update the start of sequence flag
        } else {
            prev = c; // Update `prev` only when it's not a new sequence start
        }
    }
    cout << wins;
}
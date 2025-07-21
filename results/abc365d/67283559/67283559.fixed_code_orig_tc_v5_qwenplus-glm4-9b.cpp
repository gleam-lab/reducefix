#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Initialize the score and the next hand vector.
    int total = 0;
    vector<char> next = {'R', 'P', 'S'};

    // First half loop
    for (int i = 0; i < N / 2; i++) {
        // Calculate the index of the optimal move
        int idx = 0;
        if (next[idx] == 'R' && S[i] == 'S') idx = 2;
        else if (next[idx] == 'P' && S[i] == 'R') idx = 1;
        else if (next[idx] == 'S' && S[i] == 'P') idx = 0;
        
        // Update the score and the next hand vector
        total += idx;
        next.erase(next.begin() + idx);
        next.push_back(next[0]);
    }

    // Clear the next vector for the second half
    next = {'R', 'P', 'S'};
    
    // Second half loop
    for (int i = N / 2; i < N; i++) {
        // Calculate the index of the optimal move
        int idx = 0;
        if (next[idx] == 'R' && S[i] == 'S') idx = 2;
        else if (next[idx] == 'P' && S[i] == 'R') idx = 1;
        else if (next[idx] == 'S' && S[i] == 'P') idx = 0;
        
        // Update the score and the next hand vector
        total += idx;
        next.erase(next.begin() + idx);
        next.push_back(next[0]);
    }

    cout << total << endl;
    return 0;
}
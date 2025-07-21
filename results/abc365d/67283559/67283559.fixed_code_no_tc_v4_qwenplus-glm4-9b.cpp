#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // First loop calculating score for the first person
    int total = 0;
    vector<char> hand = {'R', 'P', 'S'};
    vector<char> next(hand); // Initialize next hand as hand
    
    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use = 'N';
        
        for (char n : hand) {
            if ((n == 'R' && S[i] == 'S') || (n == 'P' && S[i] == 'R') || (n == 'S' && S[i] == 'P')) {
                score++;
                use = n;
                break;
            }
        }
        
        if (score == 0) {
            use = S[i];
        }
        
        total += score;
        
        // Update the next hand by removing the character used
        next.erase(remove(next.begin(), next.end(), use), next.end());
    }
    
    // Second loop calculating score for the second person
    vector<char> next2(hand); // Initialize next hand as hand
    
    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use = 'N';
        
        for (char n : hand) {
            if ((n == 'R' && S[i] == 'S') || (n == 'P' && S[i] == 'R') || (n == 'S' && S[i] == 'P')) {
                score++;
                use = n;
                break;
            }
        }
        
        if (score == 0) {
            use = S[i];
        }
        
        // Update the next hand by removing the character used
        next2.erase(remove(next2.begin(), next2.end(), use), next2.end());
    }
    
    // Output the maximum score of both players
    cout << max(total, next2.size()) << endl;
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string s(n, ' ');
    cin >> s;
    
    // Count occurrences of each move
    vector<int> count(3, 0); // R, P, S
    for(char ch : s) {
        if(ch == 'R') count[0]++;
        else if(ch == 'P') count[1]++;
        else count[2]++;
    }
    
    // Determine the best response to minimize losses
    char best_response = ' ';
    int max_count = 0;
    for(int i = 0; i < 3; ++i) {
        if(count[i] > max_count) {
            max_count = count[i];
            best_response = "RPS"[i]; // Map index to character
        }
    }
    
    // Calculate the maximum wins
    int wins = 0;
    for(char ch : s) {
        if((ch == 'R' && best_response != 'P') ||
           (ch == 'P' && best_response != 'S') ||
           (ch == 'S' && best_response != 'R')) {
            wins++;
        }
    }
    
    printf("%d\n", wins);
    return 0;
}
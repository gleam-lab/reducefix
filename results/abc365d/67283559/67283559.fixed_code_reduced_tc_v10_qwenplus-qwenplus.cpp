#include <bits/stdc++.h>
using namespace std;

int simulate(const string& S, const vector<char>& hand, char first_move) {
    int total = 0;
    vector<char> next;
    for (auto c : hand) {
        if (c != first_move) next.push_back(c);
    }
    
    for (size_t i = 1; i < S.size(); ++i) {
        bool won = false;
        for (auto n : next) {
            if ((n == 'R' && S[i] == 'S') || 
                (n == 'P' && S[i] == 'R') || 
                (n == 'S' && S[i] == 'P')) {
                total++;
                next.clear();
                for (auto c : hand) {
                    if (c != n) next.push_back(c);
                }
                won = true;
                break;
            }
        }
        if (!won) {
            next.clear();
            for (auto c : hand) {
                if (c != S[i]) next.push_back(c);
            }
        }
    }
    return total;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> hand = {'R', 'P', 'S'};
    
    // First scenario: play optimally from the beginning
    int total1 = 0;
    vector<char> next = hand;
    for (size_t i = 0; i < S.size(); ++i) {
        bool won = false;
        for (auto n : next) {
            if ((n == 'R' && S[i] == 'S') || 
                (n == 'P' && S[i] == 'R') || 
                (n == 'S' && S[i] == 'P')) {
                total1++;
                vector<char> new_next;
                for (auto c : hand) {
                    if (c != n) new_next.push_back(c);
                }
                next = new_next;
                won = true;
                break;
            }
        }
        if (!won) {
            vector<char> new_next;
            for (auto c : hand) {
                if (c != S[i]) new_next.push_back(c);
            }
            next = new_next;
        }
    }
    
    // Second scenario: skip first move
    int total2 = 0;
    for (size_t i = 1; i < S.size(); ++i) {
        bool won = false;
        for (auto n : next) {
            if ((n == 'R' && S[i] == 'S') || 
                (n == 'P' && S[i] == 'R') || 
                (n == 'S' && S[i] == 'P')) {
                total2++;
                vector<char> new_next;
                for (auto c : hand) {
                    if (c != n) new_next.push_back(c);
                }
                next = new_next;
                won = true;
                break;
            }
        }
        if (!won) {
            vector<char> new_next;
            for (auto c : hand) {
                if (c != S[i]) new_next.push_back(c);
            }
            next = new_next;
        }
    }
    
    cout << max(total1, total2) << endl;
    return 0;
}
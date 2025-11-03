#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    // We need to simulate the sequence of button presses
    // Each character in S represents a required button press
    // We can only press one button at a time, and we cannot press the same button twice consecutively
    // We want to find the minimum number of total button presses
    
    if (N == 0) {
        cout << 0;
        return 0;
    }
    
    int ans = 0;
    char current = 'N'; // No button pressed initially
    
    for (char target : S) {
        if (current != target) {
            // We can press the target button directly
            ans++;
            current = target;
        } else {
            // We're already on the same button, so we need to press a different button first
            // Then press the target button again
            ans += 2;
            // After pressing: current -> other -> current (target)
            // So we end up back on the same button
        }
    }
    
    cout << ans;
    return 0;
}
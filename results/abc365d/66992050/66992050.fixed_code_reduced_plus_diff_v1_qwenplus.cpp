#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    // We want to minimize the number of hand changes
    // Each time we need to throw a different move than last time, we must change hands
    
    char left = 'N';   // last move made by left hand
    char right = 'N';  // last move made by right hand
    int ans = 0;
    
    for (char c : S) {
        // If current move can be done by either hand, choose optimally
        if (c == 'P') {
            if (left != 'S' && right != 'S') {
                // Neither hand has just thrown scissors -> we must change hands
                ans++;
                // Prefer to use left hand if possible, or update strategically
                if (left == 'N') {
                    left = 'P';
                } else if (right == 'N') {
                    right = 'P';
                } else {
                    // Both hands have been used; assign to left and remember it changed
                    left = 'P';
                }
            } else if (left != 'S') {
                left = 'P';
            } else if (right != 'S') {
                right = 'P';
            } else {
                // Both hands last threw 'S', so we must change hands
                ans++;
                // Assign to left hand arbitrarily
                left = 'P';
            }
        }
        else if (c == 'R') {
            if (left != 'P' && right != 'P') {
                ans++;
                if (left == 'N') {
                    left = 'R';
                } else if (right == 'N') {
                    right = 'R';
                } else {
                    left = 'R';
                }
            } else if (left != 'P') {
                left = 'R';
            } else if (right != 'P') {
                right = 'R';
            } else {
                ans++;
                left = 'R';
            }
        }
        else if (c == 'S') {
            if (left != 'R' && right != 'R') {
                ans++;
                if (left == 'N') {
                    left = 'S';
                } else if (right == 'N') {
                    right = 'S';
                } else {
                    left = 'S';
                }
            } else if (left != 'R') {
                left = 'S';
            } else if (right != 'R') {
                right = 'S';
            } else {
                ans++;
                left = 'S';
            }
        }
    }
    
    cout << ans;
    return 0;
}
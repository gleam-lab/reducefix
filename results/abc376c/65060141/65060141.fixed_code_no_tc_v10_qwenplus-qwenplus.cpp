#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<ll> A(n), B(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // We need to find the minimum x such that we can assign all toys to boxes
    // with one toy per box, and each toy fits in its assigned box.
    // One of the boxes (the new one) has size x.

    // Try to match largest toys with available boxes. If a toy doesn't fit in
    // the current biggest box, we must put it in the new box (so x >= A[i]).
    // So we greedily try to assign the biggest toys to the biggest boxes.

    int a_ptr = n - 1;  // Largest toy
    int b_ptr = n - 2;  // Largest existing box

    while (a_ptr >= 0 && b_ptr >= 0) {
        if (B[b_ptr] >= A[a_ptr]) {
            // Box fits the toy
            b_ptr--;
            a_ptr--;
        } else {
            // Toy doesn't fit in any remaining box => must use new box
            a_ptr--;
        }
    }

    if (a_ptr < 0) {
        // All toys fit in existing boxes => no need for new box (x = 0 is not valid as x must be positive)
        cout << 1 << '\n';
        return 0;
    }

    // The remaining toys (from A[0..a_ptr] need to go into the new box
    // So x must be at least A[a_ptr], the largest among them
    ll min_x = A[a_ptr];
    
    // Now verify if this x works by checking if we can assign all toys
    a_ptr = n - 1;
    b_ptr = n - 2;
    int unused_boxes = 0;

    // First pass: match from largest to smallest
    while (a_ptr >= 0 && b_ptr >= 0) {
        if (B[b_ptr] >= A[a_ptr]) {
            b_ptr--;
            a_ptr--;
        } else {
            a_ptr--;
        }
    }

    // After matching, any remaining toys must go into the new box
    // So check if all of them can fit in a box of size min_x
    for (int i = 0; i <= a_ptr; ++i) {
        if (A[i] > min_x) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << min_x << '\n';
    return 0;
}
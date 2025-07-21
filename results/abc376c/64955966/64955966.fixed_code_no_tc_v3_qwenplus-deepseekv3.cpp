#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N-1; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    
    ll x_needed = -1;
    vector<bool> box_used(N-1, false);
    int toy_ptr = 0;
    int box_ptr = 0;
    
    while (toy_ptr < N && box_ptr < N-1) {
        if (A[toy_ptr] <= B[box_ptr]) {
            box_used[box_ptr] = true;
            toy_ptr++;
            box_ptr++;
        } else {
            if (x_needed == -1) {
                x_needed = A[toy_ptr];
                toy_ptr++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    while (toy_ptr < N) {
        if (x_needed == -1) {
            x_needed = A[toy_ptr];
            toy_ptr++;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    if (x_needed == -1) {
        // All toys fit in existing boxes, but we need to purchase a box.
        // The new box can be of size 1, but we need to ensure no toy is left.
        // However, since all toys are placed, the new box can be of any size, but the problem says place each toy in boxes.
        // So, the minimal x is not needed since all N-1 boxes are used, and N toys are placed. But N-1 boxes can only hold N-1 toys.
        // Wait, the original problem says N toys and N boxes (N-1 existing + 1 new).
        // The code above may have a logic flaw here.
        // Let me re-examine.
        // If all N toys are placed in N-1 boxes, then it's impossible because boxes must contain only one toy each.
        // So, x_needed should not be -1 here. That means, the initial approach above is incorrect.
        
        // Correct approach:
        // We need to place N toys into N boxes (existing N-1 boxes + 1 new box).
        // So, at least one toy must go into the new box.
        // The minimal x is the size of the smallest toy that cannot be placed in the existing boxes.
        // So, even if all toys could fit into existing boxes, we still need to place one toy in the new box.
        // Thus, x must be at least the size of one toy.
        // The minimal x is the smallest possible size that can accommodate one of the toys not placed in existing boxes.
        // But how to determine which toy to place in the new box?
        // We need to select the smallest possible x such that the remaining N-1 toys can be placed in the N-1 existing boxes.
        // This requires finding the largest N-1 toys that can be placed in the N-1 boxes, and the remaining toy will go into the new box.
        
        // So, the correct approach is to first try to match the largest N-1 toys to the N-1 boxes, and the smallest toy will go into the new box.
        // Or, alternatively, we can try to match the largest N-1 boxes to the largest N-1 toys, and the smallest remaining toy will go into the new box.
        // So, we need to sort both arrays in descending order, then for each box, check if it can hold the corresponding toy.
        // If all boxes can hold their corresponding toys, then the new box can hold the smallest toy.
        // Otherwise, the new box must hold the largest toy that cannot fit into any box.
        
        // Let me reimplement the solution with this in mind.
        
        // Re-sorting the arrays in descending order.
        sort(A.begin(), A.end(), greater<ll>());
        sort(B.begin(), B.end(), greater<ll>());
        
        // We need to place N-1 toys into N-1 boxes, and the remaining toy into the new box.
        // The minimal x is the size of the remaining toy.
        // The remaining toy is the one that cannot be matched with any box.
        // So, we can try to match the largest N-1 toys to the boxes first.
        
        priority_queue<ll> toys_heap;
        for (ll a : A) {
            toys_heap.push(a);
        }
        
        priority_queue<ll> boxes_heap;
        for (ll b : B) {
            boxes_heap.push(b);
        }
        
        ll new_box_size = -1;
        while (!boxes_heap.empty()) {
            ll box = boxes_heap.top();
            boxes_heap.pop();
            ll toy = toys_heap.top();
            if (toy <= box) {
                toys_heap.pop();
            } else {
                if (new_box_size == -1) {
                    new_box_size = toy;
                    toy = toys_heap.top();
                    toys_heap.pop();
                } else {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        
        if (new_box_size == -1) {
            // All boxes matched, but one toy remains.
            new_box_size = toys_heap.top();
        }
        
        cout << new_box_size << endl;
        return;
    }
    
    cout << x_needed << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    bool possible = true;
    int x = -1;
    
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > b[i]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        x = a.back();
    } else {
        // Check if we can replace one box with a new x
        // The new x must accommodate the largest toy that couldn't fit
        // and the remaining toys must fit the remaining boxes
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int largest_a_not_fit = -1;
        for (int i = 0; i < n - 1; i++) {
            if (a[n - 1 - i] > b[i]) {
                largest_a_not_fit = a[n - 1 - i];
                break;
            }
        }
        if (largest_a_not_fit == -1) {
            // All a[i] <= b[i] when sorted in ascending? No, it's not possible if previous step failed
            // So this means we need to find the minimal x such that x >= the largest a not fitting in any b
            // Which is the largest a when sorted in descending that is > b[i]
            sort(a.begin(), a.end(), greater<int>());
            sort(b.begin(), b.end(), greater<int>());
            int candidate = -1;
            for (int i = 0; i < n - 1; i++) {
                if (a[i] > b[i]) {
                    candidate = a[i];
                    break;
                }
            }
            if (candidate != -1) {
                // Check if the remaining a's can fit into remaining b's
                vector<int> new_a;
                for (int num : a) {
                    if (num != candidate) {
                        new_a.push_back(num);
                    }
                }
                sort(new_a.begin(), new_a.end(), greater<int>());
                sort(b.begin(), b.end(), greater<int>());
                possible = true;
                for (int i = 0; i < n - 1; i++) {
                    if (new_a[i] > b[i]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    x = candidate;
                } else {
                    x = -1;
                }
            } else {
                x = -1;
            }
        } else {
            x = largest_a_not_fit;
            // Now check if the other toys can fit into the boxes
            vector<int> new_a;
            for (int num : a) {
                if (num != x) {
                    new_a.push_back(num);
                }
            }
            sort(new_a.begin(), new_a.end(), greater<int>());
            sort(b.begin(), b.end(), greater<int>());
            possible = true;
            for (int i = 0; i < n - 1; i++) {
                if (new_a[i] > b[i]) {
                    possible = false;
                    break;
                }
            }
            if (!possible) {
                x = -1;
            }
        }
    }
    
    cout << x << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Use multiset to maintain the order and allow easy removal of K elements
    multiset<int> s(a.begin(), a.end());
    
    // Remove the K largest elements to minimize the range of the remaining elements
    for (int i = 0; i < k; i++) {
        s.erase(s.end());
    }

    // The difference between the smallest and largest of the remaining elements is the answer
    cout << *s.begin() - *(s.end()) << endl;

    return 0;
}
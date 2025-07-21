#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, int> m;
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;
        if (n == 1) { // Add ball with integer x to the bag
            int x;
            cin >> x;
            m[x]++;
        } else if (n == 2) { // Remove ball with integer x from the bag
            int x;
            cin >> x;
            m[x]--;
            // If there are no more balls of integer x, remove x from the map
            if (m[x] == 0) {
                m.erase(x);
            }
        } else { // Output the number of distinct integers in the bag
            cout << m.size() << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    priority_queue<int> pq;
    for(int i = 0; i < n; ++i) {
        pq.push(h[i]);
    }

    long long ans = 0;
    int turn = 0;
    
    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();

        if(curr > 0) {
            if(turn % 3 == 2) {
                --curr;
            } else {
                curr -= 2;
            }
            ans += 1 + (turn % 3 != 0);

            if(curr > 0) {
                pq.push(curr);
            }
        }

        ++turn;
    }

    cout << ans << endl;

    return 0;
}
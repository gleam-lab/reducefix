#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N - 1);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int low = 1;
    int high = 1e9;
    int answer = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        vector<int> boxes = B;
        boxes.push_back(mid);
        sort(bboxes.begin(), boxes.end());
        
        bool possible = true;
        int box_ptr = 0;
        for (int i = 0; i < N; ++i) {
            if (box_ptr >= boxes.size()) {
                possible = false;
                break;
            }
            if (boxes[box_ptr] >= A[i]) {
                box_ptr++;
            } else {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    // Now, check if the answer is really feasible
    if (answer != -1) {
        vector<int> boxes = B;
        boxes.push_back(answer);
        sort(bboxes.begin(), boxes.end());
        int toy_ptr = 0;
        int box_ptr = 0;
        bool feasible = true;
        while (toy_ptr < N && box_ptr < boxes.size()) {
            if (boxes[box_ptr] >= A[toy_ptr]) {
                toy_ptr++;
                box_ptr++;
            } else {
                box_ptr++;
            }
        }
        if (toy_ptr != N) {
            answer = -1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
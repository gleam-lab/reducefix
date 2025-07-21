#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Candidate {
    ll a;
    int idx;
};

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<Candidate> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
    }
    
    // Sort the candidates based on their current votes
    sort(A.begin(), A.end(), [](const Candidate& a, const Candidate& b) {
        return a.a < b.a;
    });
    
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i].a;
    }
    
    ll remaining_votes = K - prefix_sum[N];
    vector<ll> res(N, -1);
    
    for (int i = 0; i < N; ++i) {
        // Binary search to find the minimal X for candidate i
        ll left = 0;
        ll right = remaining_votes;
        ll answer = -1;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Calculate the new vote count for candidate i
            ll new_votes = A[i].a + mid;
            
            // Find the first candidate with votes > new_votes
            auto it = upper_bound(A.begin(), A.end(), Candidate{new_votes, 0}, 
                [](const Candidate& x, const Candidate& y) {
                    return x.a < y.a;
                });
            int cnt_greater = A.end() - it;
            
            if (cnt_greater < M) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        res[A[i].idx] = answer;
    }
    
    // Output the results in the original order
    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}
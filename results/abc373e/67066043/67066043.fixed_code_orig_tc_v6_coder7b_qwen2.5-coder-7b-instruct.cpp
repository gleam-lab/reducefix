#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> mergeSortAndCount(vector<ll>& arr) {
    if (arr.size() <= 1) return arr;
    
    int mid = arr.size() / 2;
    vector<ll> left(arr.begin(), arr.begin() + mid);
    vector<ll> right(arr.begin() + mid, arr.end());
    
    left = mergeSortAndCount(left);
    right = mergeSortAndCount(right);
    
    vector<ll> merged;
    ll inversions = 0, i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            merged.push_back(left[i]);
            ++i;
        } else {
            merged.push_back(right[j]);
            inversions += (mid - i);
            ++j;
        }
    }
    
    while (i < left.size()) {
        merged.push_back(left[i]);
        ++i;
    }
    
    while (j < right.size()) {
        merged.push_back(right[j]);
        ++j;
    }
    
    return merged;
}

vector<ll> getPrefixSum(const vector<ll>& arr) {
    vector<ll> prefixSum(arr.size() + 1);
    for (int i = 1; i <= arr.size(); ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }
    return prefixSum;
}

vector<ll> countInversions(const vector<ll>& arr) {
    vector<ll> sortedArr = arr;
    mergeSortAndCount(sortedArr);
    vector<ll> freq(arr.size() + 1, 0);
    vector<ll> result(arr.size());
    
    for (int i = arr.size() - 1; i >= 0; --i) {
        result[i] = freq[arr[i]];
        ++freq[arr[i]];
    }
    
    return result;
}

vector<ll> minVotesToWin(const vector<ll>& votes, const vector<ll>& prefixSum, int M, ll totalVotes) {
    int N = votes.size();
    vector<ll> minVotes(N);
    
    for (int i = 0; i < N; ++i) {
        if (votes[i] >= totalVotes) {
            minVotes[i] = 0;
        } else {
            int requiredVotes = votes[i] + 1;
            int canBeat = min(M, N - 1);
            int sumOfTopCandidates = prefixSum[min(canBeat, N)] - prefixSum[i];
            
            if (sumOfTopCandidates < requiredVotes * (canBeat - 1)) {
                minVotes[i] = -1;
            } else {
                minVotes[i] = requiredVotes - (prefixSum[i + 1] - votes[i]);
            }
        }
    }
    
    return minVotes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    ll K;
    cin >> N >> M >> K;
    
    vector<ll> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
        K -= votes[i];
    }
    
    sort(votes.rbegin(), votes.rend());
    vector<ll> inversions = countInversions(votes);
    vector<ll> prefixSum = getPrefixSum(inversions);
    
    vector<ll> result = minVotesToWin(votes, prefixSum, M, K);
    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
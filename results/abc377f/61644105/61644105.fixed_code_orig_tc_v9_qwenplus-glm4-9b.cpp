#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int main() {
  cin >> N >> M;

  vector<pair<int, int>> pieces;
  pieces.reserve(M);

  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    pieces.emplace_back(a, b);
  }

  // Sort pieces based on rows and columns
  sort(pieces.begin(), pieces.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first || (a.first == b.first && a.second < b.second);
  });

  int uniqueRows = 0, uniqueCols = 0;

  set<int> attackedRows, attackedCols;

  for (int i = 0; i < M; ++i) {
    if (attackedRows.find(pieces[i].first) == attackedRows.end()) {
      attackedRows.insert(pieces[i].first);
      uniqueRows++;
    }
    if (attackedCols.find(pieces[i].second) == attackedCols.end()) {
      attackedCols.insert(pieces[i].second);
      uniqueCols++;
    }
  }

  long long totalSquares = N * N;
  long long attackedSquares = (uniqueRows + uniqueCols) * N;

  set<pair<int, int>> attackedDiagonalsSum;
  set<pair<int, int>> attackedDiagonalsDiff;

  for (int i = 0; i < M; ++i) {
    int sum = pieces[i].first + pieces[i].second;
    int diff = pieces[i].first - pieces[i].second;

    if (attackedDiagonalsSum.find({sum, 0}) == attackedDiagonalsSum.end()) {
      attackedDiagonalsSum.insert({sum, 0});
    }
    if (attackedDiagonalsDiff.find({diff, 0}) == attackedDiagonalsDiff.end()) {
      attackedDiagonalsDiff.insert({diff, 0});
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (attackedDiagonalsSum.find({i, 0}) != attackedDiagonalsSum.end()) {
      attackedSquares++;
    }
    if (attackedDiagonalsDiff.find({i, 0}) != attackedDiagonalsDiff.end()) {
      attackedSquares++;
    }
  }

  cout << (totalSquares - attackedSquares) << endl;

  return 0;
}
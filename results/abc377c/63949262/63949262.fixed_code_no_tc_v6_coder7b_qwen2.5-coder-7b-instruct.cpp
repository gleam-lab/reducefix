#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读取输入
    long long N;
    long long piece_num;
    cin >> N >> piece_num;

    // 使用集合来存储所有不可放置棋子的位置
    set<long long> invalid_positions;

    // 遍历每个棋子，标记其周围的8个位置为无效
    for (long long k = 0; k < piece_num; ++k) {
        long long x, y;
        cin >> x >> y;

        // 计算可能的8个方向
        long long dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        long long dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        for (int d = 0; d < 8; ++d) {
            long long nx = x + dx[d];
            long long ny = y + dy[d];

            // 检查新位置是否在有效范围内
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                // 将新位置加入到无效集合中
                invalid_positions.insert(nx * N + ny);
            }
        }
    }

    // 计算有效位置的数量
    long long total_positions = N * N;
    long long valid_positions = total_positions - invalid_positions.size();

    // 输出结果
    cout << valid_positions << endl;

    return 0;
}
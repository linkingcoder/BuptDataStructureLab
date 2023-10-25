#include <iostream>
using namespace std;

const int N = 8;
int boards[N][N] = {0}; // 8x8的棋盘，初始化为0
int res = 0; // 记录解的数量

// 检查在(row, column)放置皇后是否符合要求
bool check(int row, int column) {
    // 检查同一列是否有皇后
    for (int i = 0; i < row; ++i) {
        if (boards[i][column] != 0) {
            return false;
        }
    }
    // 检查左上对角线是否有皇后
    for (int m = row - 1, n = column - 1; m >= 0 && n >= 0; m--, n--) {
        if (boards[m][n] == 1) {
            return false;
        }
    }
    // 检查右上对角线是否有皇后
    for (int m = row - 1, n = column + 1; m >= 0 && n < N; m--, n++) {
        if (boards[m][n] == 1) {
            return false;
        }
    }
    return true;
}

// 递归放置皇后，k表示当前处理的行
void setQueen(int k) {
    if (k == N) {
        // 如果成功放置了8个皇后，增加解的数量并输出当前解
        res++;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                cout << boards[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        // 遍历在当前行的每个位置并放置皇后
        for (int i = 0; i < N; i++) {
            if (check(k, i)) {
                boards[k][i] = 1; // 放置皇后
                setQueen(k + 1); // 递归放置下一行的皇后
                boards[k][i] = 0; // 回溯，重置当前位置
            }
        }
    }
}

int main() {
    setQueen(0); // 从第0行开始放置皇后
    cout<< res << endl; // 输出总解的数量
    return 0;
}

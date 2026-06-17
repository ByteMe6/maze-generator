#include <iostream>
#include <cstdlib>
#include <ctime>

const int sideSize = 30;
const int cells = sideSize / 2;

int matrix[sideSize][sideSize];
bool visited[cells][cells];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void labirint(int x, int y) {
    visited[x][y] = true;
    matrix[x * 2][y * 2] = 0;

    int order[4] = {0, 1, 2, 3};
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = order[i]; order[i] = order[j]; order[j] = tmp;
    }

    for (int i = 0; i < 4; i++) {
        int d = order[i];
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= cells || ny < 0 || ny >= cells) continue;
        if (visited[nx][ny]) continue;
        matrix[x * 2 + dx[d]][y * 2 + dy[d]] = 0;
        labirint(nx, ny);
    }
}

void printLab() {
    for (int i = 0; i < sideSize; i++) {
        for (int j = 0; j < sideSize; j++) {
            switch (matrix[i][j]) {
                case 1: std::cout << "██"; break;
                case 0: std::cout << "  "; break;
                case 5: std::cout << " X"; break;
            }
        }
        std::cout << "\n";
    }
}

int main() {
    srand(time(0));
    for (int i = 0; i < sideSize; i++)
        for (int j = 0; j < sideSize; j++)
            matrix[i][j] = 1;

    labirint(cells / 2, 0);
    matrix[(cells / 2) * 2][sideSize - 1] = 5;

    printLab();
    return 0;
}

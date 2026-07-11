#include "bits/stdc++.h"

using namespace std;

struct Task
{
    int x;
    int y;
    Direction direction; // 0:Up 1:Right 2:Down 3:Left
};

enum class Direction
{
    Up,
    Right,
    Down,
    Left
};

int main() {
    int H, W;
    cin >> H >> W;

    pair<int, int> start, goal;
    cin >> start.first >> start.second;
    cin >> goal.first >> goal.second;

    vector<vector<char>> S(W, vector<char>(H));
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            cin >> S[i][j];
        }
    }

    vector<vector<int>> costs(W, vector<int>(H, -1));
    costs[start.first - 1][start.second - 1] = 0;

    queue<Task> tasks;
    if (start.first != W) tasks.push(Task{start.first + 1, start.second, Direction::Right});
    if (start.first != 1) tasks.push(Task{start.first - 1, start.second, Direction::Left});
    if (start.second != H) tasks.push(Task{start.first, start.second + 1, Direction::Up});
    if (start.second != 1) tasks.push(Task{start.first, start.second - 1, Direction::Down});

    while(!tasks.empty()) {
        Task task = tasks.front();
        tasks.pop();

        
        if (task.x != W) {
            if (costs[task.x - 1][task.y - 1] != -1)
            tasks.push(Task{start.first + 1, start.second, Direction::Right});
        }
        if (start.first != 1) tasks.push(Task{start.first - 1, start.second, Direction::Left});
        if (start.second != H) tasks.push(Task{start.first, start.second + 1, Direction::Up});
        if (start.second != 1) tasks.push(Task{start.first, start.second - 1, Direction::Down});
    }
}

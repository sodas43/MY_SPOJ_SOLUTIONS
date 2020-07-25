#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

typedef pair<int, pii > piii; //<dist, {x, y}>

vector<vector<char>> grid;
vector<vector<int>> dist;

vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}

bool isValid(int r, int c, int R, int C) {
    return (r >= 0 && r < R && c >= 0 && c < C);
}

int dijkstra(pii startPos, int R, int C) {
    priority_queue<piii, vector<piii>, greater<piii>> minHeap;

    minHeap.push({0, startPos});
    dist[startPos.first][startPos.second] = 0;

    while (!minHeap.empty()) {
        auto cur = minHeap.top();
        minHeap.pop();

        auto curCost = cur.first;
        auto curX    = cur.second.first;
        auto curY    = cur.second.second;

        for (int i = 0; i < 4; ++i) {
            auto newX = curX + dirs[i][0];
            auto newY = curY + dirs[i][1];

            if (isValid(newX, newY, R, C) && grid[newX][newY] != 'X') {
                if (grid[newX][newY] == 'D') { // reached target
                    return curCost;
                }

                auto cost = grid[newX][newY] - '0';

                if (dist[curX][curY] + cost < dist[newX][newY]) {
                    dist[newX][newY] = dist[curX][curY] + cost;

                    minHeap.push({dist[newX][newY], {newX, newY}});
                }
            }
        }
    }
    return -1;
}

int main() {
    init();

    while (1) {
        int R, C;
        cin >> C >> R;

        if (R == 0 && C == 0)   break;

        grid.clear();
        grid.resize(R + 1, vector<char>(C + 1, 0));

        dist.clear();
        dist.resize(R + 1, vector<int>(C + 1, INT_MAX));

        pii startPos;

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                char ch;
                cin >> ch;

                grid[i][j] = ch;

                if (ch == 'S') { startPos = {i, j}; }
            }
        }

        cout << dijkstra(startPos, R, C) << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int cx, cy, fx, fy;
int cd, fd;
string map_[10];
int t;
int state[10][10][4][10][10][4];

void move(int& x, int& y, int& d) {
    switch (d) {
        case (0) : {
            if (x - 1 >= 0 && map_[x-1][y] != '*') {
                x -= 1;
            }
            else {
                d = (d + 1) % 4;
            }
            break;
        }
        case (1) : {
            if (y + 1 < 10 && map_[x][y+1] != '*') {
                y += 1;
            }
            else {
                d = (d + 1) % 4;
            }
            break;
        }
        case (2) : {
            if (x + 1 < 10 && map_[x+1][y] != '*') {
                x += 1;
            }
            else {
                d = (d + 1) % 4;
            }
            break;
        }
        case (3) : {
            if (y - 1 >= 0 && map_[x][y-1] != '*') {
                y -= 1;
            }
            else {
                d = (d + 1) % 4;
            }
            break;
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> map_[i][j];
            if (map_[i][j] == 'C') {
                cx = i;
                cy = j;
            }
            if (map_[i][j] == 'F') {
                fx = i;
                fy = j;
            }
        }
    }
    while (1) {
        state[cx][cy][cd][fx][fy][fd] = 1;
        move(cx, cy, cd);
        move(fx, fy, fd);
        t += 1;
        if (state[cx][cy][cd][fx][fy][fd] == 1) {
            cout << '0';
            return 0;
        }
        if (cx == fx && cy == fy) {
            cout << t;
            return 0;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int board[8][8];
void kt(int x, int y)
{
    //Base Conditions

    if(x>=8 || y>=8 || x<0 || y<0 || board[x][y]!=-1)
        return;
    board[x][y] = cnt;
    cnt++;
    kt(x + 1, y + 2);
    kt(x - 1, y + 2);
    kt(x + 2, y - 1);
    kt(x - 2, y - 1);
    kt(x + 1, y - 2);
    kt(x - 1, y - 2);
    kt(x + 2, y + 1);
    kt(x - 2, y + 1);
    return;
}
int main()
{
    memset(board, -1, sizeof(board));
    kt(4, 5);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0;j<8;j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
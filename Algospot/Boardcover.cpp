#include <iostream>
#include <vector>

using namespace std;

const int moveList[4][3][2] = {
    { {0, 0}, {1, 0}, {0, 1} }, 
    { {0, 0}, {0, 1}, {1, 1} }, 
    { {0, 0}, {1, 0}, {1, -1} }, 
    { {0, 0}, {1, 0}, {1, 1} } };

bool set(vector<vector<int> >& board, int type, int y, int x, int delta)
{
    bool ret = true;

    for(int i = 0; i < 3; ++i){
        int newRow = y + moveList[type][i][0];
        int newCol = x + moveList[type][i][1];

        if(newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size()){
            ret = false;
        }
        else if((board[newRow][newCol] += delta) > 1)
            ret = false;
    }

    return ret;
}

int setBoard(vector<vector<int> >& board)
{
    int x = -1, y = -1;

    for(int rowNum = 0; rowNum < board.size(); ++rowNum){
        for(int colNum = 0; colNum < board[rowNum].size(); ++colNum){
            // 1 - visited
            if(board[rowNum][colNum] == 0){
                y = rowNum;
                x = colNum;
                break;
            } 
        }
        if(y != -1) break;  
    }

    if(y == -1) return 1;
    int ret = 0;
    for(int type = 0; type < 4; ++type)
    {
        // fill
        if(set(board, type, y, x, 1))
        {
            ret += setBoard(board);
        }

        // clear
        set(board, type, y, x, -1);
    }

    return ret;
}


int main(void)
{
    int caseNum;
    int row, col;

    cin >> caseNum;
    for(int caseIndex = 0; caseIndex < caseNum; ++caseIndex){
        cin >> row >> col;

        // Set Input
        vector<vector<int> > board;
        int emptyNum = 0;
        for(int rowNum = 0; rowNum < row; ++rowNum){
            vector<int> boardRow;
            for(int colNum = 0; colNum < col; ++colNum){
                char temp;
                cin >> temp;
                if(temp == '#') boardRow.push_back(1);
                else{
                    boardRow.push_back(0);
                    emptyNum++;
                }
            }
            board.push_back(boardRow);
        }


        if(emptyNum % 3 != 0) {
            cout << 0 << endl;
            continue;
        }

        cout << setBoard(board) << endl;
    }

    return 0;
}
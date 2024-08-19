class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            /*check if any column contain repeated numbers*/
            if(isValidCol(board, i) == false)
            {
                return false;
            }
            
            /*check if any row contain repeated numbers*/
            if(isValidRow(board, i) == false)
            {
                return false;
            }

            /*
            check if any sub box contain repeated numbers
            we have 9 sub boxes, to access each sub box using the same loop we need to convert the loop iterator value to the row and column start position of the sub box
            */
            if(isValidSubBox(board, (i/3)*3, (i%3)*3) == false)
            {
                return false;
            }
            
            
        }
        return true;
    }
private:
    bool isValidCol(vector<vector<char>>& board, int rowIdx)
    {
        unordered_set<int> colSet;

        for(int i=0;i<board[rowIdx].size();i++)
        {
            /*check if the character is a number*/
            if(board[rowIdx][i] != '.')
            {
                if(colSet.find(board[rowIdx][i]) != colSet.end())
                    return false;
                else
                    colSet.insert(board[rowIdx][i]);
            }
        }
        return true;
    }
    bool isValidRow(vector<vector<char>>& board, int colIdx)
    {
        unordered_set<int> rowSet;

        for(int i=0;i<board.size();i++)
        {
            /*check if the character is a number*/
            if(board[i][colIdx] != '.')
            {
                if(rowSet.find(board[i][colIdx]) != rowSet.end())
                    return false;
                else
                    rowSet.insert(board[i][colIdx]);
            }
        }
        return true;
    }
    
    /*rowIdx and colIdx are the start position of the sub box*/
    bool isValidSubBox(vector<vector<char>>& board, int rowIdx, int colIdx)
    {
        unordered_set<int> boxSet;
        
        /*traverse sub box elements*/
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                /*check if the character is a number*/
                if(board[rowIdx+i][colIdx+j] != '.' )
                {
                    if(boxSet.find(board[rowIdx+i][colIdx+j] ) != boxSet.end())
                    {
                        return false;
                    }
                    else
                        boxSet.insert(board[rowIdx+i][colIdx+j]);
                }
            }
        }
        return true;
    }
};
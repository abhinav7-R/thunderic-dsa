#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool dfs( vector<vector<char>>& board, string &word, int i, int j, int k){
    if (k == word.size()){
        return true; 
    }
    
    int m = board.size();
    int n = board[0].size();
    
    if (i<0 || j<0 || i>=m || j>=n || board[i][j] != word[k])
         return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = 
          dfs(board, word, i+1, j, k+1) ||
          dfs(board, word, i-1, j, k+1) ||
          dfs(board, word, i, j+1, k+1) ||
          dfs(board, word, i, j-1, k+1) ;

    board[i][j] = temp;
     
    return found;
          
}

bool exist(vector<vector<char>>& board, string& word){
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            if(dfs(board, word, i, j, 0))
                return true;
        }
    }

    return false;
}

int main(){
    int rows, colm;

    cout<<"enter the row size:";
    cin>>rows;

    cout<<"enter the column size=";
    cin>>colm;

    vector<vector<char>> boards(rows, vector<char>(colm));

    cout<<"enter the boards letter  = \n ";
    for (int i = 0; i<rows; i++){
        for (int j=0; j<colm; j++){
            cin>>boards[i][j];
        }
    }

    string words;

    cout<<"enter the word :";
    cin>>words;

    bool result = exist(boards, words);
    cout<<result;

    return 0;

}
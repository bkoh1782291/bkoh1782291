// # Brian Koh
// # a1782291
// # Artificial Intelligence Assignment 1
// # g++ ttt.cpp [state] [output] -o tictactoe.bin -std=c++11
// # usage : make

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

char player = 'x'; 
char opponent = 'o';


vector<string> states;

int evaluateBoard(string s){

    // for checking wins on rows
    // 012 345 678
    for(int rows = 0; rows < 9; rows++)
    {
        if ( s[0] == player && s[1] == player && s[2] == player ||
             s[3] == player && s[4] == player && s[5] == player ||
             s[6] == player && s[7] == player && s[8] == player )
        {
            //cout << "called1";
            return 1;
        }
        else if ( s[0] == opponent && s[1] == opponent && s[2] == opponent ||
                  s[3] == opponent && s[4] == opponent && s[5] == opponent ||
                  s[6] == opponent && s[7] == opponent && s[8] == opponent )
        {
            //cout << "called2";
            return -1;
        }
    }

    // for checking wins on cols
    // 036 147 258
    for(int cols = 0; cols < 9; cols++)
    {
        if ( s[0] == player && s[3] == player && s[6] == player ||
             s[1] == player && s[4] == player && s[7] == player ||
             s[2] == player && s[5] == player && s[8] == player )
        {
            return 1;
        }
        else if ( s[0] == opponent && s[3] == opponent && s[6] == opponent ||
                  s[1] == opponent && s[4] == opponent && s[7] == opponent ||
                  s[2] == opponent && s[5] == opponent && s[8] == opponent )
        {
            return -1;
        }
    }

    // checking wins on diagonals
    // 048 246
    for(int diag = 0; diag < 9; diag++)
    {
        if ( s[0] == player && s[4] == player && s[8] == player ||
             s[2] == player && s[4] == player && s[6] == player )
        {
            return 1;
        }
        else if ( s[0] == opponent && s[4] == opponent && s[8] == opponent ||
                  s[2] == opponent && s[4] == opponent && s[6] == opponent )
        {
            return -1;
        }
    }
    
    // if none of the checks done, return 0 instead
    return 0;
}

bool MovesLeft(string s)
{
    for (int i = 0; i < 9; i++)
            if (s[i] == '-')
                return true;
    return false;
}

int minimax(string s, int depth, bool turn)
{
    int score = evaluateBoard(s);

    if (score == 1)
        return score;

    if (score == -1)
        return score;
    
    if (MovesLeft(s) == false)
        return 0;

    // maximizer's turn 'x'
    if (turn == true)
    {
        int best = -1000;
        
        for(int i = 0; i < 9; i++)
        {
            if (s[i] == '-'){

                s[i] = player;
                best = max(best, minimax(s, depth + 1, !turn));
                //undo move
                s[i] = '-';
            }
        }
        return best;
    }
    // minimizer's turn 'o'
    else if (turn == false)
    {
        int best = 1000;
        
        for(int i = 0; i < 9; i++)
        {
            if (s[i] == '-'){
                
                s[i] = opponent;
                best = min(best, minimax(s, depth + 1, !turn));
                //undo move
                s[i] = '-';
            }
        }
        return best;
    }
}

int GameStates(string s, int depth, bool turn)
{
    int score = evaluateBoard(s);

    if (score == 1)
        return 1;

    if (score == -1)
        return -1;
    
    if (MovesLeft(s) == false)
        return 0;

    // maximizer's turn 'x'
    if (turn == true)
    {
        int best = -1000;
        
        for(int i = 0; i < 9; i++)
        {
            if (s[i] == '-'){

                s[i] = player;
                
                best = max(best, GameStates(s, depth + 1, !turn));
                string tmpstr =  s + " " + to_string(evaluateBoard(s));
                states.push_back(tmpstr);
                //undo move
                s[i] = '-';
            }
        }
        return best;
    }
    // minimizer's turn 'o'
    else if (turn == false)
    {
        int best = 1000;
        
        for(int i = 0; i < 9; i++)
        {
            if (s[i] == '-'){
                
                s[i] = opponent;
                
                best = min(best, GameStates(s, depth + 1, !turn));
                string tmpstr =  s + " " + to_string(evaluateBoard(s));
                states.push_back(tmpstr);
                
                //undo move
                s[i] = '-';
            }
        }
        return best;
    }
}

int returnBestMove(string s){

    int bestVal = -1000;
    int bestMove = -1;
    
    for(int i = 0; i < 9; i++)
    {
        if (s[i] == '-'){

            s[i] = player;
            int moveVal = minimax(s, 0, false);
            //undo move
            s[i] = '-';
            
            if (moveVal > bestVal)
            {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }

    cout << "value of best move: " << bestVal << endl;
    
    return bestMove;
}

bool isMaxTurn(string board)
{
    int min_count = 0;
    int max_count = 0;

    for (int i = 0; i < 9; i++){
        if (board[i] == 'x'){
            max_count++;
        }
        if (board[i] == 'o'){
            min_count++;
        }
    }
    // cout << "max_count: " << max_count << endl;
    // cout << "min_count: " << min_count << endl;
    // if o > x then it's max's turn
    if (min_count > max_count){
        return true;
    }
    // if x > o then its min's turn
    else if (max_count > min_count){
        return false;
    }
    // else equal, it will definitely be max's turn
    else {
        return true;
    }
}

string returnUpdatedBoard(string board){

    int bestMove = returnBestMove(board);
    cout << "bestMove: " << bestMove << endl;

    // if game is still playable
    if (evaluateBoard(board) == 0)
    {
        if (isMaxTurn(board) == true){
            board[bestMove] = 'x';
        }
        if (isMaxTurn(board) == false){
            board[bestMove] = 'o';
        }
    }
    return board;
}

int main(int argc, char* argv[]){

    string board = argv[1];
    ofstream myfile (argv[2]);
    
    // error handling
    if ((board.length() < 9)){
        cout << "please input board with 9 values!" << endl;
        cerr << "USAGE: " << argv[0] << " [state] [output]" << endl;
        return 0;
    }

    int result = evaluateBoard(board);

    // cout << MovesLeft(board) << endl;
    // cout << "gamestate: " << result << endl;
    
    string updatedBoard = returnUpdatedBoard(board);
    cout << "updated: " << updatedBoard << endl;

    // print out gamestates
    bool turn = isMaxTurn(board);

    

    if (turn == true)
    {
        GameStates(board, 0, true);
    }
    else if (turn == false)
    {
        GameStates(board, 0, false);
    }
    
    // check if there is insufficient arguements
    if (argc < 2) {
        // Tell the user how to run the program
        cerr << "USAGE: " << argv[0] << " [state] [output]" << endl;
        return 1;
    }
    // write and output to file argv[2]
    if (myfile.is_open())
    {
        for (int i = 0; i < states.size(); i++){
            // print to file
            myfile << states[i] << endl;
        }
        // myfile << "updated board: " << returnUpdatedBoard(board) << '\n';
        myfile.close();
    }
    else { 
        cout << "Unable to open file";
    }

    return 0;
}
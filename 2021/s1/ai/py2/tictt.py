# Brian Koh
# a1782291
# Artificial Intelligence Assignment 1
# usage : $ python tictactoe.py [state] [path]

import sys
import copy
import math

# defines which player's turn at the current game board
def curr_player(board):

    X_count = 0
    O_count = 0

    for i in range(3):
        for j in range(3):
            if board[i][j] == 'x':
                X_count += 1
            elif board[i][j] == 'o':
                O_count += 1
    
    if X_count <= O_count:
        return 'x'
    else:
        return 'o'


# to declare if there are any patterns on the current board
def EvaluateBoard(b):

    for a in range(3):
        # rows
        if ((b[a][0] == b[a][1] == b[a][2]) and (b[a][0] != '-')):
            return b[a][0]
        # cols
        if ((b[0][a] == b[1][a] == b[2][a]) and (b[0][a] != '-')):
            return b[0][a]
    # diagonals
    if (((b[0][0] == b[1][1] == b[2][2]) or (b[0][2] == b[1][1] == b[2][0])) and (b[1][1] != '-')):
        return b[1][1]
    else:
        return None


# to declare the winner of the current board
def utility(board):

    if EvaluateBoard(board) == 'x':
        return 1
    elif EvaluateBoard(board) == 'o':
        return -1
    else:
        return 0


# to declare if the game has ended or not
def status(board):

    index = 0

    if (EvaluateBoard(board) == 'x') or (EvaluateBoard(board) == 'o'):
        return True

    for i in range(3):
        for j in range(3):
            if (board[i][j] == '-'):
                index += 1
    
    if (index == 0):
        return True
    else:
        return False


# copy board with advanced move with deepcopy, suited for recursive calls
def result(board, action):

    x, y = action[0], action[1]
    board_copy = copy.deepcopy(board)

    if (board_copy[x][y] != '-'):
        raise Exception("node visited")
    else:
        board_copy[x][y] = curr_player(board)

    return board_copy



def minvalue(board, value):

    if status(board):
        return utility(board), value

    best = 1000
    bestMove = -1

    # declare all possible actions for the current game
    possible_actions = []

    for i in range(3):
        for j in range(3):
            if (board[i][j] == '-'):
                possible_actions.append((i,j))

    possible = copy.deepcopy(possible_actions)

    # loop through possible moves and recursive call minimax
    for i in possible:
        bestVal = maxvalue(result(board, i), i)

        # min (v, max-val)
        if best > bestVal[0]:
            best = bestVal[0]
            bestMove = i

        gameState = array_to_string(result(board, i))
        util = str(bestVal[0])
        # store state and util and output to file
        # print(gameState + ' ' + util)
        file = open(sys.argv[2], "a")
        file.write(gameState + ' ' + util + '\n')
        file.close()

    return best, bestMove



def maxvalue(board, value):

    if status(board):
        return utility(board), value

    best = -1000
    bestMove = -1

    # declare all possible actions for the current game
    possible_actions = []

    for i in range(3):
        for j in range(3):
            if (board[i][j] == '-'):
                possible_actions.append((i,j))

    possible = copy.deepcopy(possible_actions)

    # loop through possible moves and recursive call minimax
    for i in possible:
        bestVal = minvalue(result(board, i), i)

        # max (v, min-val)
        if best < bestVal[0]:
            best = bestVal[0]
            bestMove = i

        gameState = array_to_string(result(board, i))
        util = str(bestVal[0])
        # store state and util and output to file
        # print(gameState + ' ' + util)
        file = open(sys.argv[2], "a")
        file.write(gameState + ' ' + util + '\n')
        file.close()

    return best, bestMove


# function for alphabeta pruning maxvalue
def alpha_beta_prune_max(board, value, alpha, beta):

    # if terminal test return state and utility
    if status(board):
        return utility(board), value

    best = -1000
    bestMove = -1
    
    # declare all possible actions for the current game
    possible_actions = []

    for i in range(3):
        for j in range(3):
            if (board[i][j] == '-'):
                possible_actions.append((i,j))

    possible = copy.deepcopy(possible_actions)

    # loop through possible moves and recursive call minimax
    for i in possible:
        bestVal = alpha_beta_prune_min(result(board, i), i, alpha, beta)

        # max(v , min-val)
        if best < bestVal[0]:
            best = bestVal[0]
            bestMove = i
        
        if alpha >= beta:
            break
        
        alpha = max(best, alpha)

        gameState = array_to_string(result(board, i))
        util = str(bestVal[0])
        # store state and util and output to file
        file = open(sys.argv[2], "a")
        file.write(gameState + ' ' + util + '\n')
        file.close()
        # print(gameState + ' ' + util)

    return best, bestMove

# function for alphabeta pruning minvalue
def alpha_beta_prune_min(board, value, alpha, beta):

    # if terminal test return state and utility
    if status(board):
        return utility(board), value

    best = 1000
    bestMove = -1

    # declare all possible actions for the current game
    possible_actions = []

    for i in range(3):
        for j in range(3):
            if (board[i][j] == '-'):
                possible_actions.append((i,j))

    possible = copy.deepcopy(possible_actions)

    # loop through possible moves and recursive call minimax
    for i in possible:
        bestVal = alpha_beta_prune_max(result(board, i), i, alpha, beta)

        # min (v, max-val)
        if best > bestVal[0]:
            best = bestVal[0]
            bestMove = i

        if alpha >= beta:
            break

        beta = min(best, beta)

        gameState = array_to_string(result(board, i))
        util = str(bestVal[0])
        # store state and util and output to file
        file = open(sys.argv[2], "a")
        file.write(gameState + ' ' + util + '\n')
        file.close()
        # print(gameState + ' ' + util)

    return best, bestMove


# function to convert string into array
def string_to_array(board):   

    b = [[],[],[]]
    list_count = 0

    for y in board:
        if list_count <= 5 and list_count >= 3:
            b[1].append(y)
        elif list_count <= 8 and list_count >= 6:
            b[2].append(y)
        elif list_count <= 2 and list_count >= 0:
            b[0].append(y)
        list_count += 1

    return b


# function to convert 2d matrix to string
def array_to_string(board):

    new_str = ""

    for i in range(3):
        for j in range(3):
            new_str += board[i][j]

    return new_str


if __name__ == "__main__":

    file = open(sys.argv[2], "w")
    file.write("")
    file.close()

    board = sys.argv[1]
    game = string_to_array(board)

    value = ()

    # minimax Decision from lecture

    gameState = status(game)

    print "bruh"

    # if prune found in command line
    if len(sys.argv) > 3:
        if sys.argv[3] == "prune":
            if gameState:
                gameState = None
            
            if curr_player(game) == 'x':
                value = alpha_beta_prune_max(game, (), -1000, 1000)
            elif curr_player(game) == 'o':
                value = alpha_beta_prune_min(game, (), -1000, 1000)

    # if ply argument found
    elif len(sys.argv) > 4:
        if sys.argv[4]:
            print "ply"

    # else run naive minimax
    else:
        if gameState:
            gameState = None
        
        if curr_player(game) == 'x':
            value = maxvalue(game,())
        elif curr_player(game) == 'o':
            value = minvalue(game,())
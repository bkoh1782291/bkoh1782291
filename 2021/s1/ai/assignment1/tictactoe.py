# Brian Koh
# a1782291
# Artificial Intelligence Assignment 1
# usage : $ python tictactoe.py [state] [path]
#       : $ python tictactoe.py [state] [path] prune
#       : $ python tictactoe.py [state] [path] prune 3

import sys
import copy

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
        if ((b[a][0] == b[a][1] == b[a][2]) and (b[a][0] == 'x')):
            return 'x'
        elif ((b[a][0] == b[a][1] == b[a][2]) and (b[a][0] == 'o')):
            return 'o'

        # cols
        if ((b[0][a] == b[1][a] == b[2][a]) and (b[0][a] == 'x')):
            return 'x'
        elif ((b[0][a] == b[1][a] == b[2][a]) and (b[0][a] == 'o')):
            return 'o'

    # diagonals
    if (((b[0][0] == b[1][1] == b[2][2]) or (b[0][2] == b[1][1] == b[2][0])) and (b[1][1] == 'x')):
        return 'x'
    elif (((b[0][0] == b[1][1] == b[2][2]) or (b[0][2] == b[1][1] == b[2][0])) and (b[1][1] == 'o')):
        return 'o'
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


# copy board with deepcopy, suited for recursive calls
def result(board, action):

    x = action[0]
    y = action[1]
    board_copy = copy.deepcopy(board)
    board_copy[x][y] = curr_player(board)

    return board_copy


# minimizer function
def minvalue(board, value):

    # if terminal test, return utility(state)
    if status(board):
        return utility(board), value

    # best = infinity
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

        # store state and util and output to file
        gameState = array_to_string(result(board, i))
        util = str(bestVal[0])
        
        file = open(sys.argv[2], "a")
        file.write(gameState + ' ' + util + '\n')
        file.close()

    return best, bestMove


def maxvalue(board, value):

    # if terminal test, return utility(state)
    if status(board):
        return utility(board), value

    # best = -inf
    best = -10000
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

        # store state and util and output to file
        gameState = array_to_string(result(board, i))
        util = str(bestVal[0])
        
        file = open(sys.argv[2], "a")
        file.write(gameState + ' ' + util + '\n')
        file.close()

    return best, bestMove



# function for alphabeta pruning minvalue
def alpha_beta_prune_min(board, value, alpha, beta):

    # if terminal test return state and utility
    if status(board):
        return utility(board), value

    # best = +inf
    best = 10000

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

        # if best is less than alpha, write to output
        if best <= alpha:
            gameState = array_to_string(result(board, i))
            util = str(bestVal[0])
            file = open(sys.argv[2], "a")
            file.write(gameState + ' ' + util + '\n')
            file.close()
            return best, bestMove

        # if best less than beta update value
        beta = min(best, beta)

        # store state and util and output to file
        gameState = array_to_string(result(board, i))
        util = str(bestVal[0])
        file = open(sys.argv[2], "a")
        file.write(gameState + ' ' + util + '\n')
        file.close()

    return best, bestMove


# function for alphabeta pruning maxvalue
def alpha_beta_prune_max(board, value, alpha, beta):

    # if terminal test return state and utility
    if status(board):
        return utility(board), value

    # best = -inf
    best = -10000
    
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
        
        # if best is more than beta, write to output
        if best >= beta:
            gameState = array_to_string(result(board, i))
            util = str(bestVal[0])
            file = open(sys.argv[2], "a")
            file.write(gameState + ' ' + util + '\n')
            file.close()
            return best, bestMove

        # if best is more than alpha, update value
        alpha = max(alpha, best)

        gameState = array_to_string(result(board, i))
        util = str(bestVal[0])
        # store state and util and output to file
        file = open(sys.argv[2], "a")
        file.write(gameState + ' ' + util + '\n')
        file.close()

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


# begin early termination question
# Evaluation function for game states
# as different states are fed into this function, states are evaluated and total wins are calcuated
def evaluation(board, character):

    winning_lines = 0
    for a in range(3):
        # rows
        if (board[0][a] == board[1][a] == board[2][a] == character):
            winning_lines += 1
        # cols
        if (board[a][0] == board[a][1] == board[a][2] == character):
            winning_lines += 1

    #diagonals
    if (board[0][0] == board[1][1] == board[2][2] == character):
        winning_lines += 1
    if (board[0][2] == board[1][1] == board[2][0] == character):
        winning_lines += 1

    return winning_lines


# early termination for tree traversal for min value
def early_termination_min(board, value, alpha, beta, depth, cutoff):
    
    # copy into new board
    max_board = copy.deepcopy(board)
    min_board = copy.deepcopy(board)

    for i in range(3):
        for j in range(3):
            if(max_board[i][j] == '-'):
                max_board[i][j] = 'x'

    for k in range(3):
        for l in range(3):
            if(min_board[k][l] == '-'):
                min_board[k][l] = 'o'

    max_wins = evaluation(max_board, 'x')
    min_wins = evaluation(min_board, 'o')

    # E(s) = M(s) - O(s)
    results = max_wins - min_wins

    # if terminal test, return utility(state)
    if (status(board)):
        return results, value

    if (depth >= cutoff):
        return results, value

    best = 1000
    # declare all possible actions for the current game
    possible_actions = []
    for i in range(3):
        for j in range(3):
            if (board[i][j] == '-'):
                possible_actions.append((i,j))
    possible = copy.deepcopy(possible_actions)

    # loop through possible moves and recursive call minimax
    for i in possible:
        bestVal = early_termination_max(result(board, i), i, alpha, beta, depth+1, cutoff)

        # min (v, max-val)
        if best > bestVal[0]:
            best = bestVal[0]
            bestMove = i

        # if best is less than alpha, write to output
        if best <= alpha:
            gameState = array_to_string(result(board, i))
            util = str(bestVal[0])
            file = open(sys.argv[2], "a")
            file.write(gameState + ' ' + util + '\n')
            file.close()
            return best, bestMove

        # if best less than beta update value
        beta = min(best, beta)

        # store state and util and output to file
        gameState = array_to_string(result(board, i))
        util = str(bestVal[0])
        file = open(sys.argv[2], "a")
        file.write(gameState + ' ' + util + '\n')
        file.close()

    return best, bestMove


# early termination for tree traversal for max value
def early_termination_max(board, value, alpha, beta, depth, cutoff):

    # deep copy into new board
    max_board = copy.deepcopy(board)
    min_board = copy.deepcopy(board)

    for i in range(3):
        for j in range(3):
            if(max_board[i][j] == '-'):
                max_board[i][j] = 'x'

    for k in range(3):
        for l in range(3):
            if(min_board[k][l] == '-'):
                min_board[k][l] = 'o'

    max_wins = evaluation(max_board, 'x')
    min_wins = evaluation(min_board, 'o')

    # E(s) = M(s) - O(s)
    results = max_wins - min_wins

    # if terminal test, return utility(state)
    if (status(board)):
        return results, value

    if (depth >= cutoff):
        return results, value

    best = -1000
    # declare all possible actions for the current game
    possible_actions = []
    for i in range(3):
        for j in range(3):
            if (board[i][j] == '-'):
                possible_actions.append((i,j))
    possible = copy.deepcopy(possible_actions)

    # loop through possible moves and recursive call minimax
    for i in possible:
        bestVal = early_termination_min(result(board, i), i, alpha, beta, depth+1, cutoff)

        # max(v , min-val)
        if best < bestVal[0]:
            best = bestVal[0]
            bestMove = i
        
        # if best is more than beta, write to output
        if best >= beta:
            gameState = array_to_string(result(board, i))
            util = str(bestVal[0])
            file = open(sys.argv[2], "a")
            file.write(gameState + ' ' + util + '\n')
            file.close()
            return best, bestMove

        # if best is more than alpha, update value
        alpha = max(alpha, best)

        gameState = array_to_string(result(board, i))
        util = str(bestVal[0])
        # store state and util and output to file
        file = open(sys.argv[2], "a")
        file.write(gameState + ' ' + util + '\n')
        file.close()
    
    return best, bestMove


# function to print the best move called in main()
def print_best_move(board, value, isMax):

    if isMax == 'x':
        bestMove_board[value[1][0]][value[1][1]] = 'x'
        print array_to_string(bestMove_board)

    elif isMax == 'o':
        bestMove_board[value[1][0]][value[1][1]] = 'o'
        print array_to_string(bestMove_board)


# main function
if __name__ == "__main__":
    
    # flush output file
    file = open(sys.argv[2], "w")
    file.write("")
    file.close()

    board = sys.argv[1]
    game = string_to_array(board)
    value = ()
    gameState = status(game)
    bestMove_board = game

    # minimax Decision from lecture
    # if no special args run naive minimax
    if len(sys.argv) == 3:
        if gameState:
            gameState = None
        
        if curr_player(game) == 'x':
            value = maxvalue(game,())
            print_best_move(bestMove_board, value, 'x')

        elif curr_player(game) == 'o':
            value = minvalue(game,())
            print_best_move(bestMove_board, value, 'o')
    
    # if prune found in command line run ab_pruning
    elif len(sys.argv) == 4 and sys.argv[3] == "prune":
        
            if gameState:
                gameState = None
            
            if curr_player(game) == 'x':
                value = alpha_beta_prune_max(game, (), -1000, 1000)
                print_best_move(bestMove_board, value, 'x')

            elif curr_player(game) == 'o':
                value = alpha_beta_prune_min(game, (), -1000, 1000)
                print_best_move(bestMove_board, value, 'o')

    # if ply argument found run early termination on top of ab pruning
    elif len(sys.argv) == 5:
        if gameState:
            gameState = None
        
        if curr_player(game) == 'x':
            value = early_termination_max(game, (), -1000, 1000, 0, int(sys.argv[4]))
            print_best_move(bestMove_board, value, 'x')

        elif curr_player(game) == 'o':
            value = early_termination_min(game, (), -1000, 1000, 0, int(sys.argv[4]))
            print_best_move(bestMove_board, value, 'o')
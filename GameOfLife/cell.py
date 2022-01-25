import numpy as np
import os
import time
import _thread

def add_padding(grid, padding):
    return np.pad(grid, padding)

def cell_state(block, cell_state):
    neighbors = np.sum(block) - cell_state
    if cell_state == 1 and ( neighbors == 2 or neighbors == 3 ): # if alive
        return 1
    elif cell_state == 0 and neighbors == 3:
        return 1
    else:
        return 0


def get_block(grid, i, j):
    return grid[ i-1:i+2, j-1:j+2 ]

# Padding should be added before that
def update_state(grid):
    new_state = np.zeros(np.shape(grid))
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            c = cell_state(get_block(grid, i, j), grid[i][j])
            new_state[i][j] = c
    return np.array(new_state)

def visualize(grid):
    for row in grid:
        for cell in row:
            if cell == 1:
                print("0", end = "")
            else:
                print(".", end = "")
        print("") # newline

if __name__ == '__main__':
    with open("glider.txt", "r") as file:
        state = np.array([list(x.strip()) for x in file.readlines()], dtype='object')
        state = np.where(state == ".", np.zeros(np.shape(state)), 1)

    state = add_padding(state, 10)

    while True:
        visualize(state)
        state = update_state(state)
        time.sleep(0.1)
        os.system('clear')

    # state  = np.array([[1,0,1], [1, 2, 1]])
    # print(update_state(state))

from copy import deepcopy

def solution(key, lock):
    answer = True
    rotate90, rotate180, rotate270 = rotate(key)
    padded_lock = zero_pad(lock, len(key)-1)

    scan_size = len(padded_lock) - len(key) + 1
    for i in range(0, scan_size):
        for j in range(0, scan_size):
            if is_solve(i, j, key, padded_lock):
                return answer
            if is_solve(i, j, rotate90, padded_lock):
                return answer
            if is_solve(i, j, rotate180, padded_lock):
                return answer
            if is_solve(i, j, rotate270, padded_lock):
                return answer
    answer = False
    return answer

def rotate(key):
    n = len(key)
    rotate90 = [[key[n-1-j][i] for j in range(0,n)] for i in range(0,n)]
    rotate180 = [[key[n-1-i][n-1-j] for j in range(0,n)] for i in range(0,n)]
    rotate270 = [[key[j][n-1-i] for j in range(0,n)] for i in range(0,n)]
    return rotate90, rotate180, rotate270

def zero_pad(lock, key_size):
    return [[-1]*(len(lock[0])+2*key_size)]*key_size    + \
           [[-1]*key_size+r+[-1]*key_size for r in lock] + \
           [[-1]*(len(lock[0])+2*key_size)]*key_size

def is_solve(x_start, y_start, key, padded_lock):
    copied_lock = deepcopy(padded_lock)
    key_size = len(key)
    for i in range(0, key_size):
        for j in range(0, key_size):
            if copied_lock[x_start + i][y_start + j] == 1 and key[i][j] == 1:
                return False
            elif copied_lock[x_start + i][y_start + j] == 0 and key[i][j] == 1:
                copied_lock[x_start + i][y_start + j] = 1
    scan_start = key_size - 1
    scan_end = len(padded_lock) - key_size + 1

    for i in range(scan_start, scan_end):
        for j in range(scan_start, scan_end):
            if (copied_lock[i][j] == 0):
                return False

    return True

solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]]	, [[1, 1, 1], [1, 1, 0], [1, 0, 1]]	)
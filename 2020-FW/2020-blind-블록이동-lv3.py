from collections import deque

# 상하좌우 이동 및 회전 8 종류까지 총 12종 이동 경우의 수 파악
def move(loc1, loc2, board): 
    direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    ret = []
    for m in direction:
        if board[loc1[0] + m[0]][loc1[1] + m[1]] == 0 and board[loc2[0] + m[0]][loc2[1] + m[1]] == 0:
            ret.append({(loc1[0] + m[0], loc1[1] + m[1]), (loc2[0] + m[0], loc2[1] + m[1])})

    rotate = [1, -1]
    # loc1과 loc2의 x좌표가 같음 == 가로회전
    if loc1[0] == loc2[0]:
        for r in rotate:
            if board[loc1[0] + r][loc1[1]] == 0 and board[loc2[0] + r][loc2[1]] == 0:
                ret.append({(loc1[0] + r, loc1[1]), (loc1[0], loc1[1])})
                ret.append({(loc2[0] + r, loc2[1]), (loc2[0], loc2[1])})
    # 그렇지 않으면 세로회전
    else:
        for r in rotate:
            if board[loc1[0]][loc1[1] + r] == 0 and board[loc2[0]][loc2[1] + r] == 0:
                ret.append({(loc1[0], loc1[1] + r), (loc1[0], loc1[1])})
                ret.append({(loc2[0], loc2[1] + r), (loc2[0], loc2[1])})
    
    # 이동 가능한 2개 좌표 집합의 리스트 [{(), ()}, {(), ()}, {(), ()}] ---
    return ret

def solution(board):
    size = len(board)
    # 상하좌우에 1로된 벽 추가
    new_board = [[1 for i in range(len(board)+2)] for i in range(len(board)+2)] 
    for i in range(len(board)):
        for j in range(len(board)):
            new_board[i+1][j+1] = board[i][j]
    
    # BFS위한 queue 추가
    que = deque()
    visited = []

    # 좌표와 거리(걸린 시간)를 queue에 추가
    que.append([{(1, 1), (1, 2)}, 0])
    # 방문한 좌표 집합에 대해서 체크
    visited.append({(1, 1), (1, 2)})

    while len(que)!= 0:
        temp = que.popleft()
        loc = list(temp[0])
        dist = temp[1]+1

        for m in move(loc[0], loc[1], new_board):
            if (size, size) in m:
                return dist
            
            elif not m in visited:
                que.append([m, dist])
                visited.append(m)

    return 0
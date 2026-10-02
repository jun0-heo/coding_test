from collections import deque

def check(room):
    dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    for r in range(5):
        for c in range(5):
            if room[r][c] != 'P':
                continue
            visited = [[False] * 5 for _ in range(5)]
            visited[r][c] = True
            q = deque([(r, c, 0)])
            while q:
                y, x, d = q.popleft()
                if d == 2:
                    continue
                for dy, dx in dirs:
                    ny, nx = y + dy, x + dx
                    if not (0 <= ny < 5 and 0 <= nx < 5):
                        continue
                    if visited[ny][nx] or room[ny][nx] == 'X':
                        continue
                    if room[ny][nx] == 'P':
                        return 0
                    visited[ny][nx] = True
                    q.append((ny, nx, d + 1))
    return 1

def solution(places):
    return [check(room) for room in places]
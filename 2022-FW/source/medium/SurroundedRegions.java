package medium;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class SurroundedRegions {
    private Queue<Pair> queue = new LinkedList<>();
    private char[][] result;
    private int m;
    private int n;

    class Pair{
        Integer first;
        Integer second;
        public Pair(Integer first, Integer second) {
            this.first = first;
            this.second = second;
        }
        public Integer first() {
            return first;
        }
        public Integer second() {
            return second;
        }
    }

    public void solve(char[][] board) {
        m = board.length;
        n = board[0].length;
        result = new char[m][n];

        for(char[] row : result)
            Arrays.fill(row, 'X');

        for (int i = 0; i < m; i++) {
            findAdjacentRegion(i, 0, board[i][0]);
            findAdjacentRegion(i, n-1, board[i][n-1]);
        }
        for (int j = 0; j < n; j++) {
            findAdjacentRegion(0, j, board[0][j]);
            findAdjacentRegion(m-1, j, board[m-1][j]);
        }

        while(!queue.isEmpty()) {
            Pair pair = queue.poll();
            bfs(board, pair.first(), pair.second());
        }


        for (int i = 0; i < board.length; i++) board[i] = Arrays.copyOf(result[i], result[i].length);
    }

    public void bfs(char[][] board, int i, int j) {
        if (i > 0) {
            findAdjacentRegion(i-1, j, board[i-1][j]);
        }
        if (i < m-1) {
            findAdjacentRegion(i+1, j, board[i+1][j]);
        }
        if (j > 0) {
            findAdjacentRegion(i, j-1, board[i][j-1]);
        }
        if (j < n-1) {
            findAdjacentRegion(i, j+1, board[i][j+1]);
        }
    }

    public void findAdjacentRegion(int i, int j, char region) {
        if (region == 'O' && result[i][j] == 'X') {
            result[i][j] = 'O';
            queue.add(new Pair(i, j));
        }
    }
}

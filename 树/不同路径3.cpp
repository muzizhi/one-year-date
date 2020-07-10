
960、不同路径3: 有障碍物，起点和终点不定表示为1/2，要求每个格子走一次，几种？
思路：有种数独感，好难可能没有。稍微看看答案解析吧，官方回溯：统计开始和结束和可走个数，尝试遍历每一个 0 方格，并在走过的方格里留下一个障碍。
回溯的时候，我们要删除那些自己留下的障碍。不好的路径很快就会因没有无障碍的方格可以走而被卡住。
知识点：【2020.7.11】hard
最好理解：先遍历一遍grid，找到起点、终点并且统计无障碍方格的总数；深度优先搜索，每次到达终点，判断（当前步数 == 无障碍方格的总数 - 1）进行不同路径计数；返回值


/*class Solution {
    public int uniquePathsIII(int[][] grid) {

    }
}*/


class Solution {
    int ans;
    int[][] grid;
    int tr, tc;
    int[] dr = new int[]{0, -1, 0, 1};
    int[] dc = new int[]{1, 0, -1, 0};
    int R, C;

    public int uniquePathsIII(int[][] grid) {
        this.grid = grid;
        R = grid.length;
        C = grid[0].length;

        int todo = 0;
        int sr = 0, sc = 0;
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] != -1) {
                    todo++;
                }

                if (grid[r][c] == 1) {
                    sr = r;
                    sc = c;
                } else if (grid[r][c] == 2) {
                    tr = r;
                    tc = c;
                }
            }

        ans = 0;
        dfs(sr, sc, todo);
        return ans;
    }

    public void dfs(int r, int c, int todo) {
        todo--;
        if (todo < 0) return;
        if (r == tr && c == tc) {
            if (todo == 0) ans++;
            return;
        }

        grid[r][c] = 3;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (0 <= nr && nr < R && 0 <= nc && nc < C) {
                if (grid[nr][nc] % 2 == 0)
                    dfs(nr, nc, todo);
            }
        }
        todo++; //why 不用这一句，也能得到正确值？？奇怪
        grid[r][c] = 0;
    }
}

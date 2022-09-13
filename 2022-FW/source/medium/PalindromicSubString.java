package medium;

class PalindromicSubString {
    public String longestPalindrome(String s) {
        int n = s.length();
        int[][] dp = new int[n+1][n+1];
        int rI = 1;
        int rJ = 1;

        for (int i = 1; i <= n; i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int lastIndex = i + j - 2;
                if (lastIndex < n && s.charAt(j - 1) == s.charAt(lastIndex) && (i == 2 || dp[i - 2][j + 1] != 0)) {
                    dp[i][j] = dp[i - 2][j + 1] + 2;
                    rI = i;
                    rJ = j;
                }
            }
        }

        return s.substring(rJ - 1, rJ + rI - 1);
    }
}

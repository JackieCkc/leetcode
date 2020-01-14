// There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

// Note:
// All costs are positive integers.

// Example:

// Input: [[17,2,17],[16,16,5],[14,3,19]]
// Output: 10
// Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. 
//              Minimum cost: 2 + 5 + 3 = 10.


class Solution {
    private int[][] mem;
    
    public int minCost(int[][] costs) {
        mem = new int[costs.length][3];
        return dfs(costs, 0, -1);
    }
    
    private int dfs(int[][] costs, int i, int p) {
        if (i == costs.length) return 0;        
        if (p != -1 && mem[i][p] != 0) return mem[i][p];
        
        int res = Integer.MAX_VALUE;
        for (int j = 0; j < 3; j++) {
            if (j == p) continue;
            res = Math.min(res, costs[i][j] + dfs(costs, i + 1, j));
        }
        if (p != -1) mem[i][p] = res;
        return res;
    }
}

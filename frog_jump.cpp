/*Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

Example:

Input: heights[] = [20, 30, 40, 20] 
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20-30|  = 10
Total Cost = 10 + 10 = 20
Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40-50|  = 10
Total Cost = 20 + 10 = 30
Constraints:

1 <= height.size() <= 105
0 <= height[i]<=104
*/
// memorizationclass
/*
Solution {
public:
    int solve(int ind, vector<int>& height, vector<int>& dp) {
        if (ind == 0) return 0;

        if (dp[ind] != -1) return dp[ind];

        int min_cost = INT_MAX;
        for (int i = 1; i <= 2; i++) {
            if (ind - i >= 0) {
                int jump = solve(ind - i, height, dp) + abs(height[ind] - height[ind - i]);
                min_cost = min(min_cost, jump);
            }
        }

        return dp[ind] = min_cost;
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1); // Memoization table
        return solve(n - 1, height, dp);
    }
};
*/
// memoriztion without using loop in binary (1or2) jumps
/*
class Solution {
public:
    int solve(int ind, vector<int>& height, vector<int>& dp) {
        if (ind == 0) return 0;

        if (dp[ind] != -1) return dp[ind];

        int jump = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
        
        int jump2=INT_MAX;
        
        if(ind-2>=0){
            jump2 = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
        }
        
        dp[ind] = min(jump,jump2);
            

        return dp[ind];
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1); // Memoization table
        return solve(n - 1, height, dp);
    }
};
*/
// tabulation approach
/*
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 0);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            int jump = dp[i - 1] + abs(height[i] - height[i - 1]);
            int jump2 = (i-2>=0) ? dp[i - 2] + abs(height[i] - height[i - 2]) : INT_MAX;
            dp[i] = min(jump, jump2);
        }

        return dp[n - 1];
    }
};
*/
// IF K JUMP IS THERE 
// memoization approach
class Solution {
public:
    int memoSolve(int ind, vector<int>& height, vector<int>& dp, int k) {
        if (ind == 0) return 0;
        if (dp[ind] != -1) return dp[ind];

        int minCost = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (ind - j >= 0) {
                int cost = memoSolve(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
                minCost = min(minCost, cost);
            }
        }

        return dp[ind] = minCost;
    }

    int minCostMemoization(vector<int>& height, int k) {
        int n = height.size();
        vector<int> dp(n, -1);
        return memoSolve(n - 1, height, dp, k);
    }
};
// tabulation approach
class Solution {
public:
    int minCostTabulation(vector<int>& height, int k) {
        int n = height.size();
        vector<int> dp(n, 0);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            int minCost = INT_MAX;

            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int cost = dp[i - j] + abs(height[i] - height[i - j]);
                    minCost = min(minCost, cost);
                }
            }

            dp[i] = minCost;
        }

        return dp[n - 1];
    }
};





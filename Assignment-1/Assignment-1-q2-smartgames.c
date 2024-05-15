#include<stdio.h>
#include<stdbool.h>

int minimax(int depth, int nodeindex, bool player, int evals[]) {
    // Base case: If the depth is 0 or the nodeindex is out of bounds
    if (depth == 0 || nodeindex >= 7) {
        return evals[nodeindex];
    }

    if (player) { // Maximizer's turn
        int maxEval = -1000; // Assuming the evaluation values won't exceed this limit
        for (int i = 0; i < 2; i++) {
            int eval = minimax(depth - 1, 2 * nodeindex + 1 + i, false, evals);
            maxEval = (eval > maxEval) ? eval : maxEval;
        }
        return maxEval;
    } else { // Minimizer's turn
        int minEval = 1000; // Assuming the evaluation values won't go below this limit
        for (int i = 0; i < 2; i++) {
            int eval = minimax(depth - 1, 2 * nodeindex + 1 + i, true, evals);
            minEval = (eval < minEval) ? eval : minEval;
        }
        return minEval;
    }
}

int main() {
    int evals[] = {3, 5, 2, 9, 12, 5, 23, 23};
    int res = minimax(4, 0, true, evals);
    printf("The optimal value is: %d\n", res);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

// Function to implement Alpha-Beta Pruning
int alphabetaminimax(int depth, int nodeindex, bool player, int evals[], int alpha, int beta) {
    // Base case: If depth is the maximum depth, return the evaluation value
    if (depth == 4) {
        return evals[nodeindex];
    }

    if (player) {  // Maximizer's move
        int maxEval = -1000;
        for (int i = 0; i < 2; i++) {
            int eval = alphabetaminimax(depth + 1, nodeindex * 2 + i, false, evals, alpha, beta);
            if (eval > maxEval) {
                maxEval = eval;
            }
            if (eval > alpha) {
                alpha = eval;
            }
            if (beta <= alpha) {
                break;  // Beta cut-off
            }
        }
        return maxEval;
    } else {  // Minimizer's move
        int minEval = 1000;
        for (int i = 0; i < 2; i++) {
            int eval = alphabetaminimax(depth + 1, nodeindex * 2 + i, true, evals, alpha, beta);
            if (eval < minEval) {
                minEval = eval;
            }
            if (eval < beta) {
                beta = eval;
            }
            if (beta <= alpha) {
                break;  // Alpha cut-off
            }
        }
        return minEval;
    }
}





int main() {
    int evals[] = {3, 5, 2, 9, 12, 5, 7, -6, 3, 4, -3, 9, -8, -3, -100, 2};
    int res = alphabetaminimax(0, 0, true, evals, -1000, 1000);
    printf("The optimal value is: %d\n", res);
    return 0;
}
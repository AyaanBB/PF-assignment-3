#include <stdio.h>
#include <string.h>

struct Player {
    int ballScores[12];
    char playerName[50];
    int totalScore;
};

int validateScore(int score) {
    return (score >= 0 && score <= 6);
}

void playGame(struct Player *player) {
    printf("Enter scores for %s:\n", player->playerName);
    player->totalScore = 0;
    for (int i = 0; i < 12; i++) {
        printf("Ball %d: ", i + 1);
        scanf("%d", &player->ballScores[i]);
        if (!validateScore(player->ballScores[i])) {
            printf("Invalid score. Marking the ball as played.\n");
            player->ballScores[i] = 0;
        }
        player->totalScore += player->ballScores[i];
    }
}

void findWinner(struct Player player1, struct Player player2) {
    if (player1.totalScore > player2.totalScore) {
        printf("Winner: %s with %d runs!\n", player1.playerName, player1.totalScore);
    } else if (player1.totalScore < player2.totalScore) {
        printf("Winner: %s with %d runs!\n", player2.playerName, player2.totalScore);
    } else {
        printf("The match is a tie! Both scored %d runs.\n", player1.totalScore);
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\n--- Match Scoreboard ---\n");
    for (int i = 0; i < 2; i++) {
        struct Player player = i == 0 ? player1 : player2;
        printf("Player: %s\n", player.playerName);
        printf("Scores: ");
        for (int j = 0; j < 12; j++) {
            printf("%d ", player.ballScores[j]);
        }
        printf("\nAverage Score: %.2f\n", player.totalScore / 12.0);
        printf("Total Score: %d\n\n", player.totalScore);
    }
}

int main() {
    struct Player player1, player2;
    strcpy(player1.playerName, "Player 1");
    strcpy(player2.playerName, "Player 2");
    playGame(&player1);
    playGame(&player2);
    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);
    return 0;
}

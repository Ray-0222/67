
#include <stdio.h>

typedef struct {
    int id;
    int power;
} Player;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Player list[10];
    int count = 0;

    for (int i = 0; i < N; i++) {
        Player newPlayer;
        scanf("%d %d", &newPlayer.id, &newPlayer.power);

        // 1. 資格審查
        if (count == K) {
            Player last = list[count - 1];

            if (newPlayer.power < last.power ||
                (newPlayer.power == last.power &&
                 newPlayer.id >= last.id)) {

                printf("Player %d rejected\n", newPlayer.id);
                continue;
            }

            // 淘汰最後一名
            count--;
        }

        // 2. 插入排序
        int j = count - 1;

        while (j >= 0 &&
              (list[j].power < newPlayer.power ||
              (list[j].power == newPlayer.power &&
               list[j].id > newPlayer.id))) {

            list[j + 1] = list[j];
            j--;
        }

        // 插入新玩家
        list[j + 1] = newPlayer;
        count++;

        // 3. 輸出排行榜
        printf("Leaderboard:");

        for (int j = 0; j < count; j++) {
            printf(" (%d, %d)", list[j].id, list[j].power);
        }

        printf("\n");
    }

    return 0;
}

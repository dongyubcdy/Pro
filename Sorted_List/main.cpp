#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init();
extern void insert(int data);
extern int remove(int index);
extern int searchByIndex(int index);

#define INSERT	100
#define REMOVE	200
#define SBI		300

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main() {
    setbuf(stdout, NULL);
    int T;
    scanf("%d", &T);
    int N;
    int cmd, ret;
    int idx, data;
    for (int TC = 1; TC <= T; TC++) {

        init();

        int score = 100;

        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &cmd);

            switch (cmd) {

            case INSERT:
                scanf("%d", &data);
                insert(data);

                break;

            case REMOVE:
                scanf("%d %d", &idx, &data);

                ret = remove(idx);

                if (ret != data) {
                    score = 0;
                }
                break;

            case SBI:
                scanf("%d %d", &idx, &data);

                ret = searchByIndex(idx);

                if (ret != data) {
                    score = 0;
                }
                break;
            }
        }

        printf("#%d %d\n", TC, score);
    }

    return 0;
}

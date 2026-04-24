#include <stdio.h>

int main() {
    int n, i, j, time = 0, completed = 0;
    
    int at[10], bt[10], wt[10], tat[10], ct[10];
    int p[10], done[10];

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    
    for(i = 0; i < n; i++) {
        printf("\nP%d AT and BT: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        p[i] = i + 1;
        done[i] = 0;
    }

    while(completed < n) {
        int min_bt = 9999, index = -1;

        
        for(i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    index = i;
                }
            }
        }

        if(index != -1) {
            time += bt[index];
            ct[index] = time;

            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            avg_wt += wt[index];
            avg_tat += tat[index];

            done[index] = 1;
            completed++;
        } else {
            time++;  // CPU idle
        }
    }

    
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage WT = %.2f", avg_wt/n);
    printf("\nAverage TAT = %.2f\n", avg_tat/n);

    return 0;
}

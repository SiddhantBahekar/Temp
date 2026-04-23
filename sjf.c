#include <stdio.h>

int main() {
    int n, i, j;
    int bt[10], wt[10], tat[10], p[10];

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i + 1; // Process ID
    }

    // Sorting (SJF)
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                // Swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process ID
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Waiting Time
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Output
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f", avg_wt/n);
    printf("\nAverage TAT = %.2f\n", avg_tat/n);

    return 0;
}

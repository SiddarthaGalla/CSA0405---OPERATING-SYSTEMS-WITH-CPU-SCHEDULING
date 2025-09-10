#include <stdio.h>
int main(){
    int b[10], WT[10], TAT[10];
    int TWT = 0, TTAT = 0, ATWT, ATTAT, i, j, n,temp;

    printf("Enter no of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }   

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
     WT[0] = 0;  
    for (i = 1; i < n; i++) {
        WT[i] = b[i - 1] + WT[i - 1];
        TWT += WT[i];
    }
    ATWT = TWT / n;

    for (i = 0; i < n; i++) {
        TAT[i] = b[i] + WT[i];
        TTAT += TAT[i];
    }
    ATTAT = TTAT / n;

    printf("The average waiting time = %d\n", ATWT);
    printf("The average turnaround time = %d\n", ATTAT);

    return 0;
}

Output :
Enter no of processes: 4
Enter burst times:
8 6 4 2
The average waiting time = 5
The average turnaround time = 10


#include <stdio.h>
int main(){
    int b[10], WT[10], TAT[10],pr[10];
    int TWT = 0, TTAT = 0, i, j, m, n,temp;
    float ATWT, ATTAT;
    
    printf("Enter no of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }   

    printf("Enter no of processes: ");
    scanf("%d", &m);
    printf("Enter the priority number:");
    for (i = 0; i < m; i++) {
        scanf("%d",&pr[i]);
    }

    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (pr[j] > pr[j + 1]) {
                temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;

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

    printf("The average waiting time = %f\n", ATWT);
    printf("The average turnaround time = %f\n", ATTAT);

    return 0;
}

OUTPUT :
Enter no of processes: 4
Enter burst times:
8 6 4 2
Enter no of processes: 4
Enter the priority number:
4 2 1 3
The average waiting time = 6.000000
The average turnaround time = 11.000000

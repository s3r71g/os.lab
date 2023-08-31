#include<stdio.h>

void waitingTime(int processors[], int n, int wt[], int bt[]){
                 wt[0] = 0;
                 int i;
                 for(i=1; i<n; i++){
                    wt[i] =bt[i-1] + wt[i-1];
                 }
}

void turnAroundTime(int processors[], int n, int tat[], int bt[], int wt[]){
                 int i;
                 for(i=0; i<n; i++){
                    tat[i] =bt[i] + wt[i];
                 }
}

void avgTime(int processors[], int n, int bt[] ){
    int waitTime[n], tatTime[n], totalWT = 0, totalTAT = 0;
    waitingTime(processors, n, waitTime, bt);
    turnAroundTime(processors, n, tatTime, bt, waitTime);
    int i;
    for(i=0; i<n; i++){
        totalWT += waitTime[i];
        totalTAT += tatTime[i];
        
        printf("\n%d\t%d\t%d\t%d", processors[i], bt[i], waitTime[i], tatTime[i]);
    }
    float s1 = (float)totalWT/(float)n;
    float s2 = (float)totalTAT/(float)n;
    printf("\n\nAverage waiting time = %f",s1 );
    printf("\nAverage turn around time = %f\n", s2);
}

int main()
{
    
    int ch;
    while(ch!=3)
    {
        printf("\nFinding TurnaroundTime and WaitingTime for: \n");
        printf("1.FCFS Schedule\n2.SJF Schedule\n3.EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                int n;
                printf("\nEnter number of processors: ");
                scanf("%d", &n);
                int processors[n];
                int burstTime[n];
                int i;
                for(i=0; i<n; i++)
                {
                    processors[i] = i+1;
                    printf("Enter burst time for processor %d: ", i+1);
                    scanf("%d", &burstTime[i]);
                }
                
                avgTime(processors, n, burstTime);
            }
            break;
            
            case 2:
            {
                int j,temp2,temp,i,n,burst[10],proc[10];
                printf("Enter no of processes:");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("Enter burst time of process %d:",i+1);
                    scanf("%d",&burst[i]);
                    proc[i]=i+1;
                }
                for(i=0;i<n;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(burst[i]>burst[j])
                        {
                            temp=burst[i];
                            burst[i]=burst[j];
                            burst[j]=temp;
                            temp2=proc[i];
                            proc[i]=proc[j];
                            proc[j]=temp2;
                        }
                    }
                }

                avgTime(proc, n, burst);

            }
            break;
        }
    }
    printf("\nExiting..........\n");
        
    return 0;
}

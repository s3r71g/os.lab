#include<stdio.h>
#include<stdbool.h>

//functions for Prority
void waitingtime1(int proc[],int n,int burst_time[],int wait_time[]){
    wait_time[0]=0;
    for(int i=1;i<n;i++){
        wait_time[i] = burst_time[i-1] + wait_time[i-1];
    }
}
void turnaroundtime1(int proc[],int n,int burst_time[],int wait_time[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i] = burst_time[i] + wait_time[i];
    }
 }
 
 int avgtime1(int proc[], int n, int burst_time[], int prior[]) {
  int wait_time[n], tat[n], total_wt = 0, total_tat = 0;

  waitingtime1(proc, n, burst_time, wait_time);
  turnaroundtime1(proc, n, burst_time, wait_time, tat);

  printf("Process\t  Priority\tBurst Time\tWaiting Time\tTurnaround Time\n");

  for (int i = 0; i < n; i++) {
    total_wt = total_wt + wait_time[i];
    total_tat = total_tat + tat[i];
    printf("%d\t\t%d\t%d\t\t%d\t\t%d\n", proc[i], prior[i], burst_time[i], wait_time[i], tat[i]);
  }

  printf("Average waiting time = %f\n", (float)total_wt / (float)n);
  printf("Average turn around time = %f\n", (float)total_tat / (float)n);
}

//functions for RoundRobin

int turnarroundtime2(int processes[], int n, int bt[], int wt[], int tat[]) {
   
   for (int i = 0; i < n ; i++)
   tat[i] = bt[i] + wt[i];
   return 1;
}

int waitingtime2(int processes[], int n, int bt[], int wt[], int quantum) {
   
   int rem_bt[n];
   for (int i = 0 ; i < n ; i++)
   rem_bt[i] = bt[i];
   int t = 0; 
   while (1) {
bool done = true;
      
      for (int i = 0 ; i < n; i++) {
         
         
         if (rem_bt[i] > 0) {
done = false; 
            if (rem_bt[i] > quantum) {
               t += quantum;
               rem_bt[i] -= quantum;
            }
            else {
              
               t = t + rem_bt[i];
               wt[i] = t - bt[i];
               rem_bt[i] = 0;
            }
         }
      }
      if (done == true)
         break;
   }
   return 1;
}


int findavgTime2(int processes[], int n, int bt[], int quantum) {
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
   
   waitingtime2(processes, n, bt, wt, quantum);
   turnarroundtime2(processes, n, bt, wt, tat);

   for (int i=0; i<n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      printf("\n%d\t%d\t%d\t%d\n",i+1, bt[i], wt[i], tat[i]);
   }
   printf("\nAverage waiting time = %f", (float)total_wt / (float)n);
   printf("\nAverage turnaround time = %f", (float)total_tat / (float)n);
   return 1;
}



int main() {
    
    
    int ch;
    while(ch!=3)
    {
        printf("\nFinding TurnaroundTime & WaitinngTime for: \n");
        printf("1.Prority Schedule\n2.Round Robin Schedule\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int j,temp2,temp,t3,i,n,burst[10],proc[10],prior[10];
                printf("Enter no of processes: ");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("Enter burst time of process %d: ",i+1);
                    scanf("%d",&burst[i]);
                    printf("\nEnter priority of process %d: ", i+1);
                    scanf("%d",&prior[i]);
                    proc[i]=i+1;
                }
                for(i=0;i<n;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(prior[i]<prior[j])
                        {
                            t3 = prior[i];
                            prior[i] = prior[j];
                            prior[j] = t3;

                            temp=burst[i];
                            burst[i]=burst[j];
                            burst[j]=temp;

                            temp2=proc[i];
                            proc[i]=proc[j];
                            proc[j]=temp2;
                        }
                    }
                }

                avgtime1(proc, n, burst, prior);
        
            }
            break;
            
        
            case 2:
            {
                int n;
                printf("Enter the Number of Processes: ");
                scanf("%d",&n);
                int processes[n];
                int burst_time[n];
   
                int quantum;
                printf("Enter the quantum time: ");
                scanf("%d",&quantum);
                int i=0;
                for(i=0;i<n;i++)
                {
                    processes[i]=i+1;
                    printf("Enter the Burst Time of process %d: ", i+1);
                    scanf("%d",&burst_time[i]);
                }
                
                findavgTime2(processes, n, burst_time, quantum);
            }
            break;
        }
    }
   return 0;
}

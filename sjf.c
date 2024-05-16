#include<stdio.h>

struct process{
    int arrivalTime,
        burstTime,
        pID,
        turnAroundTime,
        waitTime;
};

int main(){
    
    int n,current=0;
    float avgWT=0.0,avgTT=0.0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    struct process p[n], temp;
    
    for(int i=0;i<n;i++){
        printf("Enter arrival time of process %d:",i+1);
        scanf("%d",&p[i].arrivalTime);
        printf("Enter burst time of process %d:",i+1);
        scanf("%d",&p[i].burstTime);
        p[i].pID=i+1;
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].arrivalTime>p[j+1].arrivalTime){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        int diff = p[i].arrivalTime-current;
        if(diff>0){
            printf("\nThe CPU is in idle state for %d seconds.",diff);
            current+=diff;
        }
        
        p[i].waitTime=current-p[i].arrivalTime;
        p[i].turnAroundTime=p[i].waitTime+p[i].burstTime;
        
        printf("\nprocess %d started.",p[i].pID);
        current+=p[i].burstTime;
        printf("\nprocess %d ended after %d seconds.",p[i].pID,p[i].burstTime);
    }
    
    printf("\nPID\tArrival time\tBurst time\tWait time\tTurnaround time");
    for(int i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].pID,p[i].arrivalTime,p[i].burstTime,p[i].waitTime,p[i].turnAroundTime);
        avgWT+=p[i].waitTime;
        avgTT+=p[i].turnAroundTime;
    }
    avgWT/=n;
    avgTT/=n;
    printf("\nAverage wait time=%f",avgWT);
    printf("\nAverage turnaround time=%f",avgTT);
}
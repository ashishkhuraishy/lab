#include <stdio.h>

struct Process{
  int indx;
  int burstTime;
  int waitingTime;
  int turnAroundTime;
}process[10], temp;

void sortProcess(int n){
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(process[i].burstTime > process[j].burstTime){
        temp = process[i];
        process[i] = process[j];
        process[j] = temp;
      }
    }
  }
}


void findTimeTaken(int n){
  process[0].waitingTime = 0;
  process[0].turnAroundTime =  process[0].waitingTime + process[0].burstTime;

  for(int i=1; i<n; i++){
    process[i].waitingTime =  process[i - 1].waitingTime + process[i - 1].burstTime;
    process[i].turnAroundTime =  process[i].waitingTime + process[i].burstTime;
  }

}

void sjf(int n){
  int avgWT = 0, avgTAT = 0; 

  sortProcess(n);
  findTimeTaken(n);

  printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around\n");

  for(int i=0; i<n; i++){
    printf("\nP%d\t\t%d\t\t\t%d\t\t\t\t%d\n", process[i].indx, process[i].burstTime, process[i].waitingTime, process[i].turnAroundTime);
    avgWT = avgWT + process[i].waitingTime;
    avgTAT = avgTAT + process[i].turnAroundTime;
  }

  printf("\nAvg Waiting Time -> %d\n", avgWT);
  printf("Avg TurnAround Time -> %d\n", avgTAT);

}

int main(void) {
  int n;

  printf("Enter the number of procesess : ");
  scanf("%d", &n);


  printf("Please specify the burst time of each process\n");
  for(int i=0; i<n; i++){
    process[i].indx = i + 1;

    printf("Process %d : ", i+1);
    scanf("%d", &process[i].burstTime);
  }

  sjf(n);

  return 0;
}
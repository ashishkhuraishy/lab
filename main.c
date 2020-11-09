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


void findWaitingTime(int n){
  process[0].waitingTime = 0;
  process[0].turnAroundTime =  process[0].waitingTime + process[0].burstTime;

  for(int i=1; i<n; i++){
    process[0].turnAroundTime =  process[0].waitingTime + process[0].burstTime;
    process[0].turnAroundTime =  process[0].waitingTime + process[0].burstTime;
  }

}

void findTimeTake(int n){
  int avgWT = 0, avgTAT = 0; 

  sortProcess(n);

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


  return 0;
}
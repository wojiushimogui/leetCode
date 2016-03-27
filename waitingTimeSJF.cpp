#include<stdio.h>
#include<stdlib.h>

 // INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
float waitingTimeSJF(int *requestTimes, int *durations, int n)
{
    // WRITE YOUR CODE HERE
    //ִ��ʱ�̼�ȥ����ʱ�̾��ǵȴ�ʱ����
    if(requestTimes==NULL||durations==NULL||n<1){
        return -1.0;
    }
    
    int *visited=(int *)malloc(n*sizeof(int ));
    if(visited==NULL){
        //exit(EXIT_FAILURE);
        return -1.0;
    }
    //memset(visited,n,sizeof(int),0);
    for(int i=0;i<n;i++){//��ʼ��Ϊ��
        visited[i]=0;
    }
    visited[0]=1;//����һ��������
    int totalTime=durations[0];
    int res=0;
    for(int i=1;i<n;i++){
        //��ʣ�µ������ҳ���С��
        //int minTimeTask=INT_MAX;
        int minTimeTask=10000;
        int k=-1;
        for(int j=1;j<n;j++){
            if(visited[j]!=1&&durations[j]<minTimeTask){
                minTimeTask=durations[j];
                k=j;
            }
        }
        if(k!=-1&&minTimeTask!=10000){
            
            int time=totalTime-requestTimes[k];
            if(time<0){//��ͽ�ǰ��ȴ������������
                int kk=-1;
                int minValue=10000;
                for(int nn=1;nn<k;nn++){
                    if(visited[nn]!=1&&durations[nn]<minValue){
                    	minValue=durations[nn];
                    	kk=nn;
                	}               
            	}
            	res+=(totalTime-requestTimes[kk]);
                totalTime+=minValue;
                visited[kk]=1;
            }
            else{
                res+=(totalTime-requestTimes[k]);
                totalTime+=minTimeTask;
                visited[k]=1;
            }
            
        }
        else{
            return -1.0;
        }
       
    }
    return (1.0*res)/n;
}
// FUNCTION SIGNATURE ENDS

int main(void){
	int arr[4]={0,1,3,9};
	int time[4]={2,1,7,5};
	int n=4;
	float res=waitingTimeSJF(arr, time, n);
	printf("shijian:%f\n",res);
	
}

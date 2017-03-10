#include <iostream>
#include <vector>
#include <string.h>
using std::cout;
using std::endl;
using std::vector;
#define N 15

void AdjustDown(int arr[],int k,int len)
{
	arr[0]=arr[k];
	for(int i=2*k;i<=len;i*=2)
	{
		if(i<len&&arr[i]<arr[i+1])
			i++;
		if(arr[0]>=arr[i])
			break;
		else{
			arr[k]=arr[i];
			k=i;
		}
	}
	arr[k]=arr[0];
}

void BuildMaxHeap(int arr[],int len)
{
	for(int idx=len/2;idx>0;idx--)
		AdjustDown(arr,idx,len);
}

void HeapSort(int arr[],int len)
{
	BuildMaxHeap(arr,len);
	for(int i=len;i>1;i--)
	{
		arr[i]=arr[i]+arr[1];
		arr[1]=arr[i]-arr[1];
		arr[i]=arr[i]-arr[1];
		AdjustDown(arr,1,i-1);
	}
}

void AdjustUp(int arr[],int k)
{
	arr[0]=arr[k];
	int i=k/2;
	while(i>0&&arr[i]<arr[0]){
		arr[k]=arr[i];
		k=i;
		i=k/2;
	}
	arr[k]=arr[0];
}

void insertsort(int arr[],int len)
{
	for(int i=2;i<len;i++)
		if(arr[i]<arr[i-1])
		{
			int temp=arr[i];
			int j;
			for(j=i-1;temp<arr[j];--j)
				arr[j+1]=arr[j];
			arr[j+1]=temp;
		}
}


int main(void)
{
	int arr[N]={234,456,675,4234,231,24,234,34554,657,457,658,76,8,34,534};
	for(int idx=0;idx!=N;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;

	HeapSort(arr,N);
	for(int idx=0;idx!=N;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
	
	insertsort(arr,N);
	for(int idx=0;idx!=N;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;

#if 0
	AdjustUp(arr,N);
	for(int idx=0;idx!=N;++idx)
		cout<<arr[idx]<<" ";
	cout<<endl;
#endif
	return 0;
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

int KnapSack(int weight[],int value[],int capacity,int currentWeight,int index,int size)
{
    if(currentWeight>=capacity || index>=size)
    {
        return 0;
    }
  
    
    int include = value[index] + KnapSack(weight,value,capacity,currentWeight + weight[index],index+1,size);
    int exclude = 0 + KnapSack(weight,value,capacity,currentWeight,index+1,size);


    int ans = max(include,exclude);

    return ans;
}
int main()
{
  int weight[] = {10, 20, 30};
  int value[] = {60, 100, 120};
  int capacity = 50;

  int currentWeight = 0;
  int currentValue = 0;
  int index = 0;
  int size = 3;

  int ans = KnapSack(weight,value,capacity,currentWeight,index,size);

  cout<<"Answer is : "<<ans;



}
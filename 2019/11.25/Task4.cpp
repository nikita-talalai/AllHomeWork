//Напишите эффективную процедуру, выписывающую из массива длины n все элементы, у которых произведение ненулевых цифр больше k.
//В комментариях напишите, почему перебор - эффективный.

#include <iostream>
using namespace std;

void accept(int* arr, int n, int k){
  int element, remain;
  int multi = 1;
  for(int i = 0;i < n;i++){
    element = arr[i];
    while(element!=0){
      remain = element%10;
      element /= 10;
      if(remain != 0){
      multi *= remain;
     }   
    }
    if(multi > k){
      cout << arr[i] << " ";
    }
    multi = 1;
  }
}

int main()
{
   int n, k;
   cin >> n >> k;
   int* arr = new int[n];
   for(int i =0 ;i < n;i++){
     cin >> arr[i];
   }
   accept(arr, n, k);
   return 0;
  
}

#include <iostream>
using namespace std;


int min(int a, int b, int c)
{
    if(a < b)
    {
        return (a < c ? a : c);
    }
    else
    {
        return (a < b ? a : b);
    }
}

int distanceOfHamming(string a, string b)
{
    if(a.length()!=b.length())
    {
        cout << "Strings have different length" << endl;
        return -1;
    }
    
    int count =0;
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i]!=b[i])
        {
            count++;
        }
    }
    return count;
}

int distanceOfLevenshtein(string a, string b, int InsertCost = 0, int DeleteCost = 0, int ReplaceCost = 0)
{
    int **arr;
    arr = new int*[a.length()];
    for (int i = 0; i < a.length(); i++) 
    { 
        arr[i] = new int[b.length()];
    }
    arr[0][0] = 0;
    for(int j = 1; j < b.length(); j++)
    {
        arr[0][j] = arr[0][j-1] + InsertCost;
    }  
    for(int i = 1; i < a.length(); i++)
    {
        arr[i][0] = arr[i-1][0] + DeleteCost;

        for(int j = 1; j < b.length(); j++)
        {
            if(a[i]!=b[j])
            {
                arr[i][j] = min(arr[i-1][j] + DeleteCost, arr[i][j-1] + InsertCost, arr[i-1][j-1] + ReplaceCost);
            }
            else
            {
                arr[i][j] = arr[i-1][j-1];
            }
        }
    }
  return arr[a.length()-1][b.length()-1];
}


int main()
{
   string a, b;
   cout << "The first string: " << endl;
   cin >> a;
   
   cout << "The second string: " << endl;
   cin >> b;
   
   cout << "Distence of Hamming: " << distanceOfHamming(a, b) << endl;
   cout << "Distence of Levenshtein: " << distanceOfLevenshtein(a, b) << endl;
   //cout << "Weight distence of Levenshtein: " << weightDistanceOfLevenshtein(a, b);
   return 0;
}

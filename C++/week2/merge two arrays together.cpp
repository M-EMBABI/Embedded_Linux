#include <iostream>  
  
void Merge(int a[], int b[], int res[], int n, int m) 
  
{  
    int i = 0, l = 0, k = 0;  
    while (i < n && l < m) 
    {  
        if (a[i] <= b[l])
         { 
            res[k] = a[i];  
            i += 1;  
            k += 1;  
         } 
        else 
        {  
            res[k] = b[l];
            l += 1;  
            k += 1;  
        }  
    }  
    while (i < n) 
    { 
        res[k] = a[i];  
        i += 1;  
        k += 1;  
    }  
    while (l < m) 
    { 
        res[k] = b[l];  
        l += 1;  
        k += 1;  
    }  
}  
  
int main()  
{  
    int a[] = { 15, 55, 262, 156 };  
    int b[] = { 41,  12, 100, 95 };  
    int n = sizeof(a) / sizeof(a[0]);  
    int m = sizeof(b) / sizeof(b[0]); 
  
    int res[n + m]; 
    Merge(a, b, res, n, m);  
  
      
    for (int i = 0; i < n + m; i++)
    {

     
     std::    cout << " " << res[i];
    }  
     std:: cout << "\n";  
  
    return 0;  
}

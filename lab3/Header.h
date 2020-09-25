#pragma once

#include <iostream>
using namespace std;
class Massive
{
private:
    int n, n2;
    int* arr;
  /*  int* arr2;
    int* merge;*/
public:
    Massive()
    {
        n = 1; arr = new int[n];
    }
    Massive(int n_size)
    {
        n = n_size; arr = new int[n];
       /* n2 = n2_size; arr = new int[n2];*/
        
    }

    Massive(const Massive& other) //copy
    {
        this->n = other.n;
        this->arr = new int[other.n];
        for (int i = 0; i < other.n; i++)
        {

            this->arr[i] = other.arr[i];

        }
    }
    ~Massive()
    {
        delete[]arr;
    }
    void setSize(int size) { n = size; }
    void show()
    {
        for (int i = 0; i < n; i++)
        {

            std::cout << arr[i] << " ";
        }
    }
    void setMassive( )
    {
        int a;
       
        for (int x = 0; x < this->n; x++)
        {
            std::cin >> a;
            this->arr[x] = a;

        }
    }
  
    void ShellSort()
    {
        int step, i, j, tmp;
        for (step = n / 2; step > 0; step /= 2)
            for (i = step; i < n; i++)
                for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
                {
                    tmp = arr[j];
                    arr[j] = arr[j + step];
                    arr[j + step] = tmp;
                }
    }
        /*Massive operator+ (const Massive&);
       const Massive& operator= (const Massive&);*/
    
    Massive& operator= (const Massive& right) // оператор присваивания
    {
       
        if (&right != this) 
        {
            
            for (int ix = 0; ix < n; ix++) this->arr[ix] = right.arr[n-ix-1]; 
            return *this;
        }
    }
    
     Massive operator+ (const Massive& right)
     {
         int j=0;
        int size = this->n + right.n;
        Massive array(size);       
        
        for (int i = 0; i < this->n; i++) array.arr[j++] = this->arr[i];
        for (int i = 0; i < right.n; i++) array.arr[j++] = right.arr[i];
        return array;
    }
  
       friend Massive& operator--(Massive& a);
};





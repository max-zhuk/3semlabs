#ifndef STACK_H
#define STACK_H
#include <cassert> // для assert
#include <iostream>
#include <iomanip> //setw
using namespace std;
template <typename T>

void check(T& a) {
    bool fa = true;
    do
    {
        std::cin >> a;
        if (std::cin.fail())
            std::cout << "error" << std::endl;
        else
            fa = false;
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    } while (fa);
}

template <typename T>
class Stack
{
private:
    T* stackPtr;                    
    int size;                   
    int top;                         
public:
    Stack(int = 5);                 
    Stack(const Stack<T>&);         
    ~Stack();                        
    inline const T& setSize(int) const;
    inline void push(const T&);    
    inline T pop();                   
    inline void printStack();        
    inline const T& Peek(int) const; 
    inline int getStackSize() const; 
    inline T* getPtr() const;        
    inline int getTop() const; 
    void print()
    {
        for (int i = 0; i <top ; i++)
        {
            cout<< "|"<<stackPtr[i][0]<<endl;

        }
        cout << endl;
    }
    
};






int main()
{
    Stack<int> st;
    int rit;
    int s = st.getStackSize();
    for (int i = 0; i < s; i++)
    {
   
    check(rit);
    st.push(rit);
    }
    st.printStack();

   int a= st.getStackSize();
   cout << "stack size: "<<a<<endl;
   a = st.Peek(2);
   cout << "Peek 2: " << a << endl;
   a = st.getTop();
   cout << "number of the top element: " << a<<endl;
  
    st.pop();
    cout << "Pop top element:  " << endl;
    st.printStack();
    a = st.getTop();
    cout << "number of the top element: " << a << endl;
    for (int i = 0; i < a; i++)
    {
        st.pop();
    }
    cout << "pop stack"<<endl;
    a = st.getTop();
    cout << "number of the top element: " << a << endl;
    st.printStack();
    Stack<char*> sc;
    char* ch=new char[s];
    for (int i = 0; i < s; i++)
    {
        cin >>ch[i];
      
        sc.push(&ch[i]);
    
    }
    sc.print();
    sc.pop();
    cout << "After pop:  " << endl;
    sc.print();
}

template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize)
{
    stackPtr = new T[size]; 
    top = 0; 
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T>& otherStack) :
    size(otherStack.getStackSize())
{
    stackPtr = new T[size];
    top = otherStack.getTop();

    for (int ix = 0; ix < top; ix++)
        stackPtr[ix] = otherStack.getPtr()[ix];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr;
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T& value)
{
    assert(top < size);

    stackPtr[top++] = value;
}

// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{

    assert(top > 0);

    stackPtr[--top];
    return 0;
}

// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T& Stack<T>::Peek(int nom) const
{
    assert(nom <= top);

    return stackPtr[top - nom];
}

// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
    for (int ix = top - 1; ix >= 0; ix--)
        cout << "|" << setw(4) << stackPtr[ix] << endl;
}
   

// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
    return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T* Stack<T>::getPtr() const
{
    return stackPtr;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getTop() const
{
    return top;
}
#endif // STACK_H
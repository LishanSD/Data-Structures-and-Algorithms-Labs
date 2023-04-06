#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int stac[100], n=100, top=-1;

void Push(int val) {
   if(top>=n-1)
   cout<<"Stack Overflow"<<endl;
   else {
      top++;
      stac[top]=val;
   }
}
void Pop() {
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      top--;
   }
}
void Display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stac[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
int main() {
    vector<int> values(10000);
    auto f = []() -> int { return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    auto start = high_resolution_clock::now();

    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();  
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

   return 0;
}

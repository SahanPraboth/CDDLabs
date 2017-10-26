// Author: Sahan Ekanayake
// Purpose: A reusable barrier class.

#include "Semaphore.h"
#include <iostream>
#include <thread>

using namespace std;
int count = 0, barrierLimit = 3, threadCount = 0 ;

void taskOne(shared_ptr<Semaphore> Mutex,shared_ptr<Semaphore> BarrierA,shared_ptr<Semaphore> BarrierB)
  {
    threadCount++;
    cout << "Thread " << threadCount << " before Barrier" << endl;
    Mutex->Wait();
    count++;
    if(count == barrierLimit)
      {
        threadCount = 0;
        BarrierB->Wait();
        BarrierA->Signal();
      }
    Mutex->Signal();
    BarrierA->Wait();
    BarrierA->Signal();
    threadCount++;

    cout << "Thread " << threadCount << " after Barrier" << endl;

    Mutex->Wait();
    count --;
    if(count == 0)
      {
        BarrierA->Wait();
        BarrierB->Signal();
      }
    Mutex->Signal();
    BarrierB->Wait();
    BarrierB->Signal();
  }

int main(void)
  {
    thread threadOne, threadTwo, threadThree;
    shared_ptr<Semaphore> Mutex(new Semaphore(1));
    shared_ptr<Semaphore> BarrierA(new Semaphore(0));
    shared_ptr<Semaphore> BarrierB(new Semaphore(1));

    threadOne=thread(taskOne,Mutex,BarrierA,BarrierB);
    threadTwo=thread(taskOne,Mutex,BarrierA,BarrierB);
    threadThree=thread(taskOne,Mutex,BarrierA,BarrierB);

    threadOne.join();
    threadTwo.join();
    threadThree.join();

    return 0;
}

#include "Semaphore.h"
#include <iostream>
#include <thread>

int num = 0;

void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "Count " << num <<std::endl;
  num++;
  theSemaphore->Signal();
}

int main(void){

  std::thread threadOne, threadTwo, threadThree;
  std::shared_ptr<Semaphore> sem( new Semaphore(1));
  /**< Launch the threads  */
  threadOne=std::thread(taskOne,sem);
  threadTwo=std::thread(taskOne,sem);
  threadThree=std::thread(taskOne,sem);
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  return 0;
}

#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore,std::shared_ptr<Semaphore> theSemaphore2){
  std::cout <<"I ";
  std::cout << "must "<<std::endl;
  theSemaphore2->Signal();
  theSemaphore->Wait();
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore2->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore, std::shared_ptr<Semaphore> theSemaphore2){
  theSemaphore2->Wait();
  std::cout <<"This ";
  std::cout << "will "<<std::endl;
  theSemaphore->Signal();
  theSemaphore2->Wait();
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sema( new Semaphore);
  std::shared_ptr<Semaphore> semb( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sema,semb);
  threadTwo=std::thread(taskOne,sema,semb);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}

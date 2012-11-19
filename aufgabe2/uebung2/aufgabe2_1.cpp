#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp> 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include "semaphore_shared_data.hpp"

using namespace boost::interprocess;

int main(){ 
	srand(time(NULL));

  //use old shared memory if exists else create a new one
	shared_memory_object shm(open_or_create, "shared_memory", read_write);

  //set the size of the memory object
  shm.truncate(sizeof(shared_memory_buffer));
  
  //map the whole shared memory in this process
  mapped_region region(shm,read_write);
  
  //get the region address
  void * addr = region.get_address();
  
  //create a shared memory buffer in memory
  shared_memory_buffer *data = new (addr) shared_memory_buffer;


  while(true){
    //wait until the written number gets executed
    data->writer.wait();

    //print the square root of the original value
    std::cout << "Square Root: " << data->value << "\n";

    //create the original value
    data->value = rand() % 100 + 1;

    sleep(1);
    //reader can execute written number
    data->reader.post();
  }

  return 0;
}
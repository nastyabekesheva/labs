//
//  main.cpp
//  lab_4
//
//  Created by Nastya Bekesheva on 28.03.2023.
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <queue>
#include "Queue.cpp"
#include "CircularQueue.cpp"

void print_queue(std::queue<int> q)
{
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    
    Queue<int> q;
    q.deQueue();
    for(int i = 1; i < 6; i++)
    {
        q.enQueue(i);
    }
    std::cout << q << std::endl;
    q.enQueue(6);
    std::cout << q << std::endl;
    q.deQueue();
    q.enQueue(7);
    q.enQueue(8);
    std::cout << q << std::endl;
    std::cout << "DeQueue: ";
    int sq = q.size();
    for(int i = 0; i < sq; i++)
    {
        std::cout << q.deQueue() << ' ';
    }
    CircularQueue<int> cq(5);
    cq.deQueue();
    for(int i = 1; i < 6; i++)
    {
        cq.enQueue(i);
    }
    std::cout << cq << std::endl;
    cq.enQueue(6);
    std::cout << cq << std::endl;
    cq.deQueue();
    cq.enQueue(7);
    cq.enQueue(8);
    std::cout << cq << std::endl;
    std::cout << "DeQueue: ";
    int scq = cq.size();
    for(int i = 0; i < scq; i++)
    {
        std::cout << cq.deQueue() << ' ';
    }
    std::cout << std::endl;
    
    return 0;
}

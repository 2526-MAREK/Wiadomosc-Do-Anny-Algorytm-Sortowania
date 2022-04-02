#ifndef PRIORITY_QUEUE_HH
#define PRIORITY_QUEUE_HH

#include "element_of_priority_queue.hh"

const int MAXINT = -2147483647;

class priority_queue
{
  private:
    element_of_priority_queue * head;
    element_of_priority_queue * tail;
  public:
    priority_queue( );      
    ~priority_queue( );     
    bool empty ( void );
    std::string front ( void );
    int frontprio ( void );
    void push ( int prio, std::string cut_string );
    void pop ( void );
};

#endif
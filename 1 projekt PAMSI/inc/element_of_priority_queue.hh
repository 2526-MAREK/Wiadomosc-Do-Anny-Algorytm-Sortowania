#ifndef ELEMENT_OF_PRIORITY_QUEUE_HH
#define ELEMENT_OF_PRIORITY_QUEUE_HH

#include "package.hh"

class element_of_priority_queue
{
private:
    element_of_priority_queue *next;
    package pack;
public:
    element_of_priority_queue();
    element_of_priority_queue(element_of_priority_queue *next_temp,int prio_temp,std::string& cut_string_temp);
    int access_to_prio() const;
    const std::string& access_to_cut_string() const;
    element_of_priority_queue* &access_to_next() ;
    ~element_of_priority_queue();
};

#endif
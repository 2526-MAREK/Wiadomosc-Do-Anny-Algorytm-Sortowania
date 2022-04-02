#include "element_of_priority_queue.hh"

element_of_priority_queue::element_of_priority_queue()
{
    next = NULL;
    pack.prio = 0;
    pack.cut_string = "empty_element_of_priority_queue";
}

element_of_priority_queue::element_of_priority_queue(element_of_priority_queue *next_temp,int prio_temp, std::string& cut_string_temp)
{
    next = next_temp;
    pack.prio = prio_temp;
    pack.cut_string = cut_string_temp;        
}

int element_of_priority_queue::access_to_prio() const
{
    return pack.prio;
}

const std::string& element_of_priority_queue::access_to_cut_string() const
{
    return pack.cut_string;
}

element_of_priority_queue* &element_of_priority_queue::access_to_next() 
{
    return next;
}

element_of_priority_queue::~element_of_priority_queue()
{
}
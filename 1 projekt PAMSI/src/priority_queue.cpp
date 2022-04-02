#include "priority_queue.hh"

priority_queue::priority_queue( )
{
  head = tail = NULL;
}

priority_queue::~priority_queue( )
{
  while( head ) pop( );
}

bool priority_queue::empty ( void )
{
  return !head;
}

std::string priority_queue::front ( void )
{
  if( head ) return head->access_to_cut_string();
  else     return "empty_string";
}

int priority_queue::frontprio ( void ){
  if( !head ) return -MAXINT;
  else      return head->access_to_prio();
}

void priority_queue::push ( int prio, std::string cut_string )
{
  element_of_priority_queue * p_element_lower_priority;

  //Dynamicznie tworzymy nowy element listy 
  element_of_priority_queue * p_new_element = new element_of_priority_queue(NULL,
                                                                            prio,
                                                                            cut_string); 

  //Kolejka jest pusta ? Jesli tak to dodajamy nowy element,
  if( !head ) head = tail = p_new_element; 

  // jeśli nie to sprawdzamy czy element listy ma najwyższy priorytet
  else if( head->access_to_prio() < prio ) 
  {
    //element ma najwyzszy priorytet, więc dodajemy go na 
    //początek listy zgodnie z założeniami 
    p_new_element->access_to_next() = head; 
    head                            = p_new_element;
  }

  // jeśli kolejka nie jest pusta i wstawiany nowy element nie ma 
  //najwyższego priorytetu to wykonujemy poniższy algorytm 
  else 
  {
    //rozpoczynamy od początku listy 
    p_element_lower_priority                    = head; 

     //szukamy na liście pierwszego elementu o niższym priorytecie
     //sprawdzamy czy nie znajdujemy się na końcu listy && następnym priorytet 
     //elementu listy >= priorytet wstawianego elementu 
    while((p_element_lower_priority->access_to_next()) &&
    (p_element_lower_priority->access_to_next()->access_to_prio() >= prio )) 
      p_element_lower_priority                  = p_element_lower_priority->access_to_next();
    //nowy element wstawiamy przed element o niższym priorytecie       
    p_new_element->access_to_next()             = p_element_lower_priority->access_to_next();
    p_element_lower_priority->access_to_next()  = p_new_element;

    // jeśli element jest na końcu to uaktalniamy tail ( koniec kolejki priorytetowej)
    if(!p_new_element->access_to_next()) tail   = p_new_element; 
  }
}

void priority_queue::pop ( void )
{
  if( head )
  {
    element_of_priority_queue * p = head;
    head = head->access_to_next();
    if( !head ) tail = NULL;
    delete p;
  }
}
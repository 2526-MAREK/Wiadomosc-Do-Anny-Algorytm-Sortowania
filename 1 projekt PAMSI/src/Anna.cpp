#include "Anna.hh"

Anna::Anna() : message()
{
}

Anna::Anna(std::string& message_temp)
{
    message = message_temp;
}

void Anna::display_the_message()
{
    std::cout<<"Wiadomosc jaka odczytala Ania: "<<std::endl;
    std::cout<<"-------------------------------"<<std::endl;
    std::cout<<message<<std::endl;
    std::cout<<"-------------------------------"<<std::endl;
}
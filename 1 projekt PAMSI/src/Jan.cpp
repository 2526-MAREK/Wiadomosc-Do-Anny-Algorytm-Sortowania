#include "Jan.hh"

Jan::Jan() :message()
{
}

Jan::Jan(std::string& message_temp)
{
    message = message_temp;
}

void Jan::Jan_is_writing_a_message_to_Anna()
{
    std::cout<<"Janie wpisz wiadmosc do anny: ";
    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin, message);
}

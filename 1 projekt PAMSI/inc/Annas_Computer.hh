#ifndef ANNAS_COMPUTER_HH
#define ANNAS_COMPUTER_HH

#include "Message.hh"

class Annas_Computer{
private:
    priority_queue composed_message;
public:
Annas_Computer();
Annas_Computer(priority_queue& composed_message_temp);
void add_and_repair_message(Message& message_from_jan, std::string& fixed_message);
//void display_message();
};
#endif
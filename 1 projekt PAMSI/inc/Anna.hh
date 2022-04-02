#ifndef ANNA_HH
#define ANNA_HH
#include <string>
#include<iostream>

class Anna{
private:
    std::string message;
public:
Anna();
Anna(std::string& message_temp);
inline void initialize(std::string& message_temp){message = message_temp;}
void display_the_message();
};
#endif
#ifndef JAN_HH
#define JAN_HH

#include <iostream>
#include <string>

class Jan{
private:
    std::string message;
public:
Jan();
Jan(std::string& message_temp);
void Jan_is_writing_a_message_to_Anna();
inline std::string& access_to_message_from_Jan(){return message;}
};
#endif
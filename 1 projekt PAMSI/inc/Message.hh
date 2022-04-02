#ifndef MESSAGE_HH
#define MESSAGE_HH

#include  "priority_queue.hh"
#include <algorithm>
#include <random>

class Message {
private:
    std::string message;
    std::string message_fixed;
    unsigned int number_of_package;
    package* jumbled_message;
public:
    Message();
    Message(unsigned int number_of_package_temp, std::string message_temp);
    void initialize(unsigned int number_of_package_temp, std::string message_temp);
    bool split_the_message_into_n_packets();
    void shuffle_the_message();
    void display_the_message_in_packets();
    void display_the_message_fixed();
    void display_the_message();
    inline int acces_to_number_of_package(){return number_of_package;}
    inline package*& acces_to_jumbled_message(){return jumbled_message;}
    ~Message();
};

#endif
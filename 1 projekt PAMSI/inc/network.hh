#ifndef NETWORK_HH
#define NETWORK_HH
#include"Jan.hh"
#include"Anna.hh"
#include "Annas_Computer.hh"
#include <chrono>
#include <ctime>
#include <fstream>

//typedef void ( * algorithm_t )(void);

class Network
{
private:
    std::string text_from_file;
    Jan jan;
    Message message;
    Annas_Computer annas_comp;
    Anna anna;
public:
Network();
Network(Jan& jan_temp,Message& message_temp,Annas_Computer& annas_comp, Anna& anna);
void jan_send_message_to_anna();
unsigned int ask_how_many_packets_to_divide_the_message_into();
void display_message_in_packets();
void problems_with_the_message();
void display_repaired_message();
void display_fixed_message();
void repair_message();
void testing_algorithm();//algorithm_t p_algorithm
void read_text_from_file(const char* name_file);
unsigned int display_menu();
void Janek_send_message_function_calls();
void testing_algoritm_function_calls();
void menu(Network& net_testing);
};
#endif
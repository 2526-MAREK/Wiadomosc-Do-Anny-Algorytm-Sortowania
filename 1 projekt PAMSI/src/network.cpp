#include "network.hh"

Network::Network() : jan(), anna(), annas_comp(), message()
{

}

Network::Network(Jan& jan_temp,
Message& message_temp,
Annas_Computer& annas_comp_temp, 
Anna& anna_temp) : jan(jan_temp), message(message_temp), 
annas_comp(annas_comp_temp), anna(anna_temp)
{
}

void Network::jan_send_message_to_anna()
{
    jan.Jan_is_writing_a_message_to_Anna();
    unsigned int number_of_packets_temp = ask_how_many_packets_to_divide_the_message_into();
    Message jumb_mess_temp(number_of_packets_temp,
    jan.access_to_message_from_Jan());
    message = jumb_mess_temp;
}

unsigned int Network::ask_how_many_packets_to_divide_the_message_into()
{
    unsigned int number_of_packets_temp;
    std::cout<<"Na ile pakietów podzielić wiadomość?: "<<std::endl;
    std::cin>>number_of_packets_temp;

    return number_of_packets_temp;
}

void Network::problems_with_the_message()
{
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"Dzielenie wiadmosci na pakiety..."<<std::endl;
    message.split_the_message_into_n_packets();
    std::cout<<"Podzielono wiadomosc na pakiety!!!"<<std::endl;
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"Cos nie spodziewanego sie dzieje z wiadmoscia, została ona pomieszana...."<<std::endl;
    message.shuffle_the_message();
    std::cout<<"----------------------------------"<<std::endl;
}

void Network::repair_message()
{
    std::cout<<"Trwa naprawianie wiadomosci..."<<std::endl;
    std::string fixed_message;
    annas_comp.add_and_repair_message(message, fixed_message);
    anna.initialize(fixed_message);
}

void Network::display_fixed_message()
{
    message.display_the_message_fixed();
}

void Network::display_repaired_message()
{
    anna.display_the_message();
}
void Network::read_text_from_file(const char* name_file)
{
}

void Network::testing_algorithm()
{
    std::string text_temp = jan.access_to_message_from_Jan();
    // 4000*500(char) = 2000000(char) if we dzielimy 2000000 na 1000000 packets to mamy po dwa znaki w paczce 
    for(unsigned int i =0;i<4000;++i)
    {
        jan.access_to_message_from_Jan() += text_temp;
    }
    std::cout<<"Algorytm kolejki priorytetowej jest testowany pod katem zloznosci obliczeniowej, efekty testu prezentuja sie w pliku zlozonosc_funkcji_repair_message.csv w folderze obj"<<std::endl;
    std::cout<<"Badz cierpliwy! Moze to potrwac dluzsza chwile ! "<<std::endl;

    std::fstream plik( "zlozonosc_funkcji_repair_message.csv", std::ios::out );
    for(unsigned int number_of_package_temp =1000;number_of_package_temp<1000000; number_of_package_temp+=1000)
    {
            Message message_temp(number_of_package_temp, jan.access_to_message_from_Jan());
            message = message_temp;
            problems_with_the_message();
            auto start = std::chrono::high_resolution_clock::now();
            repair_message(); //algorithm 
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);    
             if( plik.good() )
             {
            plik << number_of_package_temp << ","<<duration.count()/1000.0<<std::endl;
            plik.flush();
     
            
             }
           /*std::cout <<"\t"<< duration.count() << " milisekund,\n"
            <<"\t"<< duration.count()/1000.0 << " sekund,\n"
            <<"\t"<< (duration.count()/1000.0)/60.0 << " minut.\n\n";*/
    }
    plik.close();
}

unsigned int Network::display_menu()
{
std::cout<<"Witaj podaj prosze, ktora opcje chcesz wybrac: "<<std::endl;
std::cout<<"1 - Janek wysyla wiadomosc do ani ze standardowego wejscia"<<std::endl;
std::cout<<"2 - Testowanie zlozonosci obliczeniowej algorytmu kolejki priorytetowej"<<std::endl;

unsigned int choice;
std::cin>>choice;

return choice;
}
void Network::menu(Network& net_testing)
{
    unsigned int choice = display_menu();    
    switch (choice)
    {
        case 1:{ this->Janek_send_message_function_calls(); break;}
        case 2:{ net_testing.testing_algoritm_function_calls(); break;}    
        default:{
            std::cout<<"------------------------------------------"<<std::endl;
            std::cout<<"Niestety program nie posiada takiej opcji"<<std::endl;
            std::cout<<"------------------------------------------"<<std::endl;
            break;
        }
    }
}
void Network::Janek_send_message_function_calls()
{
    this->jan_send_message_to_anna();
    this->problems_with_the_message();
    this->display_fixed_message();
    this->repair_message();
    this->display_repaired_message();
}

void Network::testing_algoritm_function_calls()
{
    this->testing_algorithm();
}
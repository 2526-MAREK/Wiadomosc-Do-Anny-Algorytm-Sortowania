#include "Message.hh"

Message::Message() : message()
{
    number_of_package = 0;
    jumbled_message = NULL;
}

 Message::Message(unsigned int number_of_package_temp, std::string message_temp) 
 {
   message = message_temp;
    number_of_package = number_of_package_temp;
    jumbled_message = new package[number_of_package_temp+1];
 }

bool Message::split_the_message_into_n_packets()
{
    unsigned int package_length;
    unsigned int  package_length_temp;
    /*int number_of_package = 12;
    package jumbled_message[number_of_package];*/

  int size_of_message = message.size();

  //std::cout<<size_of_message<<std::endl;

    if(number_of_package !=0 )
      {
        package_length = int(size_of_message/number_of_package);  
        package_length_temp = package_length;
      }
      else
      {
        package_length = 0;
      }
    if(package_length>=1 && package_length<= size_of_message){
      unsigned int i = 0;
      unsigned int i_2 =0;
      while(i<number_of_package)
      {
        while(i_2<package_length)
        {
            jumbled_message[i].cut_string.push_back(message[i_2]);
            jumbled_message[i].prio = i+1;
            ++i_2;
            //std::cout<<"i_2: "<<i_2<<std::endl;
        }
        package_length += package_length_temp;
        //std::cout<<"package_length: "<<package_length<<std::endl;
        ++i;
            //std::cout<<"i: "<<i<<std::endl;            
      }
      
      //if(package_length_temp*number_of_package<size_of_message){
          //std::cout<<"ELO"<<std::endl;
          for(int i_3 = i_2;i_3<size_of_message;++i_3){
        jumbled_message[i-1].cut_string.push_back(message[i_3]);
        jumbled_message[i-1].prio = i;
        //}
      }
    }
    else
    {
        std::cout<<"Nie jest mozliwe utworzenie tak małych paczek z tego zdania"<<std::endl;

        return false;
    }
    return true;
}
void Message::shuffle_the_message()
{
  std::random_device rd;
  std::default_random_engine generation(rd());
  std::shuffle(jumbled_message, jumbled_message+number_of_package, generation);
  for(int i =0;i<number_of_package;++i)
      {
            message_fixed += jumbled_message[i].cut_string;
      }
}

void Message::display_the_message_in_packets()
{
  for(int g = 0;g<number_of_package;++g)
      {
          std::cout<<jumbled_message[g].cut_string<<std::endl;
          std::cout<<jumbled_message[g].prio<<std::endl;
      }
}
void Message::display_the_message_fixed()
{
  std::cout<<"Wyswietlono wiadomosc z ktora sa problemy"<<std::endl;
  std::cout<<"-------------------------------"<<std::endl;
  std::cout<<message_fixed<<std::endl;
  std::cout<<"-------------------------------"<<std::endl;
}

void Message::display_the_message()
{
  std::cout<<"Wyswietlono wiadomosc przed problemami"<<std::endl;
  std::cout<<"-------------------------------"<<std::endl;
  std::cout<<message<<std::endl;
  std::cout<<"-------------------------------"<<std::endl;  
}
void Message::initialize(unsigned int number_of_package_temp, std::string message_temp)
{
  message = message_temp;
  number_of_package = number_of_package_temp;

}
 Message::~Message()
 {
     delete[] jumbled_message;
 }
#include "Annas_Computer.hh"
Annas_Computer::Annas_Computer() : composed_message()
{

}

Annas_Computer::Annas_Computer(priority_queue& composed_message_temp)
{
    //message_from_jan = message_from_jan_temp;
    composed_message = composed_message_temp;
}

void Annas_Computer::add_and_repair_message(Message& message, std::string& fixed_message)
{
    for(unsigned int i =0; i<message.acces_to_number_of_package();++i)
    {
        composed_message.push(message.acces_to_jumbled_message()[i].prio, message.acces_to_jumbled_message()[i].cut_string);
    }

    for(unsigned int i = message.acces_to_number_of_package() -1; i > 0;--i){
        message.acces_to_jumbled_message()[i].cut_string = composed_message.front( ) ;
        message.acces_to_jumbled_message()[i].prio = composed_message.frontprio( ) ;
            composed_message.pop( );
        }
        message.acces_to_jumbled_message()[0].cut_string = composed_message.front( ) ;
        message.acces_to_jumbled_message()[0].prio = composed_message.frontprio( ) ;

         for(unsigned int i =0;i<message.acces_to_number_of_package();++i)
      {
            fixed_message += message.acces_to_jumbled_message()[i].cut_string;
      }
}

/*void Annas_Computer::display_message()
{
    for(int g = 0;g<message_from_jan.acces_to_number_of_package();++g)
      {
          std::cout<<message_from_jan.acces_to_jumbled_message()[g].cut_string<<std::endl;
          std::cout<<message_from_jan.acces_to_jumbled_message()[g].prio<<std::endl;
      }
}*/
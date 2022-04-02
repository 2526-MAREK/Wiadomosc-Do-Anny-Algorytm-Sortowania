#include "network.hh"

#include<fstream>

int main(void)
{
  //uzytkownik wpisuje tresc wiadomosci 
  std::string mess_from_jan;
  Jan jan(mess_from_jan); 

  priority_queue prio_que;
  Annas_Computer Anna_comp(prio_que);

  Message jumb_mess;
  Anna anna;
  Network net(jan,jumb_mess, Anna_comp, anna);
  
  //testy kolejki priorytetowej 
  std::string mess_from_jan_test;
  std::string mess_from_jan_test_temp;
  std::fstream file( "tekst_500_znakow_do_testow_algorytmu.txt", std::ios::in ); //zakładamy, że plik istnieje
  if(!file.good())
  { 
    std::cout<<"Nie mozna otworzyc pliku"<<std::endl;
  }
  while (!file.eof())
  {
    getline( file, mess_from_jan_test_temp ); //wczytanie CAŁEGO jednego wiersza danych
    mess_from_jan_test += mess_from_jan_test_temp;
  }

  Jan jan_test(mess_from_jan_test); 

  priority_queue prio_que_test;
  Annas_Computer Anna_comp_test(prio_que_test);

  Message jumb_mess_test;
  Anna anna_test;
  Network net_test(jan_test,jumb_mess_test, Anna_comp_test, anna_test);
  net.menu(net_test);
  //number of packet define in program number of elements
  return 0;
}
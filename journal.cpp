#include "journal.h"

void journal::dod_do_dziennik(std::string wpisik)
{
	int licznik=this->wpis_w_dzienniku;
	this->spis[licznik]=wpisik;
	aktual_pozycje_w_dzienniku();
}

void journal::przegladaj_dziennik(int strona=0)
{
	int wpis_max=5; //ilosc wpisow na strone
	int max_strony=this->wpis_w_dzienniku/wpis_max; //obliczenie max ilosci stron na podstawie ilosci wpisow
	
	int a=strona*wpis_max;//zakres od jakiego wpisu ma pokazac
	int licznik=this->wpis_w_dzienniku;
	this->strony=strona;
	std::cout <<"V-------------------------------Dziennik---------------------------------V"<<std::endl;
	
	if(a==licznik) //gdy ilosc wpisow zgadza sie z iloscio max wpisow...
	{
		std::cout <<std::endl<<"    "<<"Brak wpisow w dzienniku"<<std::endl;
	}
	else
	{
			while(a<(strona*wpis_max)+wpis_max) // po lewej od < - zakres do jakiego wpisu ma pokazac
			{
				if(spis[a].length()>=55) //gdy tresc questa za dluga
				{
					std::cout<<std::endl<<"    -";
					int dlugosc_tekstu=spis[a].length(),b=0,czesc=55;
					while(b<dlugosc_tekstu)
					{
						std::cout<<"   "<<spis[a].substr(b,czesc)<<std::endl;
						b=b+czesc;
					}
				}
				else if(spis[a]=="") ;
				else std::cout<<std::endl<<"    -"<<"   "<<spis[a]<<std::endl;
				
				++a;
			}	
	}
	std::cout <<std::endl<<"^------------------------------------------------------------------------^"<<std::endl;
	std::cout<<std::endl<<"                                    "<<get_strona()<<"/"<<max_strony<<std::endl<<std::endl;
	system("pause");
	system("cls");	
}

void journal::aktual_pozycje_w_dzienniku(){++wpis_w_dzienniku;}

int journal::get_strona(){return strony;}

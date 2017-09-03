#ifndef items_h
#define items_h
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "eventing.h"
	
enum typ_p{jedzenie,bron,mikstura,rozne};

class przedmiot
{
	private:
		unsigned int wartosc;
		char uzycie;
		std::string nazwa;
		std::string opis;
		typ_p rodzaj;
		int obrazenka;
		
	public:
		przedmiot(int wart,std::string nazwa,char uzycie,typ_p perk,int wartos,std::string opisek)
		:wartosc(wart),nazwa(nazwa),uzycie(uzycie),rodzaj(perk),obrazenka(wartos),opis(opisek){}
		unsigned int get_wartosc();
		void set_wartosc(int wartos);
		char get_uzycie();
		typ_p get_rodzaj();
		void set_uzycie(char uzyt);
		int daj_obrazenia();
		std::string get_nazwa();
		std::string get_opis();
};

#endif

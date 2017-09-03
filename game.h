#ifndef game_h
#define game_h
#include <iostream>

#include "items.h"
#include "character.h"
#include "wrog.h"
#include "fight.h"
#include "eventing.h"
#include "paragraph.h"
const unsigned int max_dlug=40; //wymiary mapy swiatowej
const unsigned int max_szer=130;



class gra
{
	private:
		int stan;
		bool przelacznik[100];
		int dlug,szer; //wymiary mapy lokalnej (na NASZ obraz gry w interf)
		char **teren; 
		char **mapa_lokalna;
		char nazwa_lokacji[100]; 
		
	public:	
		gra(int stanek,int dlug,int szer):stan(stanek),dlug(dlug),szer(szer)
		{
			try
			{
				this->teren = new char*[max_dlug];
				for (int i = 0; i < max_dlug; ++i) this->teren[i] = new char[max_szer];
		
				this->mapa_lokalna = new char*[dlug];
				for (int j = 0; j < dlug; ++j) this->mapa_lokalna[j] = new char[szer];
			}
			catch(std::bad_alloc& e)
			{
				std::printf("B³¹d alokacji: %s\n", e.what()); 
			}
		}
		~gra()
		{
			for(int i=0; i<dlug; i++) delete [] mapa_lokalna[i];
    		delete [] mapa_lokalna;
    		
    		for(int j=0; j<max_dlug; j++) delete [] teren[j];
    		delete [] teren;
    		
		}
		int kreator_postaci();
		void intro();
		void inicjalizuj_przelaczniki();
		int  sprawdz_uzytek(std::vector<przedmiot>);
		void akcja(std::string,std::string,char,int,int);
		void kolizja(std::string,postac &,char ** &,journal &);
		void wczytaj_plik(char *); //wczytaj plik duzej mapy swiata (30x140)
		void wczytaj_obraz(std::string);//wczytaj obraz zdjecia na interf (14x29)
		char ** get_mapa_lokalna();
		std::string daj_nazwa_lokacji();
		void inicjuj(postac,int tryb,int dlug,int szer);
		friend int walka_z_wrogiem(postac &,int);
		friend int handel_barman(postac &,int,std::string);
};
#endif

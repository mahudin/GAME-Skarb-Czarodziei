#ifndef character_h
#define character_h
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "items.h"

class postac
{
	private:
		int x;
		int y;
		std::string imie;
		std::string klasa;
		int stan_postaci; //zyje czy jest martwa
		int zycie; //ilosc punktow zycia
		unsigned int poziom;
		unsigned int sila;
		unsigned int zrecznosc;
		int doswiadczenie;
		int pieniadze;
		char grafika;
		std::vector<przedmiot> ekwipunek;
		
	public:
		postac(int yb,int xa,int stan,std::string imionko,std::string klasa,char grafa,
				int zycie,unsigned int poziom,unsigned int sila,unsigned int zrecznosc,std::vector<przedmiot> plecaczek)
				:y(yb),x(xa),stan_postaci(stan),imie(imionko),klasa(klasa),grafika(grafa),zycie(zycie),poziom(poziom)
				,sila(sila),zrecznosc(zrecznosc),ekwipunek(plecaczek)
				{
				static int star=0;
				if(star==0){starter();star=1;}
				}
				
		int daj_stan();					
		int getX();
		int getY();
		int get_zycie();
		int get_pieniadze();
		int get_doswiadczenie();
		int zwroc_rozmiar_ekwipunek();
		int podaj_z_ekwipunek_gotowa_bron(char);
		unsigned int get_poziom();
		unsigned int get_sila();
		unsigned int get_zrecznosc();
		char get_grafika();
		
		std::string get_imie();
		std::string get_klasa();
		std::vector<przedmiot> get_ekwipunek();
			
		void setX(int x);
		void setY(int y);		
		void set_doswiadczenie(int);
		void set_poziom(unsigned int);	
		void set_pieniadze(int);
		void set_stan(int);
		void set_zytko(int);
		void set_ekwipunek(std::vector<przedmiot>);
		void wyswietl_ekwipunek();
		void usun_z_ekwipunek(std::string);
		void uzyj_z_ekwipunek(std::string);
		void opisz_z_ekwipunek(std::string);
		void dod_ekwipunek(przedmiot &);
		
		void starter();
		void dopalacz();
		int wlasc_liczba(std::string);
		
		friend int walka_z_wrogiem(postac &,int);
		friend int handel_barman(postac &,int,std::string);
};

#endif

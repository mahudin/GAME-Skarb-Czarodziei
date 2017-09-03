#ifndef eventing_h
#define eventing_h
#include <iostream>
#include "items.h"

class zdarzenia
{
	public:
		void normalnie();
		void losik();
		void zakaz_miasto();
		void drogowskaz1();
		int zamkniete_wrota(std::string,int);
		int zamknieta_skrzynia001(std::string);
		int zamknieta_skrzynia002(std::string);
		int zamknieta_skrzynia003(std::string);
		int wlasc_liczba(std::string id);
		void skrzynia();
		void barman();
		void barman_zakupy();
		void barman_zakupy_fail();
		void dwaj_towarzysze();
		void plotki();
};

#endif

#ifndef journal_h
#define journal_h
#include <iostream>

class journal
{
	private:
		std::string spis[1000]; //ilosc pojedynczych wpisow
		int strony; //ilosc stron, kazda zawiera po kilka wpisow
	public:
		journal(){ wpis_w_dzienniku=0; }
		void dod_do_dziennik(std::string);
		void przegladaj_dziennik(int);
		int get_strona();
		static int wpis_w_dzienniku;
		static void aktual_pozycje_w_dzienniku();
};

#endif

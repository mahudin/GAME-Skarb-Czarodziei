#ifndef wrog_h
#define wrog_h
#include <iostream>

class wrog
{
	protected:
		int zle_zycie;
		int stan_wroga;
		std::string nazwa;
		
	public:	
		wrog(int zle_zyci,int zycie_w,std::string nazwa):zle_zycie(zle_zyci),stan_wroga(zycie_w),nazwa(nazwa){}
			
		void set_zycie(int);
		void set_stan(int);
		int get_stan();
		int daj_zdrowie();
		std::string daj_nazwa();
};

class bestia:public wrog
{
	private:
		int obrazenia;
	public:
		bestia(int zle_zyci,int zycie_w,std::string nazwa,int obraz):wrog(zle_zyci,zycie_w,nazwa),obrazenia(obraz){}
		
		int daj_obrazenia();
		std::string daj_nazwa();		
};

#endif

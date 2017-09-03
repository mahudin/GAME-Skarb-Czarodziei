#include <iostream>
#include "wrog.h"

void wrog::set_zycie(int zytko)
{
	if(zytko<=0) zle_zycie=zle_zycie+zytko;
	else zle_zycie=zytko;
	if(zle_zycie==0) set_stan(0);
}
void wrog::set_stan(int stan){stan_wroga=stan;}
int wrog::get_stan(){return stan_wroga;}
int wrog::daj_zdrowie(){return zle_zycie;}
std::string wrog::daj_nazwa(){return "wrog";}
int bestia::daj_obrazenia(){return obrazenia;}
std::string bestia::daj_nazwa(){return nazwa;}

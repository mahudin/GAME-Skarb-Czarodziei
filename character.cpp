#include <iostream>
#include <cstdlib>
#include <cstring>
#include "character.h"

int postac::getX()		{return x;}
int postac::getY()		{return y;}
int postac::daj_stan()	{return stan_postaci;}
void postac::set_stan(int stan)	{stan_postaci=stan;}
void postac::setX(int x)	{this->x=getX()+x;}
void postac::setY(int y)	{this->y=getY()+y;}
int postac::get_zycie()	{return zycie;}
std::string postac::get_imie()		{return imie;}
std::string postac::get_klasa()		{return klasa;}
unsigned int postac::get_poziom()	{return poziom;}
unsigned int postac::get_sila()		{return sila;}
void postac::set_zytko(int zyc)
{
	if(zyc<=0) zycie=zycie+zyc;
	else zycie=zyc;
	if(zycie==0) set_stan(0);
}
int postac::get_doswiadczenie()		{return doswiadczenie;}
void postac::set_doswiadczenie(int doswiad)
{
	doswiadczenie=doswiad;
	if( get_doswiadczenie()==100 || //2 poziom
	 	get_doswiadczenie()==300 || //3 poziom itd..
	 	get_doswiadczenie()==600)
		 {
		 	set_poziom(get_poziom()+1);
		 	std::cout <<"KOLEJNY POZIOM"<<std::endl;
		  } 
}
void postac::set_poziom(unsigned int poz){poziom=poz;}
unsigned int postac::get_zrecznosc(){return zrecznosc;}
int postac::get_pieniadze()			{return pieniadze;}
std::vector<przedmiot> postac::get_ekwipunek(){return ekwipunek;}
void postac::set_ekwipunek(std::vector<przedmiot> ekwip)
{
	ekwip.swap(ekwipunek);
}
void postac::wyswietl_ekwipunek()
{
	std::cout <<"Zawartosc ekwipunku: "<<std::endl;
	if(ekwipunek.empty())
	{
		std::cout <<std::endl<<"  Ekwipunek jest pusty ! "<<std::endl<<std::endl;
	}
	else
	{
		std::cout <<"========================================================= "<<std::endl;
		std::cout <<"|ID. NAZWA				WARTOSC	 UZYCIE	|"<<std::endl;
		for( int i = 0; i < ekwipunek.size(); i++ )
		{
			std::cout <<"|"<<i<<". ";
   			std::cout <<  ekwipunek[i].get_nazwa() <<
		   		"  		"<<ekwipunek[i].get_wartosc()<<
				"        "<< ekwipunek[i].get_uzycie()<<" 	|"<<std::endl;
		}
		std::cout <<"========================================================= "<<std::endl;
	}
	system("pause");
	system("cls");
}

void postac::usun_z_ekwipunek(std::string id)
{
	int wlasciwa_cyfra=this->wlasc_liczba(id);
	int licznik=0;
	std::cout <<"Zawartosc ekwipunku: "<<std::endl;
	int dlug_e=ekwipunek.size();
	if(ekwipunek.empty() || (dlug_e-1)<wlasciwa_cyfra) std::cout <<std::endl<<"  Ekwipunek jest pusty lub bledne id ! "<<std::endl<<std::endl;
	else
	{
    	std::vector <przedmiot>::iterator it=ekwipunek.begin();
    	for(;it<ekwipunek.begin()+wlasciwa_cyfra;it++) ;
    			
		ekwipunek.erase(it);
		std::cout <<std::endl<<"  Element o id "<<wlasciwa_cyfra<<" usunieto ! "<<std::endl<<std::endl;
	}
	system("pause");
	system("cls");
}

void postac::opisz_z_ekwipunek(std::string id)
{
	int wlasciwa_cyfra=this->wlasc_liczba(id);
	int licznik=0;
	std::cout <<"Opis przedmiotu: "<<std::endl;
	int dlug_e=ekwipunek.size();
	if(ekwipunek.empty() || (dlug_e-1)<wlasciwa_cyfra) std::cout <<std::endl<<"  Ekwipunek jest pusty lub bledne id ! "<<std::endl<<std::endl;
	else
	{
		int id_z=0;
    	std::vector <przedmiot>::iterator it=ekwipunek.begin();
    	for(;it<ekwipunek.begin()+wlasciwa_cyfra;it++) id_z++;
    	
    	std::cout<<ekwipunek[id_z].get_nazwa()<<std::endl<<std::endl;
		std::cout<<ekwipunek[id_z].get_opis()<<std::endl;
				
	}
	system("pause");
	system("cls");
}

void postac::uzyj_z_ekwipunek(std::string id)
{
	int wlasciwa_cyfra=this->wlasc_liczba(id);
	int licznik=0;
	int dlug_e=ekwipunek.size();
	if(ekwipunek.empty() || (dlug_e-1)<wlasciwa_cyfra) std::cout <<std::endl<<"  Ekwipunek jest pusty lub bledne id ! "<<std::endl<<std::endl;
	else
	{
		int id_z=0,id_jz=0,idr;
    	std::vector <przedmiot>::iterator it=ekwipunek.begin();
    	for(;it<ekwipunek.begin()+wlasciwa_cyfra;it++) id_z++ ;
    			
    	for(id_jz;id_jz<dlug_e;id_jz++) 
		{
			if(ekwipunek[id_jz].get_uzycie()=='+')
			{
				idr=id_jz;
				ekwipunek[id_jz].set_uzycie(' ');
			}	 //gdy bedzie inny w uzyciu, zwolnic go z tego
		}
		
		if(ekwipunek[id_z].get_rodzaj()==0 || ekwipunek[id_z].get_rodzaj()==2) //gdy bedzie to typ mikstury itp, skorz. z wlasciwosci jego
		{
				if(ekwipunek[id_z].get_nazwa()=="Mikstura zycia	") set_zytko(get_zycie()+40);
				if(ekwipunek[id_z].get_nazwa()=="Jablko		") set_zytko(get_zycie()+10);
				std::cout <<std::endl<<"  Element o id "<<wlasciwa_cyfra<<" jest typu konsupcyjnego- zostal wlasnie zuzyty "<<std::endl<<"   i usuniety z ekwipunku !"<<std::endl<<std::endl;
				std::vector <przedmiot>::iterator itr=ekwipunek.begin(); //po spozyciu usuwamy go
    			for(;itr<ekwipunek.begin()+idr-1;itr++) ;
				ekwipunek.erase(it); 
		} 	
		else
		{
			ekwipunek[id_z].set_uzycie('+');
			std::cout <<std::endl<<"  Element o id "<<wlasciwa_cyfra<<" jest juz w uzyciu ! "<<std::endl<<std::endl;
		} 
	}
	system("pause");
	system("cls");
}

int postac::podaj_z_ekwipunek_gotowa_bron(char znak)
{

	int licznik=0;
	int dlug_e=ekwipunek.size();
	if(ekwipunek.empty());
	else
	{
		int id_z=-1,id_jz=0,idr;
    	std::vector <przedmiot>::iterator it=ekwipunek.begin();
    	for(;it<ekwipunek.begin()+dlug_e;it++) 
		{
			++id_z;
			if(ekwipunek[id_z].get_uzycie()=='+')
			{
				if(ekwipunek[id_z].get_rodzaj()==1)
				return ekwipunek[id_z].daj_obrazenia();
			}
		}
	}
	return 0;
}

void postac::dod_ekwipunek(przedmiot & item)
{
	ekwipunek.push_back(item);
}

char postac::get_grafika()
{
	return grafika;
}

void postac::starter()
{
	przedmiot scyzoryk		(30, "Scyzoryk      	",'+',bron,14,"  Dobra bron w kategorii krotkie miecze, w sam  raz do \n doraznego ranienia przeciwnika.\n\n  OBRAZENIA: 14\n\n");
	przedmiot mikstura_zycia(20, "Mikstura zycia	",' ',mikstura,0,"  Mikstura regenerujaca 50 punktow zdrowia.\n\n");
	przedmiot jablko		(5, "Jablko		",' ',jedzenie,0,"  Ten niepozorny owoc kryje w sobie moc, objawiajaca \n sie w zjedzeniu go w duzej ilosci\n\n");
	
	this->ekwipunek.push_back(scyzoryk);
	this->ekwipunek.push_back(mikstura_zycia);
	this->ekwipunek.push_back(jablko);
}

void postac::set_pieniadze(int kasa)
{
	pieniadze=kasa;
}

int postac::wlasc_liczba(std::string id)
{
	int wlasciwa_cyfra;
	if(id=="0") wlasciwa_cyfra=0;
	if(id=="1") wlasciwa_cyfra=1;
	if(id=="2") wlasciwa_cyfra=2;
	if(id=="3") wlasciwa_cyfra=3;
	if(id=="4") wlasciwa_cyfra=4;
	if(id=="5") wlasciwa_cyfra=5;
	if(id=="6") wlasciwa_cyfra=6;
	if(id=="7") wlasciwa_cyfra=7;
	if(id=="8") wlasciwa_cyfra=8;
	if(id=="9") wlasciwa_cyfra=9;
	if(id=="10") wlasciwa_cyfra=10;
	if(id=="11") wlasciwa_cyfra=11;
	if(id=="12") wlasciwa_cyfra=12;
	if(id=="13") wlasciwa_cyfra=13;
	if(id=="14") wlasciwa_cyfra=14;
	if(id=="15") wlasciwa_cyfra=15;
	if(id=="16") wlasciwa_cyfra=16;
	if(id=="17") wlasciwa_cyfra=17;
	if(id=="18") wlasciwa_cyfra=18;
	if(id=="19") wlasciwa_cyfra=19;
	if(id=="20") wlasciwa_cyfra=20;
	if(id=="21") wlasciwa_cyfra=21;
	if(id=="22") wlasciwa_cyfra=22;
	if(id=="23") wlasciwa_cyfra=23;
	if(id=="24") wlasciwa_cyfra=24;
	return wlasciwa_cyfra;
}

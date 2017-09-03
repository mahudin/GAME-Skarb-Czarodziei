#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "eventing.h"

void zdarzenia::normalnie()
{
	std::cout<<"  Po opis sterowania jak i  "<<std::endl;
	std::cout<<" podstaw gry mozna siegnac  "<<std::endl;
	std::cout<<" po przez komende 'p' !		"<<std::endl;
	std::cout<<" "<<std::endl;
}

void zdarzenia::losik()
{
	std::cout<<"walka";
}

int zdarzenia::zamkniete_wrota(std::string komenda_glowna,int id_z)
{
	static int otwartosc=0;
	if(otwartosc==0)
	{
		int pozycja_cyfr; //SZUKANIE LICZB w komendzie glownejs
		for (char liczby=48;liczby<=57;liczby++)
		{
			int pozc=komenda_glowna.find(liczby); // szukanie znaku liczby
			if(pozc != std::string::npos)
			{
				pozycja_cyfr=pozc;//pozycja jego
				std::string cyfra= komenda_glowna.substr(pozycja_cyfr,1);//zwrot i pobranie go
				if(komenda_glowna==("iu"+cyfra) || komenda_glowna==("IU"+cyfra)) 
				{
					int cyfra_real=wlasc_liczba(cyfra);
					return cyfra_real+1;
				}	
			}
		}
	} 	
	else
	{
		std::cout<<"   Widze przed sob¹ zamkniete "<<std::endl;
		std::cout<<" wrota ! Wyglada na to ze musze "<<std::endl;
		std::cout<<" poszukac jakiegos klucza..."<<std::endl;
		std::cout<<" "<<std::endl;
		return 0;
	}
}

void zdarzenia::zakaz_miasto()
{
	std::cout<<"  Nie moge tam teraz isc. Mam misje do wykonania- po za tym"<<
	std::endl<<" gildia na mnie liczy- i moga mnie ukatrupic jak wroce z"<<
	std::endl<<" niczym "<<
	std::endl<<" "<<std::endl;
}

void zdarzenia::drogowskaz1()
{
	std::cout<<"Napotykasz sie na jakis drogowskaz. Jest na nim napisane"<<
	std::endl<<" \"Na wschod- karczma Zaporoze, na Zachód miasto Eyewyn,"<<
	std::endl<<" na Po³udnie,krwawe wrzosowiska - WCHODZISZ NA WLASNE RYZYKO !\""<<
	std::endl<<"Chyba mam sie czego bac, skoro nikt stamtad nie wraca."<<std::endl;
}

int zdarzenia::zamknieta_skrzynia003(std::string komenda_glowna)
{
	std::cout<<"  Stara jakas sfatygowana skrzynia  "<<std::endl;
	std::cout<<" Nie ma w niej nic co moglo by mi  "<<std::endl;
	std::cout<<" sie przydac pozniej."<<std::endl;
	std::cout<<" "<<std::endl;
	return 1;
}

int zdarzenia::zamknieta_skrzynia002(std::string komenda_glowna)
{
	static int zamknietosc002=0;
	if(zamknietosc002==1)
	{
		return 1;
	} 
	else
	{
		std::cout<<"   Napataczasz sie na jakas skrzynie  "<<std::endl;
		std::cout<<" Otwierasz i wyjmujesz z niej stary  "<<std::endl;
		std::cout<<" mocno pordzewia³y klucz."<<std::endl;
		std::cout<<" "<<std::endl;
		zamknietosc002=1;
		return 1;
	} 
}

int zdarzenia::zamknieta_skrzynia001(std::string komenda_glowna)
{
	static int zamknietosc001=0;
	if(zamknietosc001==1)
	{
		return 1;
	} 
	else
	{
		std::cout<<"   Napataczasz sie na jakas skrzynie  "<<std::endl;
		std::cout<<" Otwierasz i wyjmujesz z niej troche  "<<std::endl;
		std::cout<<" kasy i jakis podreczny luk."<<std::endl;
		std::cout<<" "<<std::endl;
		zamknietosc001=1;
		return 1;
	} 
}

void zdarzenia::skrzynia()
{
	std::cout<<"   Otwierasz skrzynie a tam:!";
}

void zdarzenia::barman()
{
	std::cout<<"W czym moge pomoc ?"<<std::endl;
	std::cout<<"1. Zakupy"<<std::endl;
	std::cout<<"2. Skarb czarodziei"<<std::endl;
	std::cout<<"3. Plotki"<<std::endl;
}

void zdarzenia::barman_zakupy()
{
	std::cout<<"Do wyboru:"<<std::endl;
	std::cout<<"1. Mikstura lecznicza   -10 zl/szt."<<std::endl;
	std::cout<<"2. Dlugi miecz          -25 zl/szt."<<std::endl;
	std::cout<<"3. Powrót"<<std::endl;
}

void zdarzenia::barman_zakupy_fail()
{
	std::cout<<"Panie, nie ma kasy, nie ma przedmiotu"<<std::endl;
	std::cout<<"PrzyjdŸ jak bedzie ci sie lepiej wiodlo"<<std::endl;
	std::cout<<" "<<std::endl;
	system("pause");
}

void zdarzenia::dwaj_towarzysze()
{
	int loseczek=( std::rand() %  3) + 1;
	if(loseczek==1)
	{
		std::cout<<"  Ej, nie widzisz ze rozmawiam !"<<std::endl;
		std::cout<<" Znajdz sobie lepsze towarzystwo"<<std::endl;
		std::cout<<" "<<std::endl;
		std::cout<<" "<<std::endl;
	}
	else if(loseczek==2)
	{
		std::cout<<"  Ladnie to tak przeszkadzac innym !"<<std::endl;
		std::cout<<" Won"<<std::endl;
		std::cout<<" "<<std::endl;
		std::cout<<" "<<std::endl;
	}
	else
	{
		std::cout<<"  Czego od nas chcesz ?"<<std::endl;
		std::cout<<" Jestesmy zajeci !"<<std::endl;
		std::cout<<" "<<std::endl;
		std::cout<<" "<<std::endl;
	}
}

void zdarzenia::plotki()
{
	int loseczek=( std::rand() %  2) + 1;
	if(loseczek==1)
	{
		std::cout<<"  Powiadaja ze w Eyewin sa dobre piwa"<<std::endl;
		std::cout<<" Pasuje kiedys sprawdzic ten stan rzeczy"<<std::endl;
		std::cout<<" "<<std::endl;
		std::cout<<" "<<std::endl;
	}
	else if(loseczek==2)
	{
		std::cout<<"  Podobno kolejny nieszczesnik jakis"<<std::endl;
		std::cout<<" na wrzosowiskach przepadl. Strach sie"<<std::endl;
		std::cout<<" bac normalnie !"<<std::endl;
		std::cout<<" "<<std::endl;
	}
}

int zdarzenia::wlasc_liczba(std::string id)
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

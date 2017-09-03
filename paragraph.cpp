#include <iostream>
#include <cstdlib>
#include <cstring>
#include "paragraph.h"

void paragraph::introduction()
{
	int a,b;
	for(a=0;a<11;a++)
	{
		for(b=0;b<60;b++)
		{
			if((b>=0 || b<=69) && a==0) std::cout <<"-";
			else if(b==0 && a==2 ) std::cout <<"     Dawno dawno temu, w pewnej mrocznej krainie Asgoth"<<std::endl;
			else if(b==0 && a==3 ) std::cout <<"   zyla miedzy ludzmi legenda o wielkim skarbie, w ukrytych"<<std::endl;
			else if(b==0 && a==4 ) std::cout <<"   za lasami ruinach wiezy pewnego za dawnych czasow "<<std::endl;
			else if(b==0 && a==5 ) 
			{
				std::cout <<"   czarnoksieznika..."<<std::endl<<std::endl;	
				system("pause");
				std::cout <<std::endl<<"   wielu juz probowalo polozyc na nim swoje lapska jednak   "<<std::endl;
			}
			else if(b==0 && a==6 ) std::cout <<"   zadnemu sie to nie udalo...  pewnego razu"<<std::endl;
			else if(b==0 && a==7 ) std::cout <<"   mlody czlonek mrocznej gildii zostaje wyslany "<<std::endl;
			else if(b==0 && a==8 ) std::cout <<"   na misje w celu ratowania grupowej kasy "<<std::endl;
			else if(b==0 && a==9 ) std::cout <<"   nie wiedzac co go bedzie czekac w tej przygodzie... "<<std::endl;
			else std::cout<<" ";
		
		}
		std::cout<<std::endl;	
	}
	system("pause");
	system("cls");
}

void paragraph::zamk_wrot()
{
	std::cout<<"   Widze przed sob¹ zamkniete "<<std::endl;
	std::cout<<" wrota ! Wyglada na to ze musze "<<std::endl;
	std::cout<<" poszukac jakiegos klucza..."<<std::endl;
	std::cout<<" "<<std::endl;
}

void paragraph::menu_layout()
{
	std::cout << "=============================="<<std::endl;
	std::cout << "====SKARB CZARODZIEJI v.1.0==="<<std::endl;
	std::cout << "=============================="<<std::endl;
	std::cout << "<--------MENU-------->"<<std::endl<<std::endl;
	std::cout << "1.Rozpocznij now¹ gre"<<std::endl;
	std::cout << "2.Autor"				<<std::endl;
	std::cout << "3.Wyjscie"			<<std::endl;
	std::cout << "<-------------------->"<<std::endl;
	std::cout <<std::endl<< ":"<<"->"<<std::endl;
}

void paragraph::pomoc()
{
	std::cout << " Sterowanie: "<<std::endl<<std::endl<<
				std::endl<<"  Poruszanie:     Obsluga ekwipunku:             Pomocnicze/System:"<< 
				std::endl<<"  W - idz w gore  I   - ekwipunek                 ENTER - akcja"<< 
				std::endl<<"  S - idz w dol   IRx - wyrzuc przedmiot o id x   V     - wersja gry"<<
				std::endl<<"  A - idz w lewo  IUx - uzyj przedmiot o id x     P     - pomoc"<<
				std::endl<<"  D - idz w prawo IDx - opisuje przedmiot o id x  Z     - zakoncz"<<std::endl<<std::endl;
				std::cout<<"  Pojedynek: 	  Dziennik:"				<<
				std::endl<<"  R - atakuj      J   - dziennik"			<< 
				std::endl<<"  U - ucieczka    Jx  - x strona dziennika"	<<
				std::endl<<"  O - obrona  							"<<
				std::endl<<"    	"<<
				std::endl<<"  "<<
				std::endl<<std::endl;
				std::cout << "  Legenda: "<<
				std::endl << "   :/U - drzwi/wrota  X - budowla/zabudowanie "<<
				std::endl << "   ?   - tajemnica    N - mieszkaniec/osoba   "<<
				std::endl << "   &   - las          # - stol				"<<
				std::endl << "   %   - skrzynia     = - sciany 				"<<std::endl<<std::endl;
				system("pause");
				system("cls");	
}

void paragraph::wersja_gry()
{
	std::cout<<"WERSJA GRY"<<std::endl;
	std::cout<<"demo 1.0.08 PL"<<std::endl;
	system("pause");
	system("cls");	
}

void paragraph::autor()
{
	std::cout<<std::endl<<"Autor: Micha³ Hudaszek"<<std::endl;
	system("pause");
};

void paragraph::zamkniete()
{
	std::cout<<std::endl<<"Przedmiot nie pasuje do dziury od klucza !"<<std::endl;
	std::cout<<std::endl<<"Muszê poszukac czegos innego				"<<std::endl;
	std::cout<<std::endl<<""<<std::endl;
};

void paragraph::wyjscie()
{
	poczatek:
	char komenda_boczna;	
	system("cls");
	std::cout<<"Chcesz zakonczyc gre bez zapisu ?"<<std::endl;
	std::cout<<"1.Tak -zakoncz "<<std::endl<<"2.Nie- kontynuuj gre"<<std::endl<<std::endl;
	std::cin>>komenda_boczna;
	if(komenda_boczna==49) exit(1); 
	else if(komenda_boczna==50) system("cls");
	else goto poczatek;
}

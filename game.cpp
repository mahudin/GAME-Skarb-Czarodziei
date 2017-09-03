#include <windows.h>
#include <dos.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <fstream>
#include <new>
#include "journal.h"
#include "wrog.h"
#include "game.h"

void gra::inicjuj(postac heros,int tryb,int dlug,int szer) //wyswietla na widok konsoli teren z interfejsem
{
	int dlugd=dlug-1;
	int szer_stan=szer+15;
	char zdrowko=3; // serduszko- symbolizuje zdrowie naszego bohatera
	
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
	char ogrodzenie='#',pusta_przestrzen=' ';
	
	std::string zwierze; //wczytanie obrazu w zaleznosci czy walczymy ze zwierzeciem
	if(tryb==1)	zwierze="wolf";	
	else if(tryb==2) zwierze="rat";										

	if(tryb==0) 	//robimy mniejsze zdjecie z mapy w swiecie na nasz interfejs swiata gry//
	{
		for(e=0;e<max_dlug;e++) //y
		{
			for(f=0;f<max_szer;f++) //x
			{
				if((e>=heros.getX()-7) && (e<=heros.getX()+7) && (f>=heros.getY()-14) && (f<=heros.getY()+14)) 
				{
					mapa_lokalna[c][d]=teren[e][f];
					d++;
					if(d==29) 
					{
						c++;
						d=0;	
					}				
				}
			}
		}
	}
	else if(tryb!=0) wczytaj_obraz(zwierze);//pobieramy ju¿ spreparowe i przygotowane zdjecie obrazu na nasz interfejs swiata gry//
	
	for(int y=0;y<(dlugd-1);y++) //rysujemy obraz gry
		{		
			for(int x=0;x<(szer_stan-1);x++)
			{		
				//interfejs
				if((y==0 && x<(szer-1)) || (y==(dlugd-2)&& x<(szer-1))) std::cout << ogrodzenie; //obramowanie (gora i dol)
				else if(x==0 || x==(szer_stan-17)) std::cout << ogrodzenie; //obramowanie (boki)
				else if(x>(szer_stan-17)) std::cout << pusta_przestrzen; //po za obramowaniem (w prawo)
				else if((((szer_stan-17)/2)==x) && ((dlugd/2)==y) && tryb==0) 
				{
					std::cout<<heros.get_grafika(); //pozycja bohatera
					h++; //z powodu grafiki gracza ponizej sie rozsuwa, wiec..
				}
				else if((y>0 && y<dlugd) || (x>0 && x<(szer_stan))) //obraz obszaru
				{
					std::cout << mapa_lokalna[g][h];
					h++;
					if(h==29) 
					{
						g++;
						h=0;	
					}
				} 	
					//ekwipunek
					
				if(y==2 && x==(szer+5)) std::cout <<heros.get_imie(); 
				if(y==4 && x==(szer+5)) std::cout <<"Klasa: "<<heros.get_klasa();
				if(y==4 && x==(szer+8)) std::cout <<"Poziom: "<<heros.get_poziom();
				if(y==6 && x==(szer+5)) std::cout <<zdrowko<<" "<<heros.get_zycie();
				if(y==8 && x==(szer+5)) std::cout <<"Sila: "<<heros.get_sila();
				if(y==9 && x==(szer+5)) std::cout <<"Zrecznosc: "<<heros.get_zrecznosc();
				if(y==13 && x==(szer+5)) std::cout <<"$: "<<heros.get_pieniadze();
				if(y==15 && x==(szer+5)) std::cout <<"X:"<<heros.getY()<<" Y:" <<heros.getX();
			}
			if(y==2) std::cout << " ";
			std::cout<<std::endl;
		}	
}

void gra::intro()
{
	int opcja;
	intro:
	system("cls");	
	paragraph::menu_layout();
	std::cin >> opcja;
	switch(opcja)
		{
			case 1:
				kreator_postaci();
				break;
			case 2:
				paragraph::autor();
				break;
			case 3:
				exit(1);
				break;	
			default:	
				break;
		}
	goto intro;	
}

std::string gra::daj_nazwa_lokacji()
{
	return nazwa_lokacji;
}

int gra::kreator_postaci()
{
	int opcja_postaci,wybor_grafiki,wybor_klasy;
	std::string imie,klasa;
	char grafika;
	unsigned int sila,zrecznosc;
	inicjalizuj_przelaczniki();
	while(opcja_postaci!=1)
		{
			system("cls");
			std::cout<<"^^^^^^ Kreator postaci ^^^^^^"<<std::endl<<std::endl;
			std::cout<<"-Wprowadz imie bohatera: "<<std::endl<<":-> ";
			std::cin>>imie;
			std::cout<<"-Wprowadz klase bohatera- domyslnie wojownik ";
			std::cout<<std::endl<<" 1.Wojownik ";
			std::cout<<std::endl<<" 2.Lowca ";
			std::cout<<std::endl<<":-> ";
			std::cin>>wybor_klasy;
			if(wybor_klasy==1) klasa="Wojownik";
			else if(wybor_klasy==2) klasa="Lowca";
			else klasa="Wojownik";
			std::cout<<std::endl;
			std::cout<<"-Wprowadz grafike naszego bohatera- domyslnie bedzie pierwsza ";
			std::cout<<std::endl<<" 1. ^"<<std::endl<<" 2. *"<<std::endl<<" 3. @ "<<std::endl<<":-> ";
			std::cin>>wybor_grafiki;
			if(wybor_grafiki==1) grafika='^';
			else if(wybor_grafiki==2) grafika='*';
			else if(wybor_grafiki==3) grafika='@';
			else grafika='^';
			if(wybor_klasy==1){sila=12;zrecznosc=5;}
			else if(wybor_klasy==2){sila=5;zrecznosc=9;}
			else if(wybor_klasy==3){sila=5;zrecznosc=12;}
			
			std::cout<<"Postac utworzono"<<std::endl<<std::endl;
			std::cout<<"Decydujesz siê na t¹ postaæ ?"<<std::endl;
			std::cout<<"1.Tak"<<std::endl;
			std::cout<<"2.Nie"<<std::endl;
			std::cin>>opcja_postaci;
		}
	system("cls");
	akcja(imie,klasa,grafika,sila,zrecznosc);
}


void gra::inicjalizuj_przelaczniki()
{
	for(int u=0;u!=100;u++) this->przelacznik[u]=false;
}

void gra::akcja(std::string imie,std::string klasa,char grafika,int sila,int zrecznosc)
{	
	//tworzenie bohatera//
	int stan=1;
	journal dziennik;
	dziennik.dod_do_dziennik("Zostalem wyslany z misja odszukania i podebrania troche z legendarnych skarbow czarodzieii."); 
	dziennik.dod_do_dziennik("Musze udac sie przez krwawe wrzosowiska na poludniowy-zachod stad"); 
	std::vector<przedmiot> plecak;
	postac bohater(22,9,stan,imie,klasa,grafika,100,1,sila,zrecznosc,plecak);
	bohater.set_doswiadczenie(0);
	bohater.set_pieniadze(50);
	srand( time( NULL ) );
	paragraph::introduction();
	char startek[]="start";
	char blood_a[]="blood_area";
	char inside_a[]="inside_area";
	wczytaj_plik(startek);
	zdarzenia los;	
	while(1) //glowna petla gry
	{		
		inicjuj(bohater,0,18,32);
		char **kolizjoner=get_mapa_lokalna();
		static std::string komenda_glowna;
		std::cout <<"-----------------------------------------------------------------"<<std::endl;
		
		int idz=0,id_jz,wlasciwa_cyfra;
    	//eventy//
		if(daj_nazwa_lokacji()=="start")
		{	
			if(bohater.getX()==9 && bohater.getY()==14)
			{
				los.zakaz_miasto() ;
			}
			else if(bohater.getX()==9 && bohater.getY()==105)
			{
				system("cls");
				wczytaj_plik(inside_a);
				bohater.setX(6);
				bohater.setY(-39);
				inicjuj(bohater,0,18,32);
				std::cout <<"-----------------------------------------------------------------"<<std::endl;
			}
			else if(bohater.getX()==9 && bohater.getY()==41) 
			{
				if(los.zamknieta_skrzynia001(komenda_glowna)==1)  
				{
					if(przelacznik[12]==false) 
					{
						bohater.set_pieniadze(bohater.get_pieniadze()+30);
						przedmiot luk(30, "Luk debowy 	     	",' ',bron,19,"  Bron dystansowa sredniego zasiegu; idealna na chudego zwierza\n\n  OBRAZENIA: 19\n\n");
						bohater.dod_ekwipunek(luk);
						przelacznik[12]=true;
					}
					else los.normalnie();
				}
				else los.normalnie();
			}
			else if(bohater.getX()==28 && bohater.getY()==78) 
			{
				if(los.zamknieta_skrzynia002(komenda_glowna)==1)  
				{
					if(przelacznik[11]==false) 
					{
						przedmiot klucz(3, "Zardzewialy klucz	",' ',rozne,2,"  Jakis bardzo dawno nieuzywany kluczyk w sam raz\n do jakiegos przejscia...\n\n");
						bohater.dod_ekwipunek(klucz);
						przelacznik[11]=true;
					}
					else los.normalnie();
				}
				else los.normalnie();
			}
			else if(bohater.getX()==21 && bohater.getY()==81) 
			{
				if(przelacznik[10]==false)
				{
					if(przelacznik[14]==false)
					{
						dziennik.dod_do_dziennik("Udalo mi sie napotkac na swojej drodze jakies stare wrota. Niestety potrzebny jest do nich klucz, musze wiec rozejrzec sie po okolicy. Biorac pod uwage stan drzwi, klucz musi byc w niewiele lepszym."); przelacznik[14]=true;
					} 
					else ;
					int ajax=0,id_z;
					ajax=los.zamkniete_wrota(komenda_glowna,idz);
					if(ajax!=0 && ajax<=bohater.get_ekwipunek().size())
					{	
						std::vector <przedmiot>::iterator it=bohater.get_ekwipunek().begin();
    					for(it;it<bohater.get_ekwipunek().begin()+ajax-1;it++) ;
						
						if(bohater.get_ekwipunek()[ajax-1].get_nazwa()=="Zardzewialy klucz	")
						{
							std::cout<<"   Klucz pasuje jak ula³ !  "<<std::endl;
							std::cout<<" Otwieram drzwi i dalsza sciezka  "<<std::endl;
							std::cout<<" stoi dla mnie otworem ..."<<std::endl;
							std::cout<<" "<<std::endl;
							przelacznik[10]=true;
							bohater.get_ekwipunek().erase(it);
						}
						else paragraph::zamkniete();
					}
					else paragraph::zamk_wrot();
				}
				else los.normalnie();
			}
			else if(bohater.getX()==16 && bohater.getY()==62)
			{
				los.drogowskaz1() ;
			}
			else if(bohater.getX()==13 && bohater.getY()==90)
			{
				los.zamknieta_skrzynia003(komenda_glowna) ;
			}
			else if(bohater.getX()==25 && bohater.getY()==104)
			{
				system("cls");
				wczytaj_plik(blood_a);
				bohater.setX(0);
				bohater.setY(-85);
				inicjuj(bohater,0,18,32);
				std::cout <<"-----------------------------------------------------------------"<<std::endl;
			}
			else 
			{
				int losek =( std::rand() % 1000 ) + 0;
				if(losek==1)
				{
					system("cls");
					inicjuj(bohater,1,18,32);
					if(walka_z_wrogiem(bohater,1)==1) break;
					else inicjuj(bohater,0,18,32);
					std::cout <<"-----------------------------------------------------------------"<<std::endl;
					los.normalnie();
				}
				else if(losek>=2 && losek<=5)
				{
					system("cls");
					inicjuj(bohater,2,18,32);
					if(walka_z_wrogiem(bohater,2)==1) break;
					else inicjuj(bohater,0,18,32);
					std::cout <<"-----------------------------------------------------------------"<<std::endl;
					los.normalnie();
				}
				else los.normalnie();
			}
		}
		if(daj_nazwa_lokacji()=="blood_area")
		{
			if(bohater.getX()==23 && bohater.getY()==38)
			{
				std::cout <<"Cos ciekawego sie dzieje"<<std::endl;
			}
			if(bohater.getX()==13 && bohater.getY()==57)
			{
				system("cls");
				
				std::cout <<" Nasz bohater dotarl do pierwszych ruin powiazanych z wieza czarodzieji,"<<std::endl;
				std::cout <<"Tym samym konczy sie przygoda naszego bohatera w tej wersji gry."<<std::endl;
				std::cout <<" Jesli chcesz przezyc wiecej- zdobadz pelna wersje gry. Mimo"<<std::endl;
				std::cout<<" wszystko gratuluje wygranej i dojscia az tutaj ! "<<std::endl;
				std::cout<<" "<<std::endl;
				std::cout<<" Autor"<<std::endl<<std::endl;
				system("pause");
				exit(1);
			}
			else if(bohater.getX()==25 && bohater.getY()==18)
			{
				system("cls");
				wczytaj_plik(startek);
				bohater.setX(0);
				bohater.setY(85);
				inicjuj(bohater,0,18,32);
				std::cout <<"-----------------------------------------------------------------"<<std::endl;
			}
			else 
			{
				int losek =( std::rand() % 700 ) + 0;
				if(losek==1)
				{
					system("cls");
					inicjuj(bohater,1,18,32);
					if(walka_z_wrogiem(bohater,1)==1) break;
					else inicjuj(bohater,0,18,32);
					std::cout <<"-----------------------------------------------------------------"<<std::endl;
					los.normalnie();
				}
				else if(losek>=2 && losek<=5)
				{
					system("cls");
					inicjuj(bohater,2,18,32);
					if(walka_z_wrogiem(bohater,2)==1) break;
					else inicjuj(bohater,0,18,32);
					std::cout <<"-----------------------------------------------------------------"<<std::endl;
					los.normalnie();
				}
				else los.normalnie();
			}
		}
		if(daj_nazwa_lokacji()=="inside_area")
		{
			if(bohater.getX()==16 && bohater.getY()>=65 && bohater.getY()<=67)
			{
				system("cls");
				wczytaj_plik(startek);
				bohater.setX(-6);
				bohater.setY(39);
				inicjuj(bohater,0,18,32);
				std::cout <<"-----------------------------------------------------------------"<<std::endl;
				los.normalnie();
			}
			if(bohater.getX()==14 && bohater.getY()==66)
			{
				los.barman();
				if(komenda_glowna=="1")
				{
					handel_barman(bohater,0,komenda_glowna);
					system("cls");
					inicjuj(bohater,0,18,32);
					std::cout <<"-----------------------------------------------------------------"<<std::endl;
					los.barman();	
				}
				else if(komenda_glowna=="2")
				{
					system("cls");
					inicjuj(bohater,0,18,32);
					std::cout <<"-----------------------------------------------------------------"<<std::endl;
					std::cout <<"Nic nie wiem na ten temat i daj mi spokoj ! "<<std::endl<<std::endl<<std::endl;
				}
				else if(komenda_glowna=="3")
				{
					system("cls");
					inicjuj(bohater,0,18,32);
					std::cout <<"-----------------------------------------------------------------"<<std::endl;
					los.plotki();
				}
			}
			else if((bohater.getX()==10 && bohater.getY()==54)|| (bohater.getX()==10 &&bohater.getY()==56) )
			{
				los.dwaj_towarzysze();
			}			
			else los.normalnie();	
		}
	
		std::cout <<"-----------------------------------------------------------------"<<std::endl;
		std::cout <<"Wydaj polecenie:"<<"->";
		std::cin >> komenda_glowna;
		system("cls");	
		kolizja(komenda_glowna,bohater,kolizjoner,dziennik);	
	}		
}

void gra::kolizja(std::string komenda_glowna,postac & heros,char ** & kolizjoner,journal & dziennik)
{
		if(komenda_glowna=="d"  || komenda_glowna=="D")
		{
			if(kolizjoner[heros.getX()][heros.getY()+1]=='&') ;
			else if(kolizjoner[heros.getX()][heros.getY()+1]==' ')heros.setY(1);
			else if(kolizjoner[heros.getX()][heros.getY()+1]=='%')heros.setY(1);
			else if(kolizjoner[heros.getX()][heros.getY()+1]=='|')heros.setY(1);
			else if(kolizjoner[heros.getX()][heros.getY()+1]==':')heros.setY(1);
			else if(kolizjoner[heros.getX()][heros.getY()+1]=='?')heros.setY(1);
			else if(kolizjoner[heros.getX()][heros.getY()+1]=='N')heros.setY(1);
			else if(kolizjoner[heros.getX()][heros.getY()+1]=='+')
			{
				if(przelacznik[10]==true) heros.setY(1);
				else;
			}			
		}  
		else if(komenda_glowna=="a" || komenda_glowna=="A")
		{
			if(kolizjoner[heros.getX()][heros.getY()-1]=='&') ;
			else if(przelacznik[10]==true && kolizjoner[heros.getX()][heros.getY()-1]=='+') heros.setY(-1);
			else if(kolizjoner[heros.getX()][heros.getY()-1]=='+')
				{
				if(przelacznik[10]==true) heros.setY(-1);
				else;
			}	
			else if(kolizjoner[heros.getX()][heros.getY()-1]==' ')heros.setY(-1);
			else if(kolizjoner[heros.getX()][heros.getY()-1]=='%')heros.setY(-1);
			else if(kolizjoner[heros.getX()][heros.getY()-1]=='|')heros.setY(-1);
			else if(kolizjoner[heros.getX()][heros.getY()-1]==':')heros.setY(-1);
			else if(kolizjoner[heros.getX()][heros.getY()-1]=='?')heros.setY(-1);
			else if(kolizjoner[heros.getX()][heros.getY()-1]=='N')heros.setY(-1);
		} 
		else if(komenda_glowna=="s" || komenda_glowna=="S")
		{
			if(kolizjoner[heros.getX()+1][heros.getY()]=='&') ;
			else if(przelacznik[10]==true && kolizjoner[heros.getX()+1][heros.getY()]=='+') heros.setX(1);
			else if(kolizjoner[heros.getX()+1][heros.getY()]=='+')
				{
				if(przelacznik[10]==true) heros.setX(1);
				else;
			}	
			else if(kolizjoner[heros.getX()+1][heros.getY()]==' ')heros.setX(1);
			else if(kolizjoner[heros.getX()+1][heros.getY()]=='%')heros.setX(1);
			else if(kolizjoner[heros.getX()+1][heros.getY()]=='|')heros.setX(1);
			else if(kolizjoner[heros.getX()+1][heros.getY()]==':')heros.setX(1);
			else if(kolizjoner[heros.getX()+1][heros.getY()]=='?')heros.setX(1);
			else if(kolizjoner[heros.getX()+1][heros.getY()]=='N')heros.setX(1);
		}
		else if(komenda_glowna=="w" || komenda_glowna=="W")
		{
			if(kolizjoner[heros.getX()-1][heros.getY()]=='&') ;
			else if(przelacznik[10]==true && kolizjoner[heros.getX()-1][heros.getY()]=='+') heros.setX(-1);
			else if(kolizjoner[heros.getX()-1][heros.getY()]=='+')
			{
				{
					if(przelacznik[10]==true) heros.setX(-1);
					else;
				}	
			}
			else if(kolizjoner[heros.getX()-1][heros.getY()]==' ') heros.setX(-1);
			else if(kolizjoner[heros.getX()-1][heros.getY()]=='%') heros.setX(-1);
			else if(kolizjoner[heros.getX()-1][heros.getY()]=='|') heros.setX(-1);
			else if(kolizjoner[heros.getX()-1][heros.getY()]==':') heros.setX(-1);
			else if(kolizjoner[heros.getX()-1][heros.getY()]=='?') heros.setX(-1);
			else if(kolizjoner[heros.getX()-1][heros.getY()]=='N') heros.setX(-1);
		}
		else if(komenda_glowna=="z" || komenda_glowna=="Z"){	paragraph::wyjscie(); 	}
		else if(komenda_glowna=="i" || komenda_glowna=="I"){	heros.wyswietl_ekwipunek(); 	}
		else if(komenda_glowna=="p" || komenda_glowna=="P"){	paragraph::pomoc();		}
		else if(komenda_glowna=="v" || komenda_glowna=="V"){	paragraph::wersja_gry();		}
		else if(komenda_glowna=="j" || komenda_glowna=="J"){	dziennik.przegladaj_dziennik(0);		}
		
		int pozycja_cyfr; //SZUKANIE LICZB
		for (char liczby=48;liczby<=57;liczby++)
		{
			int pozc=komenda_glowna.find(liczby);
			if(pozc != std::string::npos)
			{
				pozycja_cyfr=pozc;
				std::string cyfra= komenda_glowna.substr(pozycja_cyfr,1);
				if(komenda_glowna==("ir"+cyfra) || komenda_glowna==("IR"+cyfra)) heros.usun_z_ekwipunek(cyfra);	
				if(komenda_glowna==("iu"+cyfra) || komenda_glowna==("IU"+cyfra)) heros.uzyj_z_ekwipunek(cyfra);
				if(komenda_glowna==("id"+cyfra) || komenda_glowna==("ID"+cyfra)) heros.opisz_z_ekwipunek(cyfra);
				if(komenda_glowna==("j"+cyfra)  || komenda_glowna==("J"+cyfra)) dziennik.przegladaj_dziennik(1);		
			}		
			else ;
		}
}

void gra::wczytaj_plik(char * nazwa) //wczytuje plik mapy swiatowej
{
	int a,b;
	std::ifstream plik;
	char pojer;
	strcpy(nazwa_lokacji,nazwa);
	std::string lokacja;
	lokacja=lokacja+nazwa;
	plik.open("maps/"+lokacja+".map"); 
	if( !plik.good() )
	{
		std::cout <<"B³¹d pliku w lokalizacji: maps/"<<nazwa<<".map."<<std::endl<<"Aplikacja zostanie zamknieta.";
	 	system("pause");
	 	exit(-1);
	} 
	for(a=0;a<max_dlug-1;a++)
	{
		for(b=0;b<max_szer-1;b++)	
		{
			plik >> pojer;
			if(pojer=='O') teren[a][b]=' ';
			else if(pojer=='&') 	teren[a][b]= '&';
			else if(pojer=='?') 	teren[a][b]= '?';
			else if(pojer=='%') 	teren[a][b]= '%';
			else if(pojer=='|') 	teren[a][b]= '|';
			else if(pojer=='+') 	teren[a][b]= '+';
			else if(pojer=='_') 	teren[a][b]='_';
			else if(pojer=='-') 	teren[a][b]='-';
			else if(pojer=='\'') 	teren[a][b]='\'';
			else if(pojer=='/') 	teren[a][b]='/';
			else if(pojer=='\\') 	teren[a][b]='\\';
			else if(pojer=='o') 	teren[a][b]='o';
			else if(pojer=='}') 	teren[a][b]='}';
			else if(pojer=='{') 	teren[a][b]='{';
			else if(pojer=='"') 	teren[a][b]='"';
			else if(pojer=='(') 	teren[a][b]='(';
			else if(pojer==')') 	teren[a][b]=')';
			else if(pojer=='=') 	teren[a][b]='=';
			else if(pojer=='^') 	teren[a][b]='^';
			else if(pojer==',') 	teren[a][b]=',';
			else if(pojer==';') 	teren[a][b]=';';
			else if(pojer=='.') 	teren[a][b]='.';
			else if(pojer=='X') 	teren[a][b]='X';
			else if(pojer=='T') 	teren[a][b]='T';
			else if(pojer=='U') 	teren[a][b]='U';
			else if(pojer==':') 	teren[a][b]=':';
			else if(pojer=='<') 	teren[a][b]='<';
			else if(pojer=='>') 	teren[a][b]='>';
			else if(pojer=='-') 	teren[a][b]='-';
			else if(pojer=='=') 	teren[a][b]='=';
			else if(pojer=='N') 	teren[a][b]='N';
			else if(pojer=='#') 	teren[a][b]='#';
		}
	}
}

void gra::wczytaj_obraz(std::string zwierze) //wczytuje plik obrazka
{
	int a,b;
	int dlugd=this->dlug-1;
	int szer_stan=this->szer+15;
	std::ifstream plik;
	char pojer;
	plik.open( "pictures/"+zwierze+".pic" );
	if( !plik.good() )
	{
		std::cout <<"B³¹d pliku "+zwierze+".pic"<<std::endl<<"Aplikacja zostanie zamknieta.";
		system("pause");
		exit(-1);
	} 
	for(a=0;a<14;a++)
	{
		for(b=0;b<28;b++)	
		{
			plik >> pojer;
			if(pojer=='O') 			mapa_lokalna[a][b]=' ';
			else if(pojer=='_') 	mapa_lokalna[a][b]='_';
			else if(pojer=='-') 	mapa_lokalna[a][b]='-';
			else if(pojer=='\'') 	mapa_lokalna[a][b]='\'';
			else if(pojer=='|') 	mapa_lokalna[a][b]='|';
			else if(pojer=='/') 	mapa_lokalna[a][b]='/';
			else if(pojer=='\\') 	mapa_lokalna[a][b]='\\';
			else if(pojer=='o') 	mapa_lokalna[a][b]='o';
			else if(pojer=='}') 	mapa_lokalna[a][b]='}';
			else if(pojer=='{') 	mapa_lokalna[a][b]='{';
			else if(pojer=='"') 	mapa_lokalna[a][b]='"';
			else if(pojer=='(') 	mapa_lokalna[a][b]='(';
			else if(pojer==')') 	mapa_lokalna[a][b]=')';
			else if(pojer=='=') 	mapa_lokalna[a][b]='=';
			else if(pojer=='^') 	mapa_lokalna[a][b]='^';
			else if(pojer==',') 	mapa_lokalna[a][b]=',';
			else if(pojer==';') 	mapa_lokalna[a][b]=';';
			else if(pojer=='.') 	mapa_lokalna[a][b]='.';
		}
	}
}

char** gra::get_mapa_lokalna()
{
	return teren;
}

int gra::sprawdz_uzytek(std::vector<przedmiot> plecak)
{
	int licznik=0,id_z=0;
	int dlug_e=plecak.size();
	if(plecak.empty()) return 0;
	else
	{
		int id_z=0,id_jz;
    	std::vector <przedmiot>::iterator it=plecak.begin();
    	for(;it<plecak.begin()+plecak.size()-1;it++) id_z++ ;
    			
    	for(id_jz;id_jz<dlug_e;id_jz++) if(plecak[id_jz].get_uzycie()=='+') return id_jz;
				
	}
}

int handel_barman(postac &heros,int wile,std::string komenda_glowna)
{
	zdarzenia los;
		while(1)
		{
			system("cls");
			std::cout <<"$ "<<heros.get_pieniadze()<<std::endl;
			std::cout <<"-----------------------------------------------------------------"<<std::endl;
			los.barman_zakupy();
			std::cout <<"-----------------------------------------------------------------"<<std::endl;
			std::cout <<"Wydaj polecenie:"<<"->";
			std::cin >> komenda_glowna;
			if(komenda_glowna=="1")
				{
					if(heros.get_pieniadze()>=10)
						{
							heros.set_pieniadze(heros.get_pieniadze()-10);
							przedmiot mikstura_zycia(20, "Mikstura zycia	",' ',mikstura,0,"  Mikstura regenerujaca 50 punktow zdrowia.\n\n");
							heros.dod_ekwipunek(mikstura_zycia);
							system("cls");
							std::cout <<"-----------------------------------------------------------------"<<std::endl;
							los.barman_zakupy();	
						}
						else los.barman_zakupy_fail();
				}
			else if(komenda_glowna=="2")
				{
					if(heros.get_pieniadze()>=25)
						{
							heros.set_pieniadze(heros.get_pieniadze()-25);
							przedmiot dmiecz(40, "Dlugi miecz     	",' ',bron,22,"  Swietna bron na ciezki zywot \n\n  OBRAZENIA: 22\n\n");
							heros.dod_ekwipunek(dmiecz);
							system("cls");
							std::cout <<"-----------------------------------------------------------------"<<std::endl;
							los.barman_zakupy();
						}
						else los.barman_zakupy_fail();
				}
			else if(komenda_glowna=="3") break;
		}
	return 0;	
}

int walka_z_wrogiem(postac & heros,int tryb)
{	
	int wybor,los_zdarzenia,licznik_konsola=0;
	int obrazenia_broni_herosa,heros_trafienie_wroga,wrog_trafienie_herosa;
	std::string komendy_a;
	char znak,zdrowko=3;
	zdarzenia los_bohatera;
	walka pojedyn;
	std::cout <<"-----------------------------------------------------------------"<<std::endl;
	bestia *odpb,wilus(25,1,"wilk",15),szczurus(15,1,"szczur",10);
	if(tryb==1)
	{ 
		odpb=&wilus;
		std::cout <<"Na swojej drodze spotkalem wilka"<<std::endl;
	}
	if(tryb==2)
	{
		odpb=&szczurus;
		std::cout <<"Na swojej drodze spotkalem szczura"<<std::endl;
	}
	std::cout <<"Czas na pojedynek"<<std::endl;
	Sleep(300);
	system("pause");
		while(1)
		{
			std::cout <<heros.get_imie()<<" " <<zdrowko<<" "<<heros.get_zycie()<<std::endl;
			std::cout <<odpb->daj_nazwa()<<" " <<zdrowko<<" "<<odpb->daj_zdrowie()<<std::endl;
			if(heros.podaj_z_ekwipunek_gotowa_bron('+')!=0) //sprawdzamy czy w ekwipunku mamy bron w uzyciu
			{
				obrazenia_broni_herosa=(heros.get_sila()/3)+heros.podaj_z_ekwipunek_gotowa_bron('+');
			}
			else obrazenia_broni_herosa=heros.get_sila();
			int heros_trafienie_wroga=( std::rand() %  obrazenia_broni_herosa) + 1;
			int wrog_trafienie_herosa=( std::rand() %  odpb->daj_obrazenia()) + 1;
			los_zdarzenia=( std::rand() % 3 ) + 1;
			if(komendy_a=="r"||komendy_a=="R")
			{
				
				if(los_zdarzenia==0 || los_zdarzenia==1)
				{
					std::cout <<"|== "<<heros.get_imie()<<" atakuje "<<odpb->daj_nazwa() <<"a- "<<odpb->daj_nazwa() <<" traci "<< heros_trafienie_wroga<<" pkt. zycia"<<std::endl;
					odpb->set_zycie(-heros_trafienie_wroga);
				}
				else if(los_zdarzenia==2|| los_zdarzenia==3 )
				{
					std::cout <<"|== "<<odpb->daj_nazwa() <<" robi kuku "<<heros.get_imie()<<"- ten traci "<< wrog_trafienie_herosa<<" pkt. zycia"<<std::endl;
					heros.set_zytko(-wrog_trafienie_herosa);
				}
				else if(los_zdarzenia>=4 )
				{
					std::cout <<"|== Mignelismy sie w ataku"<<std::endl;
				}
				
				if(heros.get_zycie()<=0)
				{
					std::cout <<"|== Bohater zgin¹³- KONIEC GRY"<<std::endl;
					Sleep(300);
					system("pause");
					exit(1);
				}
				if(odpb->daj_zdrowie()<=0)
				{
					std::cout <<"|== "<<odpb->daj_nazwa() <<" polegl z reki "<<heros.get_imie()<<std::endl;
					if(tryb==1)
					{
						std::cout <<"+5 szt zlota !!!"<<std::endl;
						heros.set_pieniadze(heros.get_pieniadze()+5);
						std::cout <<"+25 PUNKTOW DOSWIADCZENIA !!!"<<std::endl;
						heros.set_doswiadczenie(heros.get_doswiadczenie()+25);
						
					} 
					else if(tryb==2)
					{
						std::cout <<"+2 szt zlota !!!"<<std::endl;
						heros.set_pieniadze(heros.get_pieniadze()+2);
						std::cout <<"+10 PUNKTOW DOSWIADCZENIA !!!"<<std::endl;	
						heros.set_doswiadczenie(heros.get_doswiadczenie()+10);	
					}
					system("pause");
					system("cls"); 
					return 0;
				}			
			}
			else if(komendy_a=="d"||komendy_a=="D")
			{
				int obrona=(std::rand() % 200)+0;
				if(los_zdarzenia==2|| los_zdarzenia==3 )
				{
					if(obrona<=90)
					{
						std::cout<<"Nieudana obrona w walce!"<<std::endl;
						std::cout <<"|== "<<odpb->daj_nazwa() <<" robi kuku "<<heros.get_imie()<<"- ten traci "<< wrog_trafienie_herosa<<" pkt. zycia"<<std::endl;
						heros.set_zytko(-wrog_trafienie_herosa);
					}
					else
					{
						std::cout<<"Uda³o ci siê obronic w walce!";
						std::cout <<"|== "<<heros.get_imie()<<" atakuje "<<odpb->daj_nazwa() <<"a- "<<odpb->daj_nazwa() <<" traci "<< heros_trafienie_wroga<<" pkt. zycia"<<std::endl;
						odpb->set_zycie(-heros_trafienie_wroga/4);
					}
				}
			}
			else if(komendy_a=="u"||komendy_a=="U")
			{
				int ucieczka=(std::rand() % 400)+0;
				if(ucieczka<=130)
				{
					std::cout<<"Uda³o ci siê uciec z pola walki!";
					break;
				}
				else
				{
					std::cout<<"|== Ucieczka zakoñczona fiaskiem!"<<std::endl;
					if(los_zdarzenia==2)
					{
						std::cout <<"|== "<<odpb->daj_nazwa() <<" robi kuku "<<heros.get_imie()<<"- ten traci "<< wrog_trafienie_herosa<<" pkt. zycia"<<std::endl;
						heros.set_zytko(-wrog_trafienie_herosa);
					}
					else ;
				} 
			}
			else if(komendy_a=="i"||komendy_a=="I") std::cout<<"Nie mo¿na przegladac ekwipunku w trakcie walki"<<std::endl;
			else if(komendy_a=="p"||komendy_a=="P") paragraph::pomoc();
			else komendy_a="g";
			std::cout <<"-----------------------------------------------------------------"<<std::endl;
			std::cout <<"Wydaj polecenie:"<<"->";
			std::cin >> komendy_a;
			system("cls");
		}
		system("pause");	
		std::cout <<"-----------------------------------------------------------------"<<std::endl;
}

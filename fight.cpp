#include "fight.h"


int walka::pojedynek_ze_szczurem(postac & heros)
{
	int wybor;
	system("cls");
	std::cout <<"Na swojej drodze spotkalem szczura"<<std::endl;
	std::cout <<"Czas na pojedynek"<<std::endl;
	system("pause");
	std::cout <<"1.Atakuj"<<std::endl;
	std::cout <<"2.Ucieczka jak premier do Brukseli"<<std::endl;
	std::cout <<"3.Obrona -domyslnie Atakuj"<<std::endl;
	return 0;
	/*while(1)
	{
		std::cin  >> wybor;
		if(wybor==1);
		else if(wybor==2);
		else wybor=1;
	}*/
}

int walka::pojedynek_z_wilkiem(postac & heros)
{
	int wybor,los_zdarzenia,trafienie;
	//wrog wilk(1,100,1);
	system("cls");
	std::cout <<"Na swojej drodze spotkalem wilka"<<std::endl;
	std::cout <<"Czas na pojedynek"<<std::endl;
	system("pause");
	std::cout <<"1.Atakuj"<<std::endl;
	std::cout <<"2.Ucieczka jak premier do Brukseli"<<std::endl;
	std::cout <<"3.Obrona -domyslnie Atakuj"<<std::endl;
	/*while(1)
	{
		std::cin >> wybor;
		if(wybor==1)
		{
			trafienie= (std::rand() % 10 ) + 1;
			los_zdarzenia=( std::rand() % 10 ) + 1;
			if(los_zdarzenia==0 || los_zdarzenia==1 )
			{
				std::cout <<heros.get_imie()<<" atakuje wilka- wilk traci"<< trafienie;
			}
			else if(los_zdarzenia==2|| los_zdarzenia==3 )
			{
				std::cout <<"Wilk robi kuku"<<heros.get_imie()<<" i traci"<< trafienie;
				heros.set_zycie(-trafienie);
			}
			else if(los_zdarzenia>=4 )
			{
				std::cout <<"Mignelismy sie w ataku"<< trafienie;
				heros.set_zycie(-trafienie);
			}
			if(heros.daj_stan()==0)
			{
				std::cout <<"Bohater zgin¹³- KONIEC GRY"<<std::endl;
				exit(1);
			}
		}
		else if(wybor==2);
		else wybor=1;
	}
	return 0;
}

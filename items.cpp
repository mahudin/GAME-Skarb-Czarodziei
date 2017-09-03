#include <iostream>
#include <cstdlib>
#include <cstring>
#include "items.h"

int przedmiot::daj_obrazenia(){return obrazenka;};
unsigned int przedmiot::get_wartosc(){return wartosc;};
void przedmiot::set_wartosc(int wartos){this->wartosc=wartos;};
void przedmiot::set_uzycie(char uzyt){this->uzycie=uzyt;};
char przedmiot::get_uzycie(){return uzycie;};
typ_p przedmiot::get_rodzaj(){return rodzaj;};
std::string przedmiot::get_nazwa(){return nazwa;};
std::string przedmiot::get_opis(){return opis;};

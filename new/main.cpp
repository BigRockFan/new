/*
Code written by Rohan Putcha
*/
#include "entity.h"

int main()
{
	entity guy = *new entity(4, 12, 9, "Rohan"); //attack, health, magic, name
	entity minion = *new entity(2, 10, "Minion"); //attack, health, name
	guy.battle(minion);
	return 0;
}
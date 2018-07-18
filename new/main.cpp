/*
Code written by Rohan Putcha
*/
#include "entity.h"

entity setup();
entity PartOne(entity);

int main()
{
	entity player = setup();
	player = PartOne(player);
}

entity setup()
{
	string yourname, pn;
	int gender = 2;
	cout << "Enter your character's name: ";
	cin >> yourname;
	while (gender != 1 && gender != 0)
	{
		cout << "\nEnter your character's gender (Male = 0, Female = 1): ";
		cin >> gender;
	}
	if (gender == 1) { pn = "her"; }
	else { pn = "his"; }

	entity player = *new entity(4, 12, 8, yourname, pn); //attack, health, magic, name, pronoun
	return player;
}

entity PartOne(entity player)
{
	cout << "Wandering the forest, " << player.GetName() << " suddenly notices a man approaching. He wore a uniform showing he was a minion of the king.\n";
	cout << "Immediately, " << player.GetName() << " draws " << player.GetPronoun() << " sword and so does the minion.\n\n";
	entity minion = *new entity(2, 10, "Minion"); //attack, health, name
	player.battle(minion);

	return player;
}
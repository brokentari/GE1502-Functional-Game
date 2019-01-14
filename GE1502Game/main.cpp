#include <iostream>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <string>

using namespace std;

int attack(int);
int heal(int);
int summon(int);
int powerUp(int);

int main() {
	srand(time(0));
	string combatChoices[] = { "Attack", "Heal", "Summon", "Power Up" };
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	cout << "-----------------------------------------------------------------------------------------------------------------------------------";
	cout << "\n                                                    PRESS F11 FOR FULLSCREN                                                  \n\n";
	cout << "\n     WELCOME TO THE COLESSEUM! AFTER CRAWLING AND FIGHTING THROUGH DOZENS OF CONTESTANTS, YOU HAVE ARRIVED AT THE FINAL ROUND!\n\n";
	cout << "           SINCE THE EMPEROR WOULD RATHER NOT HAVE A NOBODY WIN AT HIS GAME, HE DECIDED TO CHANGE YOUR FINAL OPPONENT!\n\n";
	cout << "               DUE TO A RECENT EXPEDITION, THE ROMANS WERE ABLE TO CAPTURE ONE OF THE GORGONS, A SISTER OF MEDUSA!\n\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";

	int enemyHP = rand() % 20 + 30;
	int playerHP = 20;
	int playerChoice;
	int attackMultiplier = 0;

	while (enemyHP > 0 && playerHP > 0) {
		cout << "\nYou currently have " << playerHP << "HP." << endl;
		cout << "Enter your combat choice: \n";
		for (int i = 1; i <= 4; i++)
		{
			cout << i << ") " << combatChoices[i - 1] << endl;
		}

		cin >> playerChoice;
		cout << endl;

		switch (playerChoice) {
		case 1:
			enemyHP = attack(enemyHP) - attackMultiplier;
			break;
		case 2:
			playerHP = heal(playerHP);
			break;
		case 3:
			enemyHP = summon(enemyHP);
			break;
		case 4:
			attackMultiplier = powerUp(attackMultiplier);
			break;
		default:
			cout << "You stood around in confusion. You took damage while not dealing damage any to the monster. Hopefully you can come back from this" << endl;
			break;
		}
		int enemyAttack = rand() % 6 + 1;
		playerHP = playerHP - enemyAttack;
		cout << "The gorgon lunged at you. Without much time to react you took " << enemyAttack << " damage" << endl;

	}
	if (enemyHP <= 0)
		cout << "Congralutaions! You have defeated the gorgon and demostrated your power to the Roman empire! As a spoils of wars, you decide to take the gorgon's head, just as Perseus did when he defeated Medusa, and place it right in the middle of your shield." << endl;
	else if (playerHP <= 0)
	{
		cout << "Pathetic! Your incompetence was the cause of your own demise. May Pluto have mercy on you." << endl;
	}
}

int attack(int enemyCurrHealth) {
	int damage = rand() % 6 + 1;
	cout << "You swung your sword at the gorgon! You dealt " << damage << " damage!" << endl;
	if (enemyCurrHealth < 10) {
		cout << "The gorgon is nearly dead. Finish it off!" << endl;
	}
	return enemyCurrHealth - damage;
};

int heal(int playerCurrHealth) {
	int heal = rand() % 8 + 2;
	int tempHealth;
	if (playerCurrHealth == 20) {
		cout << "You are at max health. You do not need to heal." << endl;
	}
	else {
		 tempHealth = playerCurrHealth;
		playerCurrHealth = playerCurrHealth + heal;
		if (playerCurrHealth > 20) {
			int spilledHealth = playerCurrHealth - 20;
			playerCurrHealth = playerCurrHealth - spilledHealth;
		}
	}
	cout << "You wrapped up some bandages around your cuts. You healed " << (playerCurrHealth - tempHealth) << "HP." << endl;
	return playerCurrHealth;
}

int summon(int enemyCurrHealth) {
	int summonAttack = rand() % 12 + 4;
	cout << "\nWith the blessing of Neptune, he sends his son, the flying Horse, Pegasus, to aid you in this battle. As Pegasus comes flying from the blue, clear sky, he tackles the gorgon, dealing " << summonAttack << " damage!" << endl;

	return enemyCurrHealth - summonAttack;
}

int powerUp(int currMultiplier) {
	int newMultiplier = currMultiplier + 2;
	cout << "\nMars, God of War, bless me in this fight. You will deal +" << newMultiplier << " damage next attack!" << endl;
	return newMultiplier;
}



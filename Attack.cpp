//Attack in C++
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>

using namespace std;
int main(){
    srand (time(NULL));
    cout << "Attack" << endl;
	cout << "Instructions: fight the enemy until you or he dies." << endl;
	cout << "SAVING IS BROKEN, SORRY! :(" << endl;
	cout << "Version 0.1" << endl;
	bool done;
	int lvl,health,enemy,dollas,med,nrg,attack1,attack2,attack3,attack4,ai_attack1,ai_attack2,ai_attack3,ai_attack4,ai_nrg,ai_med,turn,bank,kills,xp,xplevel,healthmod;
	int attack_number,hhit_attack,nrm_attack,spcl_attack,item_number,buy_number,nrg_price,nrg_num,med_price,med_num,heal_price;
	float percent;
	int input1;
	done = false;
	lvl=0;
	health=100;
	enemy=100;
	dollas=0;
	med=5;
	nrg=3;
	attack1=10;
	attack2=30;
	attack3=30;
	attack4=5;
	ai_attack1=10;
	ai_attack2=30;
	ai_attack3=30;
	ai_attack4=5;
	ai_nrg=3;
	ai_med=5;
	turn=1;
	bank=0;
	kills=0;
	xp=0;
	xplevel=50;
	//load
	healthmod=25*lvl;
	health+=healthmod;
	if (health > 100+healthmod){
		health=100+healthmod;
		enemy=100;
	}
	if ((attack1 > 10) || (attack2 > 30) || (attack3 > 30) || (attack4 > 5)){
        attack1=10;
		attack2=30;
		attack3=30;
		attack4=5;
		ai_attack1=10;
		ai_attack2=30;
		ai_attack3=30;
		ai_attack4=5;
    }
	while (done == false){
		while ((health > 0) && (enemy > 0)){
			while (turn == 1){
                int random_number;
				random_number = rand() % 100 + 1;
				if (xp >= xplevel){
					lvl+=1;
					xp-=xplevel;
					Sleep(10);
					xplevel=xplevel+35+(5*lvl);
				}
				cout << "Hi! Stats:" << endl;
				cout << "Your health is: " << health << endl;
				cout << "The enemy's health is: " << enemy << endl;
				cout << "You're at level " << lvl << endl;
				cout << "You have "<< xp << "/" << xplevel << " xp" << endl;
				percent = xp/xplevel;
				percent = /*static_cast<int>*/(percent*100.0+0.5) / 100.0;
				percent = percent*100;
				if (percent > 90)
					cout << "<---------|>" << endl;
				else if ((percent > 80) && (percent <= 90))
					cout << "<--------|->" << endl;
				else if ((percent > 70) && (percent <= 80))
					cout << "<-------|-->" << endl;
				else if ((percent > 60) && (percent <= 70))
					cout << "<------|--->" << endl;
				else if ((percent > 50) && (percent <= 60))
					cout << "<-----|---->" << endl;
				else if ((percent > 40) && (percent <= 50))
					cout << "<----|----->" << endl;
				else if ((percent > 30) && (percent <= 40))
					cout << "<---|------>" << endl;
				else if ((percent > 20) && (percent <= 30))
					cout << "<--|------->" << endl;
				else if ((percent > 10) && (percent <= 20))
					cout << "<-|-------->" << endl;
				else if ((percent > 0) && (percent <= 10))
                    cout << "<|--------->" << endl;
				cout << "You have " << dollas << " dollars" << endl;
				cout << "You have " << bank << " dollars in your bank" << endl;
				cout << "You have " << med << " medpacks" << endl;
				cout << "You have " << nrg << " NRG drinks" << endl;
				cout << "You have " << attack1 << " energy for attack 1" << endl;
				cout << "You have " << attack2 << " energy for attack 2" << endl;
				cout << "You have " << attack3 << " energy for attack 3" << endl;
				cout << "You have " << attack4 << " energy for attack 4" << endl;
				cout << "You killed " << kills << " people" << endl;
				//save
				cout << "1. attack, 2. use items, 3. buy, or 4. exit: " << endl;
				input1 = getch();
				if (input1 == 49){
					// clr()

					cout << "What attack would you want to use? (any other number to go back) " << endl;
					cout << "Backup -- Uses: " << attack1 << endl;
					cout << "Hard-hitting -- Uses: " << attack2 << endl;
                    cout << "Normal -- Uses: " << attack3 << endl;
					cout << "Special -- Uses: " << attack4 << endl;
					cin >> attack_number;
					if ((attack_number == 1) && (attack1 < 1))
						cout << "No more uses!";
					else if ((attack_number == 2) && (attack2 < 1))
						cout << "No more uses!";
					else if ((attack_number == 3) && (attack3 < 1))
						cout << "No more uses!";
					else if ((attack_number == 4) && (attack4 < 1))
						cout << "No more uses!";
					else if ((attack_number == 1) && (attack1 >= 1))
						// clr()
						if ((random_number < 80) && (random_number >= 1)){
							cout << "You hit him with your backup attack!" << endl;
							enemy = enemy - 5;
							cout << "It caused 5 damage!" << endl;
							attack1-=1;
							turn = 0;
						}
						else if (random_number >= 80){
							cout << "You missed!" << endl;
							attack1-=1;
							turn = 0;
						}
					else if ((attack_number == 2) && (attack2 >= 1)){
						// clr()
						if ((random_number < 40) && (random_number >= 1)){
							hhit_attack = rand() % 16 + 35; //random.randint(35, 50)
							cout << "You hit him with your hard-hitting attack!" << endl;
							enemy = enemy - hhit_attack;
							cout << "It caused " << hhit_attack << " damage!" << endl;
							attack2-=1;
							turn = 0;
                        }
						else if (random_number >= 40){
							cout << "You missed!" << endl;
							attack2-=1;
							turn = 0;
						}
					}
					else if ((attack_number == 3) && (attack3 >= 1)){
						// clr()
						if ((random_number < 60) && (random_number >= 1)){
							nrm_attack = rand() % 11 + 10; //random.randint(10, 20)
							cout << "You hit him with your normal attack!" << endl;
							enemy = enemy - nrm_attack;
							cout << "It caused " << nrm_attack << " damage!" << endl;
							attack3-=1;
							turn = 0;
						}
						else if (random_number >= 60){
							cout << "You missed!" << endl;
							attack3-=1;
							turn = 0;
                        }
					}
                    else if ((attack_number == 4) && (attack4 >= 1)){
                        // clr()
						if ((random_number < 20) && (random_number >= 1)){
                            spcl_attack = rand() % 16 + 60; //random.randint(60, 75)
							cout << "You hit him with your special attack!" << endl;
							enemy = enemy - spcl_attack;
							cout << "It caused " << spcl_attack << " damage!" << endl;
							attack4-=1;
							turn = 0;
						}
						else if (random_number >= 20){
                            cout << "You missed!\n" << endl;
							attack4-=1;
							turn = 0;
						}
                    }
				}
				else if (input1 == 50){
					// clr()
					cout << "What item will you use? (any other number to go back)" << endl;
					cout << "1. NRG drink (energy)" << endl;
					cout << "2. Medpack" << endl;
                    cout << " > " << endl;
                    item_number = getch();

					if (item_number == 49){
						// clr()
						cout << "You tried to drink an NRG drink!" << endl;
						if ((random_number <= 60) && (random_number >= 1) && (nrg > 0)){
							cout << "You restored your energy!" << endl;
							attack1 = 10;
							attack2 = 30;
							attack3 = 30;
							attack4 = 5;
							nrg -= 1;
							turn = 0;
						}
						else if ((random_number > 60) || (nrg <= 0) || (attack1 == 10) || (attack2 == 30) || (attack3 == 30) || (attack4 == 10)){
							cout << "You failed to drink an NRG drink!" << endl;
							turn = 0;
						}
					}
					else if (item_number == 50){
						// clr()
						cout << "You tried to heal!" << endl;
						if ((random_number <= 80) && (random_number >= 1) && (health < 100+healthmod) && (med > 0)){
							cout << "You healed up!" << endl;
							health += 25;
							med -= 1;
							cout << "You have " << med << " more medpacks" << endl;
							turn = 0;
                        }
						else if ((random_number > 80) || (med <= 0) || (health >= 100+healthmod)){
							cout << "You failed to heal!" << endl;
							cout << "You have " + med << " more medpacks" << endl;
							turn = 0;
						}
					}
				}
				else if (input1 == 51){
					// clr()
					cout << "Buy what? (any other number to go back)" << endl;
					cout << "1. NRG drink (energy): 50 dollars" << endl;
					cout << "2. Medpack: 50 dollars" << endl;
					cout << "3. Full heal: 250 dollars" << endl;
					buy_number = getch();
					if (buy_number == 49){
						nrg_price = 50;
						cout << "How many?: " << endl;
						cin >> nrg_num;
						if (nrg_price * nrg_num > dollas)
							cout << "Not enough money!" << endl;
						else if (nrg_price * nrg_num <= dollas){
							dollas = dollas - (nrg_price * nrg_num);
							nrg = nrg + nrg_num;
						}
                    }
					else if (buy_number == 50){
						med_price = 50;
						cout << "How many?: " << endl;
						cin >> med_num;
						if (med_price * med_num > dollas)
							cout << "Not enough money" << endl;
						else if (med_price * med_num <= dollas){
							dollas = dollas - (med_price * med_num);
							med = med + med_num;
						}
					}
					else if (buy_number == 51){
						heal_price = 250;
						if (heal_price > dollas)
							cout << "Not enough money!" << endl;
						else if (heal_price <= dollas){
							dollas = dollas - heal_price;
							health = 100+healthmod;
							cout << "You used a full heal!" << endl;
						}
						turn = 0;
                    }
				else if (input1 == 52){
                    // clr()
					cout << "Bye!" << endl;
					system("pause");
					exit(0);
				}
            }
			while (turn == 0){
				ai_number = random.randint(1, 2)
				ai_attack = random.randint(1, 4)
				ai_item = random.randint(1, 2)
				event = random.randint(1, 100)
				if (ai_number == 1){
                    if ((ai_attack == 1) && (ai_attack1 < 1)){
						Sleep(10);
						turn = 0;
                    }
					else if ((ai_attack == 2) && (ai_attack2 < 1)){
						Sleep(10);
						turn = 0;
					}
					else if ((ai_attack == 3) && (ai_attack3 < 1)){
						Sleep(10);
						turn = 0;
                    }
					else if ((ai_attack == 4) && (ai_attack4 < 1) && (enemy > 15)){
						Sleep(10);
						turn = 0;
					}
					else if ai_attack == 1 && ai_attack1 >= 1 && ai_attack2 == 0 && ai_attack3 == 0 && ai_attack4 == 0:
						if event < 80 && event >= 1:
							cout << "He hit you with his backup attack!")
							health = health - 5
							cout << "It caused 5 damage!")
							ai_attack1-=1
							turn = 1
						else if event >= 80:
							cout << "He missed!")
							ai_attack1-=1
							turn = 1
					else if ai_attack == 2 && ai_attack2 >= 1:
						if event < 40 && event >= 1:
							ai_hhit_attack = random.randint(35, 50)
							cout << "He hit you with his hard-hitting attack!")
							health = health - ai_hhit_attack
							cout << "It caused " + str(ai_hhit_attack) + " damage!")
							ai_attack2-=1
							turn = 1
						else if event >= 40:
							cout << "He missed!")
							ai_attack2-=1
							turn = 1
					else if ai_attack == 3 && ai_attack3 >= 1:
						if event < 60 && event >= 1:
							ai_nrm_attack = random.randint(10, 20)
							cout << "He hit you with his normal attack!")
							health = health - ai_nrm_attack
							cout << "It caused " + str(ai_nrm_attack) + " damage!")
							ai_attack3-=1
							turn = 1
						else if event >= 60:
							cout << "He missed!")
							ai_attack3-=1
							turn = 1
					else if ai_attack == 4 && ai_attack4 >= 1 && enemy <= 15:
						if event < 20 && event >= 1:
							ai_spcl_attack = random.randint(60, 75)
							cout << "He hit you with his special attack!")
							health = health - ai_spcl_attack
							cout << "It caused " + str(ai_spcl_attack) + " damage!")
							ai_attack4-=1
							turn = 1
						else if event >= 20:
							cout << "He missed!")
							ai_attack4-=1
							turn = 1
				}
				else if ai_number == 2 && enemy <= 15 && ai_med > 0 && ai_item == 1 && enemy <= 15:
					ai_med -= 1
					enemy += 25
					turn = 1
				else if ai_number == 2 && ai_nrg > 0 && ai_item == 2 && attack1 == 0 && attack2 == 0 && attack3 == 0 && attack4 == 0:
					ai_nrg -= 1;
					ai_attack1 = 10;
					ai_attack2 = 30;
					ai_attack3 = 30;
					ai_attack4 = 5;
					turn = 1;
				else if ai_number == 2:
                    Sleep(10);
					turn = 0;
			}
        }
		if health <= 0 && bank >= -500{
			cout << "You blacked out!" << endl;
			cout << "The hospital healed you back up!" << endl;
			health=100;
			enemy=100;
			dollas=0;
			med=5;
			nrg=3;
			attack1=10;
			attack2=30;
			attack3=30;
			attack4=5;
			ai_attack1=10;
			ai_attack2=30;
			ai_attack3=30;
			ai_attack4=5;
			ai_nrg=3;
			ai_med=5;
			turn=1;
			bank = bank - 250;
			/*
			save1(health)
			save2(enemy)
			save2(dollas)
			save2(med)
			save2(nrg)
			save2(attack1)
			save2(attack2)
			save2(attack3)
			save2(attack4)
			save2(ai_attack1)
			save2(ai_attack2)
			save2(ai_attack3)
			save2(ai_attack4)
			save2(ai_nrg)
			save2(ai_med)
			save2(turn)
			save2(bank)
			save2(kills)
			save2(xp)
			save2(lvl)
			save2(xplevel)
			*/
			health=health+healthmod;
		}
		else if lvl >= 50:
			cout << "You win!")
			cout << "Game over!")
			health=100
			enemy=100
			dollas=0
			med=5
			nrg=3
			attack1=10
			attack2=30
			attack3=30
			attack4=5
			ai_attack1=10
			ai_attack2=30
			ai_attack3=30
			ai_attack4=5
			ai_nrg=3
			ai_med=5
			turn=1
			bank=0
			kills=0
			xp=0
			lvl=0
			xplevel=50
			amazingfeat=9001
			save1(health)
			save2(enemy)
			save2(dollas)
			save2(med)
			save2(nrg)
			save2(attack1)
			save2(attack2)
			save2(attack3)
			save2(attack4)
			save2(ai_attack1)
			save2(ai_attack2)
			save2(ai_attack3)
			save2(ai_attack4)
			save2(ai_nrg)
			save2(ai_med)
			save2(turn)
			save2(bank)
			save2(kills)
			save2(xp)
			save2(lvl)
			save2(xplevel)
			save2(amazingfeat)
			end()
		else if enemy <= 0 && health > 0:
			cout << "You killed him!")
			mons=random.randint(600,1000)
			xpadd=random.randint(20,30)
			cout << "You gained " + str(mons) + " money!")
			cout << "You gained " + str(xpadd) + " xp!")
			cout << "Another person approaches you!")
			enemy=100
			dollas=dollas+mons
			ai_attack1=10
			ai_attack2=30
			ai_attack3=30
			ai_attack4=5
			ai_nrg=3
			ai_med=5
			turn=1
			kills=kills+1
			xp=xp+xpadd
			save1(health)
			save2(enemy)
			save2(dollas)
			save2(med)
			save2(nrg)
			save2(attack1)
			save2(attack2)
			save2(attack3)
			save2(attack4)
			save2(ai_attack1)
			save2(ai_attack2)
			save2(ai_attack3)
			save2(ai_attack4)
			save2(ai_nrg)
			save2(ai_med)
			save2(turn)
			save2(bank)
			save2(kills)
			save2(xp)
			save2(lvl)
			save2(xplevel)
			enter()
			binp = input("Do you want to bank your money? (1/0): ")
			try:
				binp = int(binp)
			except ValueError:
				// clr()
				cout << "Number please!")
				binp=1
			if binp == 1:
				// clr()
				dorw = input("Deposit or withdraw? (1/2): ")
				try:
					dorw = int(dorw)
				except ValueError:
					// clr()
					cout << "Number please!")
					dorw=1
				if dorw == 1:
					// clr()
					cout << "You have {:} dollars".format(dollas))
					cout << "You have {:} dollars in your bank".format(bank))
					recdep = dollas - 500
					cout << "It's recommended to deposit " + str(recdep) + " dollars for full heal use.")
					depamt = input("How much?: ")
					// clr()
					try:
						depamt = int(depamt)
					except ValueError:
						depamt=recdep
					if depamt>dollas:
						cout << "Too much! Depositing all!")
						cout << "Depositing money...")
						bank=bank+dollas
						bank=bank-15
						dollas=0
					else:
						dollas=dollas-depamt
						cout << "Depositing money...")
						bank=bank+depamt
						bank=bank-15
				else if dorw == 2:
					// clr()
					cout << "You have {:} dollars".format(dollas))
					cout << "You have {:} dollars in your bank".format(bank))
					recwth = 500 - dollas
					cout << "It's recommended to withdraw " + str(recwth) + " dollars for full heal use (if the number's negative disregard)")
					wthamt = input("How much?: ")
					// clr()
					try:
						wthamt = int(wthamt)
					except ValueError:
						// clr()
						cout << "Number please!")
					if wthamt>bank:
						cout << "Too much! Withdrawing all!")
						cout << "Withdrawing money...")
						dollas=dollas+bank
						bank=0
					else:
						bank=bank-wthamt
						cout << "Withdrawing money...")
						dollas=dollas+wthamt
			else:
				cout << "OK!")
		else if health <= 0 && enemy > 0 && bank < -500:
			cout << "You died!")
			cout << "No money!")
			cout << "Game over!")
			health=100
			enemy=100
			dollas=0
			med=5
			nrg=3
			attack1=10
			attack2=30
			attack3=30
			attack4=5
			ai_attack1=10
			ai_attack2=30
			ai_attack3=30
			ai_attack4=5
			ai_nrg=3
			ai_med=5
			turn=1
			bank=0
			kills=0
			xp=0
			lvl=0
			xplevel=50
			save1(health)
			save2(enemy)
			save2(dollas)
			save2(med)
			save2(nrg)
			save2(attack1)
			save2(attack2)
			save2(attack3)
			save2(attack4)
			save2(ai_attack1)
			save2(ai_attack2)
			save2(ai_attack3)
			save2(ai_attack4)
			save2(ai_nrg)
			save2(ai_med)
			save2(turn)
			save2(bank)
			save2(kills)
			save2(xp)
			save2(lvl)
			save2(xplevel)
			end()
	}
}

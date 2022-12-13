#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Team 20 Simon Accamando, Kyle Kessler, Louis Sauter
//The goal of this game is to create an experience like Oregon trail, 
//where the user is able to interact with the game as to complete an end goal.
//Unlike the Oregon trail, we have created different smaller adventures for the user to experience.





/*Game- Oregon trail type adventure game

Main--access fun1
	 

fun1--gets user name, checks.
* switch case for which adventure to take                          		Switch Case
	array contains locations
	possible ask what kind of adventure to take

fun2--inventory array,													purchase looping
	needs to apply to which ever adventure is chosen
	
fun3--options for the adventure,										application loops
	needs to apply to which ever adventure is chose

fun4-1st round of choices											    Switch case	-with imbeded loops and switch cases


fun5--store pt ( 2)final decisions and end message to the game			
	
*/
//Functions:

char fun1(char player[30],int array1[30]); //gets name
int fun2(char player[30],int array1[30]);  //gets journey type
int fun3(char player[30],int array1[30],int journey); //store interaction 1
int fun4(char player[30],int array1[30],int journey); //pathing choices
int fun5(char name[30],int array[30],int trip); //store interaction 2

//Main function
int main(){
	
	char player[30];
	int journey, array1[30],path[30];
	array1[4]=1;
	while (array1[4]==1){
	player[30] = fun1(player,array1); //gets name, returns name
	//printf(" %s",player);
	journey = fun2(player,array1); //passes in name, gets adventure type out
	//printf(" %d",journey);
	array1[30]=fun3(player,array1,journey);//passes in name and inventory array, and journey selected gets inventory and curency out 
	//printf("%d, %d",array1[0],array1[1]);
	path[30]=fun4(player,array1,journey);//passes in the name and inventoroy array, and journey selected gets results out (fun5 in fun4)

		/*while(array1[4]!=1){
			printf("But you want to go again?\n(1)yes\(2)no\t");
			scanf(" %d", array1[4]);
			while (array1[4]!=1&&array1[4]!=2){
				printf("Error!! Please select one of the predefined options...\nAre you sure you don't want to go again?\n(1)yes\n(2)no\t");
				scanf(" %d", array1[4]);
			}
	}*/
}
	return 0;

}

//function 1: gets name of player, checks if name is correct, and error checks the inputs.
//A switch case runs and decides which adventure to take, the choice is then returned to the main
char fun1(char  name[],int array[]){
	if (array[4]==1){
	char check1;
	//char name[30];
	
	printf("Welcome to Team 20's Adventure game,\nIn this game you play as experienced adventurer, who are attepting great expeditions.\nBefore we begin any expiditions, what would you like to be called during your experience?\n(Please enter your name with no spaces)\n");
	scanf(" %s", &name[0]);
	printf("\nYou will be called %s",&name[0]);
	printf(" is this correct? (y)yes (n)no\n");
	scanf(" %c", &check1);
	while (check1!='y' && check1!='n'&& check1!='Y' && check1!='N'){
		printf("\nError!!\tThat was not an option, please enter one of the options provided");
		printf("\nYou will be called %s,",&name[0]); 
		printf(" is this correct? (y)yes (n)no\n");
		scanf(" %c", &check1);
	}
	while (check1=='n'||check1=='N'){
		   printf("What would you like to be called?\n");
		   scanf(" %s",&name[0]);
		   printf("\nYou will be called %s",&name[0]);
		   printf(" is this correct? (y)yes (n)no\n");
		   scanf(" %c", &check1);
		   while (check1!='y' && check1!='n'&& check1!='Y' && check1!='N'){
			      printf("\nError!!\tThat was not an option, please enter one of the options provided");
			      printf("\nYou will be called %s,",&name[0]); 
			      printf(" is this correct? (y)yes (n)no\n");
			      scanf(" %c", &check1);
	   }
   }
   //printf(" %s",name[30]);
   //printf(" %s",name);
 }  
   return name[30];
  
}

int fun2(char name[], int array[]){
   int choice;
   char adventure;
   
   printf("\n\nNow, %s, lets figure out what adventure you would like to go on.\nPlease enter one of the following and we will get underway:\n(M) Treacherous mountain climb\n(I) Mysterious hidden island\n(R) A short yet recognizable reference\n",name);
   scanf(" %c", &adventure);
   
   
   switch (adventure){
	   case 'M':
	   case 'm':
	   choice =1;
	   printf("\n\n\nYou have chosen the Mountain adventure\n");
	   break;
	   case 'I':
	   case 'i':
	   choice =2;
	   printf("\n\n\nYou have chosen the Island adventure\n");
	   break;
	   case 'R':
	   case 'r':
	   printf("\n\nI didn't think you'd pick this one.\nAs you leave the adventurer's guild, preparing for your great expidition,\nyou fall into a hole and die.\n\n");
	   
	   array[3]=9;
	   break;
	   default:
	   array[3]=9;
	   printf("\nError!! you didnt enter one of the adventure options\n");
	   printf("Do you want to go again?\n(1)Yes\n(2)No\t");
	   scanf(" %d",&array[4]);
	   printf("%d",&array[4]);
		while(array[4]!=1&&array[4]!=2&&array[4]!=0){
			printf("\nError!! Please enter one of the provided responses:\n(1)Yes\n(2)No\n");
			scanf(" %d",&array[4]);
		}
		}
   
	return choice;
}

int fun3(char name[],int array[],int trip){
	if (array[4]==1){
	array[1]=200;
	switch (trip){
	case 1:
	char store1,choice1,choice2;
	printf("This mountain is a challenge for even the most experienced climbers.\nWhen you arrive at base camp, before you climb, you have $200.\n");
	printf("\n%s, As you prepare for your climb you see a store selling supplies,\nthese might be useful on your journey up the mountain.\nDo you peruse their wares?\n(Y)Yes\n(N) No\n",name);
	scanf(" %c",&store1);
	while (store1!='y'&&store1!='Y'&&store1!='n'&&store1!='N'){
		printf("\nError!! Please select one of the options?\nAs you prepare for your climb you see a store selling supplies, these might be useful on your journey up the mountain.\nDo you peruse their wares?\n(Y)Yes\n(N) No\n");
		scanf(" %c",&store1);
	}
	if (store1=='n'||store1=='N'){
		array[0]=0;
		array[1]=200;
	}
	if (store1=='y'||store1=='Y'){
		printf("\n\nYou enter the store and find they two items for sale:\nA tent\t\t$100\nSnow shoes\t$50\nBoth\t\t$150\nDo you purchase any items?\n(Y)yes\n(N)no\n");
		scanf(" %c",&choice1);
		while (choice1!='y'&&choice1!='Y'&&choice1!='n'&&choice1!='N'){
		printf("\nError!! Please select one of the options?\nDo you purchase any items?\n(Y)Yes\n(N) No\n");
		scanf(" %c",&choice1);
		}
		if (choice1=='y'||choice1=='Y'){
		printf("What you want to purchase?: \n(T)Tent\t\t$100\n(S)SnowShoes\t$50\n(B)Both\t\t$150\n");
		scanf(" %c",&choice2);
		while (choice2!='T'&&choice2!='t'&&choice2!='S'&&choice2!='s'&&choice2!='B'&&choice2!='b'){
			 printf("\nError!!, please select one of the options...\nDo you want to purchase: \n(T)Tent\t$100\n(S)SnowShoes\t$50\n(B)Both\t$150\n");
			 scanf(" %c",&choice2);
		 }
	 }
		switch (choice2){
			case 'T':
			case 't':
			array[0]=1;
			array[1]=100;
			break;
			case 'S':
			case 's':
			array[0]=2;
			array[1]=150;
			break;
			case 'B':
			case 'b':
			array[0]=3;
			array[1]= 50;
			break;
		}
	}
	break;
///////////////////////////////////////////////////////////////////
		case 2:
		char store,choice,choice3;
	printf("This trip to the island is a challenge for even the most experienced sailors.\nWhen you arrive at the dock, before you set off, you have $200.\n");
	printf("\n%s, As you prepare for your voyage you see a store selling supplies,\nthese might be useful on your journey across the ocean.\nDo you peruse their wares?\n(Y)Yes\n(N) No\n",name);
	scanf(" %c",&store);
	while (store!='y'&&store!='Y'&&store!='n'&&store!='N'){
		printf("\nError!! Please select one of the options...\nAs you prepare for your voyage you see a store selling supplies, these might be useful on your journey across the ocean.\nDo you peruse their wares?\n(Y)Yes\n(N) No\n");
		scanf(" %c",&store);
	}
	if (store1=='n'||store1=='N'){
		array[0]=0;
		array[1]=200;
	}
	if (store=='y'||store=='Y'){
		printf("\n\nYou enter the store and find they two items for sale:\nA LifeRaft\t$100\nDuct tape\t$50\nDo you purchase any items?\n(Y)yes\n(N)no\n");
		scanf(" %c",&choice);
		while (choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n'){
		printf("Error!! Please select on of the options...\nDo you want to by anything?\n(Y)yes\n(N)no\n");
		scanf(" %c",&choice);
		}
		if (choice=='y'||choice=='Y'){
		printf("What you want to purchase?: \n(R)LifeRaft\t$100\n(D)Duct tape\t$50\n(B)Both\t$150\n");
		scanf(" %c",&choice3);
		while (choice3!='R'&&choice3!='r'&&choice3!='D'&&choice3!='d'&&choice3!='B'&&choice3!='b'){
			 printf("\nError!!, please select one of the options...\nDo you want to purchase: \n(R)LifeRaft\t$100\n(D)Duct tape\t$50\n(B)Both\t$150\n");
			 scanf(" %c",&choice3);
		 }
		switch (choice3){
			case 'R':
			case 'r':
			array[0]=1;
			array[1]=100;
			break;
			case 'D':
			case 'd':
			array[0]=2;
			array[1]=150;
			break;
			case 'B':
			case 'b':
			array[0]=3;
			array[1]= 50;
			break;
		}
	}
}
break;
printf("You have $%d left",array[1]);
//printf("%d,%d\n",array[0],array[1]);
}
}
return array[0];
}

int fun4(char name[],int array[],int trip){
	if (array[4]==1){
	char path;
	int choice;
	switch (trip){
	case 1:
		printf("\n\nFeeling assured your in decision about the store was right, you continue onward to the mountain.\nYou reach the trail markers and see there are two paths to take\n(R)Rookie\n(E)Experienced\n");
		scanf(" %c", &path);
		while (path!='r'&&path!='R'&&path!='e'&&path!='E'){
			printf("Error!! Please select one of the shown answers...\nYou reach the trail markers and see there are two paths to take\n(R)Rookie\n(E)Experienced\n");
			scanf(" %c",&path);
		}
		if (path=='r'||path=='R'){
			//printf("rookie");
			printf("\n\nAs you go along the rookie path you notice a horizon of dark clouds rolling in.\nLooking around you see two paths:\nThe First path seems worn down and well traveled.\nThe second path requires you to climb over a fallen tree.\nWhich Path do you take?\n(1)Well Traveled path\n(2)Downed tree\n");
			scanf(" %d",&choice);
			while (choice!=1&&choice!=2){
				printf("\nError!! Please select one of the shown answers...\nWhich Path do you take?\n(1)Well Traveled path\n(2)Downed tree\n");
				scanf(" %d",&choice);
			}
			switch (choice){
				case 1:
					printf("\n\nAs you travel the path, you notice it begins to snow...\nThe snow begins to pile up...\nYou can no continue on the path as the wind cuts through your jacket\n");
					if (array[0]!=1&&array[0]!=3){
					printf("Sadly you succumb to the cold.\nClinging to your last breath, you remember the store.\n");
					if (array[0]==2){
						printf("That tent might have saved your life");
					}
					if (array[0]!=2){
					printf("That store might have had somthing to protect you from the storm");
					}
					array[3]=0;
				}
					if (array[0]==1||array[0]==3){
					printf("Luckily you have a tent\nYou set up your tent and wait out the storm");
					}
				break;
				case 2:
					printf("\nYou climb over the tree and continue on your way");
					array[3]=1;
				break;
				
			}
		}
		if (path=='e'||path=='E'){
			//printf("Experienced");
			printf("\n\nAs you go along the experienced path you notice a divide in the path\nOne path leads to a cliff side\nThe other path goes through, what looks to be an old mineing cave\nlabled short cut\nWhich of the two do you choose?\n(1)Cliff\n(2)Mine\n");
			
			scanf(" %d",&choice);
			while (choice!=1&&choice!=2){
				printf("\nError!! Please select one of the shown answers...\nWhich Path do you take?\n(1)Cliff\n(2)Mine\n");
				scanf(" %d",&choice);
			}
			switch (choice){
				case 1:
					printf("\nYou approach the cliff and notice due to the wind the path is ice...");
					if (array[0]!=2&&array[0]!=3){
						printf("You try your luck on the icy mountain side and sadly\n\nYour boots were not up to the challenge\nAs you fall you remember the store\n");
					if (array[0]==1){
						printf("Those snow shoes might have given you the grip you needed");
						}
					if (array[0]!=1){
						printf("They might have sold somthing that could have helped you traverse the icy mountain side.");
						}
						array[3]=0;
					}
					if (array[0]==2||array[0]==3){
					printf("\nLuckily you have a pair of snowshoes\nYou easily traverse the icy mountain passage.");
					}
				break;
				
				case 2:
					printf("\nAs you wander throught the unlit mine, you come across a cave in.\nThrough a crawl space in the rubble you see a waving light\nYou fit through this space however you have to leave your items behind\n");
					array[0]=0;
				break;
				
		}
		

	break;
	
	///////////////////////////////////////////////////////////////////////////////////////
	case 2:
	printf("\n\nFeeling assured your in decision about the store was right, you continue onward down the docks.\nUpon reaching your boat you check the weather conditions.\nYou know your expedition must take place with in the next two days\nYou see that their is a rather large storm approaching\nYou can either wait a day and hope it blows over or you can set out early and try to out run the storm\n(E)early\n(W)Wait\n");
		scanf(" %c", &path);
		while (path!='e'&&path!='E'&&path!='w'&&path!='W'){
			printf("Error!! Please select one of the shown answers...\nWhen do you decide to leave?\n(E)early\n(W)wait\n");
			scanf(" %c",&path);
		}
		if (path=='E'||path=='e'){
			//printf("Early");
			printf("\n\nAs you leave the saftey of the land you see clouds rolling over the horizon.\nLooks like you just beat the storm\nYour trip has two different approaches.\nThe First approach is the left side of the island.\nThis side of the island is generally calm waters, however it is over a very low clearnace reef.\nThis could pose a threat to your boat.\nThe second approach is the right side of the island.\nThis side of the island has much choppier waters.\nYou will be unable to bring your boat to shore due to the this.\nWhich approach do you take?\n(1)Left\n(2)Right\n");
			scanf(" %d",&choice);
			while (choice!=1&&choice!=2){
				printf("\nError!! Please select one of the shown answers...\nWhich approach do you take?\n(1)Left\n(2)Right\n");
				scanf(" %d",&choice);
			}
			switch (choice){
				case 1://left
					printf("\n\nAs you close in on the island, you wonder where the reef is...\nYou think this just alittle too late...\nAs the thought enters your mind, you hear an awful shearing noise, and get thrown on the floor of the boat\nIn the crash you smash your leg into the boat...There is an audible cracking noise\nYour shin bone is not as straight as it once was.\nYou hobble down to the lower deck to assess the damage to the boat.\nYou discover the reef has scratched open a hole in your boat.");
					if (array[0]==0){
					printf("\nAs sea water floods the boat you scramble too the deck and jump\nThe leg that was just slightly angled is now screaming in pain.\nEach throb of your leg reminds you of the store.\nThey might have had something useful in saving your boat.");
				}
					if (array[0]==1){
						printf("\nAs sea water floods the boat you scramble too the deck grab your life raft and jump\nEach throb of your leg reminds you of the store.\nThat duct tape may have been usful in saving your boat.");
					}
					if (array[0]==2||array[0]==3){
						printf("\nAs sea water floods the boat you scramble to grab your duct tape.\nMaking a quick patch you are able to get ashore without hurting your leg any further.");
				}
				
				break;
			
				
				case 2://right
					printf("\nYou reach the island, anchor your boat, and swim to shore\n");
				break;
			}
		}
		if (path=='w'||path=='W'){
			//printf("Waited");
			printf("\n\nAfter waiting 24 hours you wake up to an unforgiving sea.\nThe tide is high and the waves are even higher\nYour trip has two different approaches.\nThe First approach is the left side of the island.\nThis side of the island is generally calm waters, however it is over a very low clearnace reef.\nThis could pose a threat to your boat.\nThe second approach is the right side of the island.\nThis side of the island has much choppier waters.\nYou will be unable to bring your boat to shore due to the this.\nWhich approach do you take?\n(1)Left\n(2)Right\n");
			
			scanf(" %d",&choice);
			while (choice!=1&&choice!=2){
				printf("\nError!! Please select one of the shown answers...\nWhich Path do you take?\n(1)Left(2)Right\n");
				scanf(" %d",&choice);
			}
			switch (choice){
				case 1://left
					printf("\n\nAs you struggle to stay on your boat you see the island,\n you then wonder where the reef is...\nYou think this just alittle too late...\nAs the thought enters your mind, you hear an awful shearing noise, and get thrown on the floor of the slick boat\nIn the crash you obliterate your leg on the boat...There is an audible cracking noise\nYour shin bone is not as straight as it once was.\nYou hobble down to the lower deck to assess the damage to the boat.\nYou discover the reef has cracked open a hole in your boat.");
					if (array[0]==0){
					printf("\nAs sea water floods the boat you scramble too the deck and jump\nThe leg that was just slightly angled is now screaming in pain.\nYou begin to faint and inhale water.\nWhile your consciousness fades\tYou think of the store\nThey might have had something to save you from the liquid coffin you find your self in");
					array[3]=0;
				}
					if (array[0]==2){
						printf("\nAs sea water floods the boat you scramble too the deck and jump\nThe leg that was just slightly angled is now screaming in pain.\nYou begin to faint and inhale water.\nWhile your consciousness fades\tYou think of the store\nThat life raft may have saved you from the liquid coffin you find your self in");
					array[3]=0;
					}
					if (array[0]==1&&array[0]==3){
						printf("\nAs sea water floods the boat you scramble too the deck grab your life raft and jump\nQuickly inflating your raft you are pushed ashore.\n");
					}
					
				
				break;
				
				case 2://right
					if (array[0]==1&&array[0]==3){
					printf("\nYou reach the island, anchor your boat, and deploy your life raft\n After batteling the sea you bareley make it to shore\nYou seem to have injured your shin while paddling ashore\n");
					}
					if (array[0]==2){
					printf("\nYou reach the island, anchor your boat, try to swim to shore\nUnable to fight the deadly waves you begin to inhale water\nAs you begin to loose consciousness\nYou think of the store\that life raft may have just have saved your life");
					array[3]=0;
					}
					if (array[0]==0){
					printf("\nYou reach the island, anchor your boat, try to swim to shore\nUnable to fight the deadly waves you begin to inhale water\nAs you begin to loose consciousness\nYou think of the store\they may have had something that could have saved your life");
					array[3]=0;
					}
				break;
				
		}
	}
		if (array[3]!=0){
		printf("\nFinally reaching the island you find a recked ship and make camp within its broke hull.");
		if (choice==1){
			printf("\nThe storm is fully over head beating on the ship, as you fall asleep");
		}
	}
	break;
	
	}
	if (array[3]==0){
		printf("That is the end of this adventure\nWould you like to go again?\n(1)yes\n(2)no\t");
		scanf(" %d",&array[4]);
		while (array[4]!=1&&array[4]!=2){
			printf("Error!! Please select one of the provided answers:\n(1)yes\n(2)no\t");
			scanf(" %d",&array[4]);
			return array[4];
		}
	}
	if (array[3]!=0){
		array[30]=fun5(name,array,trip);
	}
}
}
	return array[0];
}



int fun5(char name[],int array[],int trip){
	
	if (array[3]==1){
		char store4,pathing,fin;
	switch (trip){
	case 1:
	char store1,choice1,choice2;
	int store;
	if (trip==1){
		store=0;
		printf("\nAfter a short hike, You have reached a check point,\nin the form of a mountain side tavern.\nYou spend the night in an open room, free of charge\n\nThe next moring, you wake up tired\nYou over hear an adventurer talking to the barkeep.\nThe barkeep suggests the adventurer takes the left path to continue up the mountain \nwarning him that the right might require some extra equiptment.\nHowever, the adventurer explains he doesn't want to take the long way,\nas he hasn't packed enough food for the journey.");
	
	}
	printf("\nYou have $%d left",array[1]);
	printf("\nDo you see what the store has to offer?\n(Y)yes\n(N)no\n");
	scanf(" %c",&store1);
	while (store1!='y'&&store1!='Y'&&store1!='n'&&store1!='N'){
		printf("\nError!! Please select one of the options?\nDo you see what the store has to offer?\n(Y)Yes\n(N) No\n");
		scanf(" %c",&store1);
	}
	if (store1=='n'||store1=='N'){
		
		}
	if (store1=='y'||store1=='Y'){
		printf("\n\nYou enter the store and find they two items for sale:\nFood\t\t$50\nClimbing Pick   $150\nBoth\t\t$200\nDo you purchase any items?\n(Y)yes\n(N)no\n");
		scanf(" %c",&choice1);
		while (choice1!='y'&&choice1!='Y'&&choice1!='n'&&choice1!='N'){
		printf("\nError!! Please select one of the options?\nDo you purchase any items?\n(Y)Yes\n(N) No\n");
		scanf(" %c",&choice1);
		}
		if (choice1=='y'||choice1=='Y'){
		printf("What you want to purchase?: \n(F)Food    \t\t$50\n(C)Climbing Pick        $150\n(B)Both    \t\t$200\n");
		scanf(" %c",&choice2);
		while (choice2!='F'&&choice2!='f'&&choice2!='C'&&choice2!='c'&&choice2!='B'&&choice2!='b'){
			 printf("\nError!!, please select one of the options...\nDo you want to purchase: \n(F)Food\t$50\n(C)Climbing Pick\t$150\n(B)Both\t$200\n");
			 scanf(" %c",&choice2);
		 }
	 }
		switch (choice2){
			case 'F':
			case 'f':
			if (array[1]>=50){
			array[0]=4;
			array[1]=array[1]-50;
			store=1;
			}
			if (store==0&&array[1]<50){
				//printf("%d",array[1]);
				printf("You dont seem to have enough for that?");
			}
			break;
			case 'C':
			case 'c':
			if (array[1]>=150){
			array[0]=5;
			array[1]=array[1]-150;
			store=1;
			}
			while(store==0&&array[1]<150){
				printf("You dont seem to have enough for that?");
			}
			break;
			case 'B':
			case 'b':
			if (array[1]>=200){
			array[0]=6;
			array[1]=array[1]-200;
			store=1;
			}
			if (store==0&&array[1]<200){
				
				printf("You dont seem to have enough for that?");
			}
			break;
		}
	}//end of store start last case 1:mountain choices
		printf("\nWhen you leave the store you again face two paths ahead\nThe left path leads to some steps cut out of the mountain\nThe right to a cliff side\nWhich path do you choose?(L)left\n(R)right\n");
		scanf(" %c",&pathing);
		while (pathing!='L'&&pathing!='l'&&pathing!='R'&&pathing!='r'){
			 printf("\nError!!, please select one of the options...\nWhich Path do you want to take?\n(L)left\n(R)right\n");
			 scanf(" %c",&pathing);
		}
		switch (pathing){
			case'L':
			case'l':
			if (array[0]!=4&&array[0]!=6&&array[1]!=200){
				printf("As you walk up the steep stone stairs you begin to fade in and out of consciousness\nYou remember the adventurer from the tavern\nif only you had eaten before\nYou faint and fall off the stairs");
			}
			if (array[1]==200){
				printf("As you walk up the steep stone stairs a man approaches you\noffers you a donkey trip up the rest of he mountain for $200\nSince you haven't eaten and feel weak you accept his offer");
				array[3]=0;
			}
			break;
			case'R':
			case'r':
			printf("After going the right path\nyou are faced with a vertical stone wall or a deep snow path\nWhich do you choose?\n(S)snow\n(W)wall\n");
			scanf(" %c",&fin);
			while (fin!='S'&&fin!='s'&&fin!='W'&&fin!='w'){
			 printf("\nError!!, please select one of the options...\nWhich Path do you want to take?\n(L)left\n(R)right\n");
			 scanf(" %c",&pathing);
			}
		switch (fin){
				case'W':
				case'w':
				if (array[0]!=5&&array[0]!=4&&array[0]!=6){
					printf("You are confident enough to free climb this vertical wall\nas you get about 20ft up you feel a sudden wave of tiredness fall over you\nHaving not eaten and nothing to hold onto the wall with you simply fall backwards\nYou don't remember what happenes after that...");
					array[3]=0;
				}
				if (array[0]==5){
					printf("With your new trusty climbing pick you start up the wall\nas you get about 20ft up you feel a sudden wave of tiredness fall over you\nWith the climbing pick hold you on the wall the feeling passes and you continue\nYou reach the top of he wall\nAnd there it is the Summit\nYou successfully climbed the mountain");
				array[3]=0;
				}
				if (array[0]==6){
					printf("With your new trusty climbing pick you start up the wall\nWith the climbing pick hold you on the wall You reach the top of he wall\nAnd there it is the Summit\nYou successfully climbed the mountain");
				array[3]=0;
				}
				if (array[0]==4){
					printf("You are confident enough to free climb this vertical wall\nAs you get about 25ft up you feel your grip start to fail\nunable to hold onto the wall\nYou begin to fall\nThe end of the fall remains a mystery to you...");
					array[3]=0;
				}
				break;
				case'S':
				case's':
				if (array[0]!=4&&array[0]!=6){
					printf("As you journey through the deep snow you begin to feel tired\n then more tired\nYou sadly give into your exaustion\nYou fall victim to what most college kids do...\nMalnutrition\n");
					array[3]=0;
				}
				break;
			}
			break;
		}

		case 2:
		
	printf("\n\n\nWhen you wake up you see there is a battered medkit in the ship with you\nYou also find a flare gun with a single flare loaded in it.");
	printf("\nAfter seeing the options before you,\nYou exit your makshift shelter and see your boat is no longer floating.\nYou are stranded\nWhile you contemplate your life decisions you see a ship in the distance, like a candle 6 blocks away\nDo you use your flare in hopes they see you?\t(F)flare\nDo you use the Medkit saving the flare for another day?\t(M)Medkit\n");
	scanf(" %c",&store4);
	while (store4!='F'&&store4!='f'&&store4!='M'&&store4!='m'){
		printf("\nError!! Please select one of the predetermined options...\nDo you use your flare in hopes they see you?\t(F)flare\nDo you use the Medkit saving the flare for another day?\t(M)Medkit\n");
		scanf(" %c",&store4);
	}
		switch (store4){
			case 'F':
			case 'f':
			printf("In your injured desperation you send up the flare\nIt gleams a bright red hugh\tfor 5 seconds...\n\nYou no longer see the boat in the distance.\nGo treat the wound with the medkit.\nThe storm ends 2 days later\nYou question if there was even a ship for weeks (you think weeks at least)\nYou run out mental stamina...\nIn your crazed state you go to the flying island you see\nScreaming and waiving to get the islands attention you run full speed towards it\nThen it hits you\t a coconut\nThe tree releases its bounty on your head and you no longer need to worry about a rescue"); 
			array[3]=0;
			break;
			case 'M':
			case 'm':
			printf("You decide to hold onto the flare hoping skys will clear up.\nYou go and treat your leg with the medkit.\nTwo days later the storm breaks...\nAfter 4 days of your coconut diet you spot it\nA ship, this one a distance of 2 blocks away.\nYou grab your flare\tfire it\n\n\nThey shoot a flare back\nyou are saved");
			array[3]=0;
			break;
		}
	
	
}
}
	if (array[3]==0){
		printf("That is the end of this adventure\nWould you like to go again?\n(1)yes\n(2)no\t");
		scanf(" %d",&array[4]);
		while (array[4]!=1&&array[4]!=2){
			printf("Error!! Please select one of the provided answers:\n(1)yes\n(2)no\t");
			scanf(" %d",&array[4]);
			return array[4];
		}
	}
return array[0];
}




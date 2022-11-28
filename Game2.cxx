#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lvlSelect(void); // user selects 1, 2, or 3
int lvlPlay(char lvlS); // Starts level 1, 2, or 3
void lvlFinish(int Score); // Finishes level, returns to main, and displays score
void Update(char Level[][18]); // Reprints the level after a change occurs
int Move(char Level[][18],int Star[], char inpt, bool update); // Moves the star, returns the score
char Complete(char Level[][18], int Star[], int End[], char inpt); // End of each level
void lvlGenerate(int lvlS, char Level[][18], int Star[], int End[]); // Generates the level, either from text or randomly
char Prompt(char inpt); // Prompts the user input so that the text is not copied and pasted
bool randomCheck(char Level[][18], int Star[], int End[]); // Makes sure that the level is able to be completed

int main()
{
	char lvlS = lvlSelect();
	int Score = lvlPlay(lvlS);
	lvlFinish(Score);
	
	return 0;
}

int lvlSelect(void)
{
	char lvlS;
	system("Color 07");
	do
	{
	printf("\n\nPlease select a level to play:");
	printf("\nCastle (1)\nOcean (2)\nRandom (3)\n");
	printf("-->  ");
	scanf(" %c",&lvlS);
	printf(" ");
	if (lvlS != '1' && lvlS != '2' && lvlS != '3')
	{
		printf("\nType a number between 1 and 3!");
	}
	
	} while(lvlS != '1' && lvlS != '2' && lvlS != '3');
	
	return lvlS;
}

int lvlPlay(char lvlS)
{
	int Score = 0;
	char inpt;
	char Level[12][18];
	if (lvlS == '1')
	{
		system("Color F8");
		int Star[2] = {11,0};
		int End[2];
		lvlGenerate(1,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\n\nStage Complete!");
		inpt = Complete(Level,Star,End,inpt);
		
		lvlGenerate(2,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\n\nStage Complete!");
		inpt = Complete(Level,Star,End,inpt);
		
		lvlGenerate(3,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\n\nStage Complete!");
		inpt = Complete(Level,Star,End,inpt);
		
		lvlGenerate(4,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\n\nStage Complete!");
		inpt = Complete(Level,Star,End,inpt);
		
		lvlGenerate(5,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\n\nLevel Complete! Returning to Main.");
		inpt = Complete(Level,Star,End,inpt);
	}
	else if (lvlS == '2')
	{
		system("Color 3F");
		int Star[2];
		int End[2];
		lvlGenerate(11,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\n\nStage Complete!");
		inpt = Complete(Level,Star,End,inpt);
		
		lvlGenerate(12,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\n\nStage Complete!");
		inpt = Complete(Level,Star,End,inpt);
		
		lvlGenerate(13,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\n\nStage Complete!");
		inpt = Complete(Level,Star,End,inpt);
		
		lvlGenerate(14,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\n\nStage Complete!");
		inpt = Complete(Level,Star,End,inpt);
		
		lvlGenerate(15,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\n\nLevel Complete! Returning to Main.");
		inpt = Complete(Level,Star,End,inpt);
	}
	else if (lvlS == '3')
	{
		system("Color F0");
		int Star[2] = {11,0};
		int End[2] = {rand() % 4 + 2, rand() % 12 + 6};
		char Level[12][18];
		
		lvlGenerate(100 + rand() % 2,Level,Star,End);
		while (Level[End[0]][End[1]] == 'E')
		{
		inpt = Prompt(inpt);
		Score = Score + Move(Level,Star,inpt,true);
		}
		printf("\nLevel Complete!\nReturning to main.");
		inpt = Complete(Level,Star,End,inpt);
	}
	return Score;
}

void Update(char Level[][18])
{
	int i,j;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("|------------------|\n");
	for (i=0;i<12;i++)
		{
			printf("|");
			for (j=0;j<18;j++)
			{
				printf("%c",Level[i][j]);
			}
			printf("|\n");
		}
		printf("|------------------|\n");
}

char Prompt(char inpt)
{
	printf("Please select a direction to move the \'*\':\n");
	printf("Up\t(1)\tRight\t(2)\nDown\t(3)\tLeft\t(4)\n[Return to Main (-)]\n-->  ");
	scanf("%c",&inpt);
	return inpt;
}

int Move(char Level[][18], int Star[], char inpt, bool update)
{
	int Score = 0;
	int Movement = 0;
	// Escape to Main
	if (inpt == '-')
	{
		printf("\n\n\nReturning to main.\n");
		lvlFinish(Score);
	}
	
	
	// Up
	else if (inpt == '1')
	{
		while (Level[Star[0]-1][Star[1]] != '|' && Level[Star[0]-1][Star[1]] != '-' && Star[0]-1 >= 0)
		{
			if (Level[Star[0]-1][Star[1]] == 'O')
			{
				Score = Score + 10;
			}
			Level[Star[0]][Star[1]] = ' ';
			Level[Star[0]-1][Star[1]] = '*';
			Star[0] = Star[0] - 1;
			Movement = 1;
		}
	}
	
	// Right
	else if (inpt == '2')
	{
		while (Level[Star[0]][Star[1]+1] != '|' && Level[Star[0]][Star[1]+1] != '-' && Star[1]+1 <= 17)
		{
			if (Level[Star[0]][Star[1]+1] == 'O')
			{
				Score = Score + 10;
			}
			Level[Star[0]][Star[1]] = ' ';
			Level[Star[0]][Star[1]+1] = '*';
			Star[1] = Star[1] + 1;
			Movement = 1;
		}
	}
	
	// Down
	else if (inpt == '3')
	{
		while (Level[Star[0]+1][Star[1]] != '|' && Level[Star[0]+1][Star[1]] != '-' && Star[0]+1 <= 11)
		{
			if (Level[Star[0]+1][Star[1]] == 'O')
			{
				Score = Score + 10;
			}
			Level[Star[0]][Star[1]] = ' ';
			Level[Star[0]+1][Star[1]] = '*';
			Star[0] = Star[0] + 1;
			Movement = 1;
		}
	}
	
	// Left
	else if (inpt == '4')
	{
		while (Level[Star[0]][Star[1]-1] != '|' && Level[Star[0]][Star[1]-1] != '-' && Star[1]-1 >= 0)
		{
			if (Level[Star[0]][Star[1]-1] == 'O')
			{
				Score = Score + 10;
			}
			Level[Star[0]][Star[1]] = ' ';
			Level[Star[0]][Star[1]-1] = '*';
			Star[1] = Star[1] - 1;
			Movement = 1;
		}
	}
	if (update == true) {	Update(Level);return Score;}
	else { return Movement;}
}

char Complete(char Level[][18], int Star[], int End[], char inpt)
{
	char str[100];
	printf("\n\n\nType anything to continue...\n-->  ");
	scanf("%s",str);
	printf(" ");
	Level[End[0]][End[1]] = ' ';
	Star[0] = 11;
	Star[1] = 0;
	inpt = '0';
	return inpt;
}

void lvlGenerate(int lvlC, char Level[][18], int Star[], int End[])
{
	int i,j;
	FILE *pointer;
	if (lvlC == 1)
	{
		pointer = fopen("Level1.1.txt","r");
		for (i=0;i<12;i++)
		{
				for (j=0;j<18;j++)
				{
					fscanf(pointer,"%c",&Level[i][j]);
					if (Level[i][j] == 'E') 
					{
						End[0] = i;
						End[1] = j;
					}
				}
		}
	}
	if (lvlC == 2)
	{
		pointer = fopen("Level1.2.txt","r");
		for (i=0;i<12;i++)
		{
				for (j=0;j<18;j++)
				{
					fscanf(pointer,"%c",&Level[i][j]);
					if (Level[i][j] == 'E') 
					{
						End[0] = i;
						End[1] = j;
					}
				}
		}
	}
	if (lvlC == 3)
	{
		pointer = fopen("Level1.3.txt","r");
		for (i=0;i<12;i++)
		{
				for (j=0;j<18;j++)
				{
					fscanf(pointer,"%c",&Level[i][j]);
					if (Level[i][j] == 'E') 
					{
						End[0] = i;
						End[1] = j;
					}
				}
		}
	}
	if (lvlC == 4)
	{
		pointer = fopen("Level1.4.txt","r");
		for (i=0;i<12;i++)
		{
				for (j=0;j<18;j++)
				{
					fscanf(pointer,"%c",&Level[i][j]);
					if (Level[i][j] == 'E') 
					{
						End[0] = i;
						End[1] = j;
					}
				}
		}
	}
	if (lvlC == 5)
	{
		pointer = fopen("Level1.5.txt","r");
		for (i=0;i<12;i++)
		{
				for (j=0;j<18;j++)
				{
					fscanf(pointer,"%c",&Level[i][j]);
					if (Level[i][j] == 'E') 
					{
						End[0] = i;
						End[1] = j;
					}
				}
		}
	}
	if (lvlC == 11)
	{
		pointer = fopen("Level2.1.txt","r");
		for (i=0;i<12;i++)
		{
				for (j=0;j<18;j++)
				{
					fscanf(pointer,"%c",&Level[i][j]);
					if (Level[i][j] == 'E') 
					{
						End[0] = i;
						End[1] = j;
					}
					else if (Level[i][j] == '*') 
					{
						Star[0] = i;
						Star[1] = j;
					}
				}
		}
	}
	if (lvlC == 12)
	{
		pointer = fopen("Level2.2.txt","r");
		for (i=0;i<12;i++)
		{
				for (j=0;j<18;j++)
				{
					fscanf(pointer,"%c",&Level[i][j]);
					if (Level[i][j] == 'E') 
					{
						End[0] = i;
						End[1] = j;
					}
					else if (Level[i][j] == '*') 
					{
						Star[0] = i;
						Star[1] = j;
					}
				}
		}
	}
	if (lvlC == 13)
	{
		pointer = fopen("Level2.3.txt","r");
		for (i=0;i<12;i++)
		{
				for (j=0;j<18;j++)
				{
					fscanf(pointer,"%c",&Level[i][j]);
					if (Level[i][j] == 'E') 
					{
						End[0] = i;
						End[1] = j;
					}
					else if (Level[i][j] == '*') 
					{
						Star[0] = i;
						Star[1] = j;
					}
				}
		}
	}
	if (lvlC == 14)
	{
		pointer = fopen("Level2.4.txt","r");
		for (i=0;i<12;i++)
		{
				for (j=0;j<18;j++)
				{
					fscanf(pointer,"%c",&Level[i][j]);
					if (Level[i][j] == 'E') 
					{
						End[0] = i;
						End[1] = j;
					}
					else if (Level[i][j] == '*') 
					{
						Star[0] = i;
						Star[1] = j;
					}
				}
		}
	}
	if (lvlC == 15)
	{
		pointer = fopen("Level2.5.txt","r");
		for (i=0;i<12;i++)
		{
				for (j=0;j<18;j++)
				{
					fscanf(pointer,"%c",&Level[i][j]);
					if (Level[i][j] == 'E') 
					{
						End[0] = i;
						End[1] = j;
					}
					else if (Level[i][j] == '*') 
					{
						Star[0] = i;
						Star[1] = j;
					}
				}
		}
	}
	if (lvlC == 100)
	{
		do 
		{
			for (i=0;i<12;i+=2)
			{
				for (j=0;j<18;j+=3)
				{
					int r = rand() % 142 + 1;
					if (r > 0 && r < 10)
					{
						Level[i][j] = '-'; Level[i][j+1] = '-';Level[i][j+2] = '-';
						Level[i+1][j] = ' '; Level[i+1][j+1] = 'O';Level[i+1][j+2] = ' ';
					}
					else if (r >= 10 && r < 20)
					{
						Level[i][j] = '-'; Level[i][j+1] = '-';Level[i][j+2] = '|';
						Level[i+1][j] = ' '; Level[i+1][j+1] = 'O';Level[i+1][j+2] = ' ';
					}
					else if (r >= 20 && r < 30)
					{
						Level[i][j] = ' '; Level[i][j+1] = ' ';Level[i][j+2] = ' ';
						Level[i+1][j] = '|'; Level[i+1][j+1] = '-';Level[i+1][j+2] = '-';
					}
					else if (r >= 30 && r < 40)
					{
						Level[i][j] = '|'; Level[i][j+1] = '-';Level[i][j+2] = '-';
						Level[i+1][j] = '|'; Level[i+1][j+1] = ' ';Level[i+1][j+2] = ' ';
					}
					else if (r >= 50 && r < 60)
					{
						Level[i][j] = '-'; Level[i][j+1] = '|';Level[i][j+2] = '-';
						Level[i+1][j] = ' '; Level[i+1][j+1] = ' ';Level[i+1][j+2] = ' ';
					}
					else if (r >= 60 && r < 75)
					{
						Level[i][j] = '-'; Level[i][j+1] = '|';Level[i][j+2] = '-';
						Level[i+1][j] = ' '; Level[i+1][j+1] = '|';Level[i+1][j+2] = ' ';
					}
					else if (r >= 80 && r < 90)
					{
						Level[i][j] = '|'; Level[i][j+1] = ' ';Level[i][j+2] = 'O';
						Level[i+1][j] = '|'; Level[i+1][j+1] = '-';Level[i+1][j+2] = ' ';
					}
					else if (r >= 90 && r < 105)
					{
						Level[i][j] = ' '; Level[i][j+1] = ' ';Level[i][j+2] = ' ';
						Level[i+1][j] = '-'; Level[i+1][j+1] = '-';Level[i+1][j+2] = '-';
					}
					else if (r >= 110 && r < 125)
					{
						Level[i][j] = '|'; Level[i][j+1] = '-';Level[i][j+2] = '|';
						Level[i+1][j] = ' '; Level[i+1][j+1] = ' ';Level[i+1][j+2] = '|';
					}
					else if (r >= 130 && r < 135)
					{
						Level[i][j] = '|'; Level[i][j+1] = '-';Level[i][j+2] = '|';
						Level[i+1][j] = '|'; Level[i+1][j+1] = 'O';Level[i+1][j+2] = ' ';
					}
					else
					{
						Level[i][j] = '|'; Level[i][j+1] = ' ';Level[i][j+2] = ' ';
						Level[i+1][j] = ' '; Level[i+1][j+1] = ' ';Level[i+1][j+2] = '|';
					}
				}
			}
			Level[End[0]][End[1]] = 'E';
		} while (randomCheck(Level,Star,End) == false);
	}
	else if (lvlC == 101)
	{
		do 
		{
			for (i=0;i<12;i+=2)
			{
				for (j=0;j<18;j+=3)
				{
					int r = rand() % 142 + 1;
					if (r > 0 && r < 10)
					{
						Level[i][j] = '-'; Level[i][j+1] = ' ';Level[i][j+2] = '-';
						Level[i+1][j] = ' '; Level[i+1][j+1] = 'O';Level[i+1][j+2] = ' ';
					}
					else if (r >= 10 && r < 20)
					{
						Level[i][j] = ' '; Level[i][j+1] = '-';Level[i][j+2] = ' ';
						Level[i+1][j] = ' '; Level[i+1][j+1] = 'O';Level[i+1][j+2] = ' ';
					}
					else if (r >= 20 && r < 30)
					{
						Level[i][j] = ' '; Level[i][j+1] = ' ';Level[i][j+2] = ' ';
						Level[i+1][j] = ' '; Level[i+1][j+1] = '-';Level[i+1][j+2] = '-';
					}
					else if (r >= 30 && r < 40)
					{
						Level[i][j] = ' '; Level[i][j+1] = ' ';Level[i][j+2] = '-';
						Level[i+1][j] = '|'; Level[i+1][j+1] = ' ';Level[i+1][j+2] = ' ';
					}
					else if (r >= 50 && r < 60)
					{
						Level[i][j] = '-'; Level[i][j+1] = '|';Level[i][j+2] = ' ';
						Level[i+1][j] = ' '; Level[i+1][j+1] = ' ';Level[i+1][j+2] = ' ';
					}
					else if (r >= 60 && r < 75)
					{
						Level[i][j] = ' '; Level[i][j+1] = '|';Level[i][j+2] = ' ';
						Level[i+1][j] = ' '; Level[i+1][j+1] = '|';Level[i+1][j+2] = ' ';
					}
					else if (r >= 80 && r < 90)
					{
						Level[i][j] = ' '; Level[i][j+1] = '|';Level[i][j+2] = 'O';
						Level[i+1][j] = ' '; Level[i+1][j+1] = ' ';Level[i+1][j+2] = ' ';
					}
					else if (r >= 90 && r < 105)
					{
						Level[i][j] = ' '; Level[i][j+1] = ' ';Level[i][j+2] = ' ';
						Level[i+1][j] = '-'; Level[i+1][j+1] = '-';Level[i+1][j+2] = ' ';
					}
					else if (r >= 110 && r < 125)
					{
						Level[i][j] = ' '; Level[i][j+1] = '-';Level[i][j+2] = ' ';
						Level[i+1][j] = ' '; Level[i+1][j+1] = ' ';Level[i+1][j+2] = ' ';
					}
					else if (r >= 130 && r < 135)
					{
						Level[i][j] = '|'; Level[i][j+1] = '-';Level[i][j+2] = '|';
						Level[i+1][j] = ' '; Level[i+1][j+1] = 'O';Level[i+1][j+2] = ' ';
					}
					else
					{
						Level[i][j] = ' '; Level[i][j+1] = ' ';Level[i][j+2] = ' ';
						Level[i+1][j] = ' '; Level[i+1][j+1] = ' ';Level[i+1][j+2] = ' ';
					}
				}
			}
			Level[End[0]][End[1]] = 'E';
		} while (randomCheck(Level,Star,End) == false);
	}
	Level[Star[0]][Star[1]] = '*';
	fclose(pointer);
	Update(Level);
}

bool randomCheck(char Level[][18], int Star[], int End[])
{
	int i,j;
	char inptC;
	char LevelC[12][18];
	for (i=0;i<12;i++) { for (j=0;j<18;j++) {LevelC[i][j] = Level[i][j];} }
	int StarC[2] = {Star[0],Star[1]};
	j=0;
	for (i=0;i<300;i++)
	{
		int r = rand() % 4 + 1;
		switch (r)
		{
			case 1:
			inptC = '1';
			break;
			case 2:
			inptC = '2';
			break;
			case 3:
			inptC = '3';
			break;
			case 4:
			inptC = '4';
			break;
		}
		Move(LevelC,StarC,inptC,false);
		if (LevelC[End[0]][End[1]] != 'E' && j == 0)
		{
		j = i;
		}
	}
	if (LevelC[End[0]][End[1]] != 'E' && j > 100)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void lvlFinish(int Score)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\nYour score is %d",Score);
	main();
}

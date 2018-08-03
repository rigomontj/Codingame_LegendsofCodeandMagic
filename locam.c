#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_card
{
	int cardNumber;
	int instanceId;
	int location;
	int cardType;
	int cost;
	int attack;
	int defense;
	char abilities[7];
	int myHealthChange;
	int opponentHealthChange;
	int cardDraw;
	float p_dmg_val;
}		card;

typedef struct	s_player
{
	int playerHealth; // Remaining Health
	int playerMana; // Max Mana
	int playerDeck; // Remaining cards in deck
	int playerRune;
}		player;

float	ft_p_dmg_val(card c)
{
	float modifiers;
	float val;
	float directbonus;

	modifiers = 1;
	directbonus = 0;
	if (strstr(c.abilities, "B") != NULL) // Breakthrough
	{
		modifiers *= 1.08;
		fprintf(stderr, "Breakthrough => %f\n", modifiers);
	}
	if (strstr(c.abilities, "L") != NULL) // Lethal
	{
		modifiers *= 1.10;
		fprintf(stderr, "Lethal => %f\n", modifiers);
	}
	if (strstr(c.abilities, "C") != NULL) // Charge
	{
		modifiers *= 1.18;
		fprintf(stderr, "Charge => %f\n", modifiers);
	}
	if (strstr(c.abilities, "W") != NULL) // Ward
	{
		modifiers *= 1.21;
		fprintf(stderr, "Ward => %f\n", modifiers);
	}
	if (c.opponentHealthChange > 0)
	{
		directbonus = 1.08 * c.opponentHealthChange; 
		fprintf(stderr, "card modifier = %f\n", modifiers);
	}

	if (c.cardType != 0) 
	{
		modifiers = 0;
		fprintf(stderr, "ITEM, DO NOT TAKE\n", modifiers);
	}
	val = ((float)c.attack + directbonus) / (float)c.cost * modifiers;
	fprintf(stderr, "card modifier = %f\n", modifiers);
	fprintf(stderr, "card value = %f\n", val);
	return (val);
}

int main(void)
{
	card n0;
	card c1;
	card c2;
	card c3;
	card c4;
	card c5;
	card c6;
	card c7;
	card c8;
	card c9;
	card c10;
	card c11;
	card c12;
	card c13;
	card c14;
	card c15;
	card c16;
	card c17;
	card c18;
	card c19;
	card c20;

	card allcards[21] = {
		n0,
		c1,
		c2,
		c3,
		c4,
		c5,
		c6,
		c7,
		c8,
		c9,
		c10,
		c11,
		c12,
		c13,
		c14,
		c15,
		c16,
		c17,
		c18,
		c19,
		c20,
	};
	while (1)
	{
		player hero;
		scanf("%d%d%d%d", &(hero.playerHealth), &(hero.playerMana), &(hero.playerDeck), &(hero.playerRune));

		player villain;
		scanf("%d%d%d%d", &(villain.playerHealth), &(villain.playerMana), &(villain.playerDeck), &(villain.playerRune));

		int villainHand;
		scanf("%d", &villainHand);

		int cardCount;
		scanf("%d", &cardCount);

		for (int i = 1; i <= cardCount; i++)
		{
			scanf("%d%d%d%d%d%d%d%s%d%d%d", &(allcards[i].cardNumber), &(allcards[i].instanceId), &(allcards[i].location), &(allcards[i].cardType), &(allcards[i].cost), &(allcards[i].attack), &(allcards[i].defense), allcards[i].abilities, &(allcards[i].myHealthChange), &(allcards[i].opponentHealthChange), &(allcards[i].cardDraw));

			if (hero.playerMana == 0 && villain.playerMana == 0)
			{
				fprintf(stderr, "CARD %i\n", i);
				allcards[i].p_dmg_val = ft_p_dmg_val(allcards[i]);
			}
			else
			{
				printf("SUMMON %i;", allcards[i].instanceId);
				printf("ATTACK %i -1;", allcards[i].instanceId);
			}
		}


		if (hero.playerMana == 0 && villain.playerMana == 0)
		{
			float v1 = allcards[1].p_dmg_val;
			float v2 = allcards[2].p_dmg_val;
			float v3 = allcards[3].p_dmg_val;
			if (v1 >= v2 && v1 >= v3)
				printf("PICK 0\n");
			if (v2 >= v1 && v2 >= v3)
				printf("PICK 1\n");
			else
				printf("PICK 2\n");
		}
		else
		{
			printf("\n");
		}
	}
}
//fprintf(stderr, "\n");

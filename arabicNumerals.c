#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#define LENGTH 7
#define WIDTH 6
#define COLON_WIDTH 5

void setNumber (int n, int asciiN[LENGTH][WIDTH * 2]);
void displayTime (int hour, int minute, int second);

int
main ()
{
  time_t timer;
  struct tm *t_st;

  while (1)
    {
      system ("clear");
      time (&timer);
      t_st = localtime (&timer);

      displayTime (t_st->tm_hour, t_st->tm_min, t_st->tm_sec);
      sleep (1);
    }

  return 0;
}

void
displayTime (int hour, int minute, int second)
{
  int h[LENGTH][WIDTH * 2], m[LENGTH][WIDTH * 2], s[LENGTH][WIDTH * 2];
  memset (h, 0, sizeof (h));
  memset (m, 0, sizeof (m));
  memset (s, 0, sizeof (s));
  int i = 0, j = 0;
  char colon[][COLON_WIDTH] = {
    {"     "},
    {"  |  "},
    {"  |  "},
    {"     "},
    {"  |  "},
    {"  |  "},
    {"     "}
  };
  int timeWidth =
    WIDTH * 2 + COLON_WIDTH + WIDTH * 2 + COLON_WIDTH + WIDTH * 2;
  char clockDisplay[LENGTH][timeWidth];
  memset (clockDisplay, 0, sizeof (clockDisplay));
  setNumber (hour, h);
  setNumber (minute, m);
  setNumber (second, s);

//Unite
  for (i = 0; i < LENGTH; i++)
    {
      for (j = 0; j < WIDTH * 2; j++)
	{
	  clockDisplay[i][j] = h[i][j];
	}
    }
//
  for (i = 0; i < LENGTH; i++)
    {
      for (j = 0; j < COLON_WIDTH; j++)
	{
	  clockDisplay[i][j + WIDTH * 2] = colon[i][j];
	}
    }
//
  for (i = 0; i < LENGTH; i++)
    {
      for (j = 0; j < WIDTH * 2; j++)
	{
	  clockDisplay[i][j + WIDTH * 2 + COLON_WIDTH] = m[i][j];
	}
    }
//
  for (i = 0; i < LENGTH; i++)
    {
      for (j = 0; j < COLON_WIDTH; j++)
	{
	  clockDisplay[i][j + WIDTH * 2 + COLON_WIDTH + WIDTH * 2] =
	    colon[i][j];
	}
    }
//
  for (i = 0; i < LENGTH; i++)
    {
      for (j = 0; j < WIDTH * 2; j++)
	{
	  clockDisplay[i][j + WIDTH * 2 + COLON_WIDTH + WIDTH * 2 +
			  COLON_WIDTH] = s[i][j];
	}
    }

//Display
  for (i = 0; i < LENGTH; i++)
    {
      for (j = 0; j < timeWidth; j++)
	{
	  printf ("%c", clockDisplay[i][j]);
	}
      printf ("\n");
    }

}

void
setNumber (int n, int asciiN[LENGTH][WIDTH * 2])
{
  int i = 0, j = 0;
  char zero[][WIDTH] = {
    {" **** "},
    {" *  * "},
    {" *  * "},
    {" *  * "},
    {" *  * "},
    {" *  * "},
    {" **** "}
  };
  char one[][WIDTH] = {
    {"    * "},
    {"    * "},
    {"    * "},
    {"    * "},
    {"    * "},
    {"    * "},
    {"    * "}
  };
  char two[][WIDTH] = {
    {" **** "},
    {"    * "},
    {"    * "},
    {" **** "},
    {" *    "},
    {" *    "},
    {" **** "}
  };
  char three[][WIDTH] = {
    {" **** "},
    {"    * "},
    {"    * "},
    {" **** "},
    {"    * "},
    {"    * "},
    {" **** "}
  };
  char four[][WIDTH] = {
    {" *  * "},
    {" *  * "},
    {" *  * "},
    {" **** "},
    {"    * "},
    {"    * "},
    {"    * "}
  };
  char five[][WIDTH] = {
    {" **** "},
    {" *    "},
    {" *    "},
    {" **** "},
    {"    * "},
    {"    * "},
    {" **** "}
  };
  char six[][WIDTH] = {
    {" **** "},
    {" *    "},
    {" *    "},
    {" **** "},
    {" *  * "},
    {" *  * "},
    {" **** "}
  };
  char seven[][WIDTH] = {
    {" **** "},
    {"    * "},
    {"    * "},
    {"    * "},
    {"    * "},
    {"    * "},
    {"    * "}
  };
  char eight[][WIDTH] = {
    {" **** "},
    {" *  * "},
    {" *  * "},
    {" **** "},
    {" *  * "},
    {" *  * "},
    {" **** "}
  };
  char nine[][WIDTH] = {
    {" **** "},
    {" *  * "},
    {" *  * "},
    {" **** "},
    {"    * "},
    {"    * "},
    {" **** "}
  };
  char none[][WIDTH] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "},
    {"      "},
    {"      "},
    {"      "}
  };

//char asciiN[LENGTH][WIDTH*2]={};
//memset(asciiN,0,sizeof(asciiN));

  int oneDigit = n % 10, twoDigit = n / 10;

  for (i = 0; i < LENGTH; i++)
    {
      for (j = 0; j < WIDTH; j++)
	{
	  switch (twoDigit)
	    {
	    case 0:
	      asciiN[i][j] = zero[i][j];
	      break;
	    case 1:
	      asciiN[i][j] = one[i][j];
	      break;
	    case 2:
	      asciiN[i][j] = two[i][j];
	      break;
	    case 3:
	      asciiN[i][j] = three[i][j];
	      break;
	    case 4:
	      asciiN[i][j] = four[i][j];
	      break;
	    case 5:
	      asciiN[i][j] = five[i][j];
	      break;
	    case 6:
	      asciiN[i][j] = six[i][j];
	      break;
	    case 7:
	      asciiN[i][j] = seven[i][j];
	      break;
	    case 8:
	      asciiN[i][j] = eight[i][j];
	      break;
	    case 9:
	      asciiN[i][j] = nine[i][j];
	      break;
	    }
	}
    }

  for (i = 0; i < LENGTH; i++)
    {
      for (j = 0; j < WIDTH; j++)
	{
	  switch (oneDigit)
	    {
	    case 0:
	      asciiN[i][j + WIDTH] = zero[i][j];
	      break;
	    case 1:
	      asciiN[i][j + WIDTH] = one[i][j];
	      break;
	    case 2:
	      asciiN[i][j + WIDTH] = two[i][j];
	      break;
	    case 3:
	      asciiN[i][j + WIDTH] = three[i][j];
	      break;
	    case 4:
	      asciiN[i][j + WIDTH] = four[i][j];
	      break;
	    case 5:
	      asciiN[i][j + WIDTH] = five[i][j];
	      break;
	    case 6:
	      asciiN[i][j + WIDTH] = six[i][j];
	      break;
	    case 7:
	      asciiN[i][j + WIDTH] = seven[i][j];
	      break;
	    case 8:
	      asciiN[i][j + WIDTH] = eight[i][j];
	      break;
	    case 9:
	      asciiN[i][j + WIDTH] = nine[i][j];
	      break;
	    default:
	      asciiN[i][j + WIDTH] = none[i][j];
	      break;
	    }
	}
    }

}
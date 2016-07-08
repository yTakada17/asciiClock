#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

#define WIDTH_I 2
#define WIDTH_V 10
#define WIDTH_X 6
#define WIDTH_L 6
#define HEIGHT 5
#define WIDTH_COLON 5
#define WIDTH_MAX_HOUR 100
//WIDTH_X*2+WIDTH_I+WIDTH_V     //24(0)
#define WIDTH_MAX_MINUTE 100
//WIDTH_X*3+WIDTH_V+WIDTH_I*3   //38
#define WIDTH_MAX_DISPLAY 100

//WIDTH_MAX_HOUR+WIDTH_COLON+WIDTH_MAX_MINUTE   //0(24):38

void displayRomeNumberTime (int h, int m, int n);

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

      printf ("%d:%d:%d\n", t_st->tm_hour, t_st->tm_min, t_st->tm_sec);
      displayRomeNumberTime (t_st->tm_hour, t_st->tm_min, t_st->tm_sec);
//printf("%d:%d:%d\n",t_st->tm_hour, t_st->tm_min, t_st->tm_sec);
      sleep (1);
    }

  return 0;
}

void
displayRomeNumberTime (int h, int m, int s)
{
  int count = 0;
  int i = 0, j = 0;
  char display[HEIGHT][WIDTH_MAX_DISPLAY + 1] = { };
  char colon[][WIDTH_COLON + 1] = {
    {"     "},
    {"  |  "},
    {"     "},
    {"  |  "},
    {"     "}
  };
  char one[][WIDTH_I + 1] = {
    {" *"},
    {" *"},
    {" *"},
    {" *"},
    {" *"}
  };
  char two[][WIDTH_I * 2 + 1] = {
    {" * *"},
    {" * *"},
    {" * *"},
    {" * *"},
    {" * *"}
  };
  char three[][WIDTH_I * 3 + 1] = {
    {" * * *"},
    {" * * *"},
    {" * * *"},
    {" * * *"},
    {" * * *"}
  };
  char four[][WIDTH_I + WIDTH_V + 1] = {
    {" * *       *"},
    {" *  *     * "},
    {" *   *   *  "},
    {" *    * *   "},
    {" *     *    "}
  };
  char five[][WIDTH_V + 1] = {
    {" *       *"},
    {"  *     * "},
    {"   *   *  "},
    {"    * *   "},
    {"     *    "}
  };
  char six[][WIDTH_V + WIDTH_I + 1] = {
    {" *       * *"},
    {"  *     *  *"},
    {"   *   *   *"},
    {"    * *    *"},
    {"     *     *"}
  };
  char seven[][WIDTH_V + WIDTH_I * 2 + 1] = {
    {" *       * * *"},
    {"  *     *  * *"},
    {"   *   *   * *"},
    {"    * *    * *"},
    {"     *     * *"}
  };
  char eight[][WIDTH_V + WIDTH_I * 3 + 1] = {
    {" *       * * * *"},
    {"  *     *  * * *"},
    {"   *   *   * * *"},
    {"    * *    * * *"},
    {"     *     * * *"}
  };
  char nine[][WIDTH_I + WIDTH_X + 1] = {
    {" * *   *"},
    {" *  * * "},
    {" *   *  "},
    {" *  * * "},
    {" * *   *"}
  };
  char ten[][WIDTH_X + 1] = {
    {" *   *"},
    {"  * * "},
    {"   *  "},
    {"  * * "},
    {" *   *"}
  };
  char twenty[][WIDTH_X * 2 + 1] = {
    {" *   * *   *"},
    {"  * *   * * "},
    {"   *     *  "},
    {"  * *   * * "},
    {" *   * *   *"}
  };
  char thirty[][WIDTH_X * 3 + 1] = {
    {" *   * *   * *   *"},
    {"  * *   * *   * * "},
    {"   *     *     *  "},
    {"  * *   * *   * * "},
    {" *   * *   * *   *"}
  };
  char fourty[][WIDTH_X + WIDTH_L + 1] = {
    {" *   * *    "},
    {"  * *  *    "},
    {"   *   *    "},
    {"  * *  *    "},
    {" *   * *****"}
  };
  char fifty[][WIDTH_L + 1] = {
    {" *    "},
    {" *    "},
    {" *    "},
    {" *    "},
    {" *****"}
  };
  char sixty[][WIDTH_L + WIDTH_X + 1] = {
    {" *     *   *"},
    {" *      * * "},
    {" *       *  "},
    {" *      * * "},
    {" ***** *   *"}
  };

//Hour
  if (h == 10)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], ten[i]);
	}
    }
  else if (11 <= h && h <= 19)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], ten[i]);
	}
      h = h % 10;
    }
  else if (h == 20)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], twenty[i]);
	}
    }
  else if (21 <= h && h <= 24)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], twenty[i]);
	}
      h = h % 20;
    }
//
  switch (h)
    {
    case 0:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], twenty[i]);
	  strcat (display[i], four[i]);
	}
      break;
    case 1:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], one[i]);
	}
      break;
    case 2:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], two[i]);
	}
      break;
    case 3:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], three[i]);
	}
      break;
    case 4:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], four[i]);
	}
      break;
    case 5:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], five[i]);
	}
      break;
    case 6:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], six[i]);
	}
      break;
    case 7:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], seven[i]);
	}
      break;
    case 8:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], eight[i]);
	}
      break;
    case 9:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], nine[i]);
	}
      break;
    default:
      break;
    }

//colon
  for (i = 0; i < HEIGHT; i++)
    {
      strcat (display[i], colon[i]);
    }

//Minute

  if (m == 10)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], ten[i]);
	}
    }
  else if (m == 20)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], twenty[i]);
	}
    }
  else if (m == 30)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], thirty[i]);
	}
    }
  else if (m == 40)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], fourty[i]);
	}
    }
  else if (m == 50)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], fifty[i]);
	}
    }
  else if (m == 60)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], sixty[i]);
	}
    }
  else if (11 <= m && m <= 19)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], ten[i]);
	}
      m = m % 10;
    }
  else if (21 <= m && m <= 29)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], twenty[i]);
	}
      m = m % 20;
    }
  else if (31 <= m && m <= 39)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], thirty[i]);
	}
      m = m % 30;
    }
  else if (41 <= m && m <= 49)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], fourty[i]);
	}
      m = m % 40;
    }
  else if (51 <= m && m <= 59)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], fifty[i]);
	}
      m = m % 50;
    }
//

  switch (m)
    {
    case 0:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], sixty[i]);
	}
      break;
    case 1:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], one[i]);
	}
      break;
    case 2:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], two[i]);
	}
      break;
    case 3:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], three[i]);
	}
      break;
    case 4:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], four[i]);
	}
      break;
    case 5:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], five[i]);
	}
      break;
    case 6:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], six[i]);
	}
      break;
    case 7:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], seven[i]);
	}
      break;
    case 8:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], eight[i]);
	}
      break;
    case 9:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], nine[i]);
	}
      break;
    default:
      break;
    }


//Colon
  for (i = 0; i < HEIGHT; i++)
    {
      strcat (display[i], colon[i]);
    }

//Second
  if (s == 10)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], ten[i]);
	}
    }
  else if (s == 20)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], twenty[i]);
	}
    }
  else if (s == 30)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], thirty[i]);
	}
    }
  else if (s == 40)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], fourty[i]);
	}
    }
  else if (s == 50)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], fifty[i]);
	}
    }
  else if (s == 60)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], sixty[i]);
	}
    }
  else if (11 <= s && s <= 19)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], ten[i]);
	}
      s = s % 10;
    }
  else if (21 <= s && s <= 29)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], twenty[i]);
	}
      s = s % 20;
    }
  else if (31 <= s && s <= 39)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], thirty[i]);
	}
      s = s % 30;
    }
  else if (41 <= s && s <= 49)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], fourty[i]);
	}
      s = s % 40;
    }
  else if (51 <= s && s <= 59)
    {
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], fifty[i]);
	}
      s = s % 50;
    }


  switch (s)
    {
    case 0:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], sixty[i]);
	}
      break;
    case 1:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], one[i]);
	}
      break;
    case 2:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], two[i]);
	}
      break;
    case 3:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], three[i]);
	}
      break;
    case 4:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], four[i]);
	}
      break;
    case 5:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], five[i]);
	}
      break;
    case 6:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], six[i]);
	}
      break;
    case 7:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], seven[i]);
	}
      break;
    case 8:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], eight[i]);
	}
      break;
    case 9:
      for (i = 0; i < HEIGHT; i++)
	{
	  strcat (display[i], nine[i]);
	}
      break;
    default:
      break;
    }


//Print
  for (i = 0; i < HEIGHT; i++)
    {
      for (j = 0; display[i][j] != '\0'; j++)
	{
	  printf ("%c", display[i][j]);
	}
      printf ("\n");
    }

}

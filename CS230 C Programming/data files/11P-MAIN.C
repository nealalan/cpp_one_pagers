#include <stdio.h>
#include <string.h>

void set (char *s, int n);
void show(char *s, int n);
char *delete (char *s, int ofs, int count);
char *insert (char *s1, int ofs, char *s2);

/*=============================================================*/
void main (void)
   {
   char s[80], *s1=s+5, *s2=s+55;
   int count, ofs, n;

   set(s, sizeof(s));
   while ((n = scanf("%s%d%d%s", s1, &ofs, &count, s2)) == 4)
      {
      printf ("offset=%d  count=%d\n", ofs, count);
      show(s, 79);
      if (s1 != delete (s1, ofs, count))
	 printf("delete return error\n");
      show(s, 79);
      if (s1 != insert (s1, ofs, s2))
	 printf("insert return error\n");
      show(s, 79);
      printf("\n");
      set(s, sizeof(s));
      }
   if (n != EOF)
      printf ("\n\n***** Format error in input *****\n");
   }

/*=============================================================*/
void show(char *s, int n)
   {
   int i, j;

   for (i=0, j=128; i < n; i++, j++)
      if (((unsigned char *)s)[i] == j)
	 putchar(' ');
      else if (s[i])
	 putchar(s[i]);
      else
	 putchar('^');
   putchar('\n');
   }

/*=============================================================*/
void set (char *s, int n)
   {
   int i, j;

   for (i=0, j=128; i < n; i++, j++)
      s[i] = j;
   }

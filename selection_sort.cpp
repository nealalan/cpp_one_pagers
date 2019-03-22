#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
  int my_array[10];
  int index, index2, found_index, temp, temp2;
  bool found;
  int looking_for;

  index = 0;

  while (index < 10)
  {
	my_array[index] = (rand(1%1000)) + 1;
    index++;
  }

  index = 0;

  while (index < (10-1))
  {
    index2 = index;
    found = false;
    temp = my_array[index2];

    while (index2 < 10)
    {
      if (my_array[index2] < temp)
      {
        temp = my_array[index2];
        found_index = index2;
        found = true;
      }

      index2++;
    }

    if (found)
    {
      temp2 = my_array[index];
      my_array[index] = my_array[found_index];
      my_array[found_index] = temp2;
    }

    index++;
  }
  index = 0;

  while (index < 10)
  {
    cout << my_array[index] << endl;
    index++;
  }

}

//Quine_McCluskey_Tabular_Method for logic design

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num_variable, num_minterm, num_dont_care;
  int *minterm_list, *dont_care_list;
  int** minterm_table;
  int i,j,k,count = 0,temp,min;
  int index;

  int* temp2;

  scanf("%d %d %d", &num_variable, &num_minterm, &num_dont_care);

  minterm_list = (int*)malloc(sizeof(int) * num_minterm);
  dont_care_list = (int*)malloc(sizeof(int) * num_dont_care);

  for(i = 0; i < num_minterm; i++)
  {
    scanf("%d",&minterm_list[i]);
  }
  for(i = 0; i < num_dont_care; i++)
  {
    scanf("%d", &dont_care_list[i]);
  }

  minterm_table = (int**)malloc(sizeof(int*) * (num_minterm + num_dont_care));
  for(i = 0; i < num_minterm + num_dont_care; i++)
  {
    minterm_table[i] = (int*)malloc(sizeof(int) * num_variable+2);
  }

  for(i = 0; i < num_minterm + num_dont_care; i++)
  {
    if(i < num_minterm)
    {
      temp = minterm_list[i];
      for(j = num_variable+1; j > 1; j--)
      {
        minterm_table[i][j] = temp % 2;
        temp /= 2;
        if(minterm_table[i][j] == 1)
        {
          count++;
        }
      }
      minterm_table[i][1] = minterm_list[i];
      minterm_table[i][0] = count;
      count = 0;
    }
    else {
      index = i - num_minterm;
      temp = dont_care_list[index];
      for(j = num_variable+1; j > 1; j--)
      {
        minterm_table[i][j] = temp % 2;
        temp /= 2;
        if(minterm_table[i][j] == 1)
        {
          count++;
        }
      }
      minterm_table[i][1] = dont_care_list[index];
      minterm_table[i][0] = count;
      count = 0;
    }
  }

  for(i = 0; i < num_minterm + num_dont_care; i++)
  {
    for(j = i+1; j < num_minterm + num_dont_care; j++)
    {
      if(minterm_table[i][0] >= minterm_table[j][0])
      {
        temp2 = minterm_table[i];
        minterm_table[i] = minterm_table[j];
        minterm_table[j] = temp2;

      }
    }
  }
 /
  for(i = 0; i < num_minterm + num_dont_care; i++)
  {
    for(j = 0; j < num_variable+2; j++)
    {
      printf("%d ", minterm_table[i][j]);
    }
    printf("\n");
  }

  free(minterm_list);
  free(dont_care_list);
  for(i = 0; i < num_minterm + num_dont_care; i++)
  {
    free(minterm_table[i]);
  }
  free(minterm_table);

  return 0;
}


//Quine_McCluskey_Tabular_Method for logic design

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num_variable, num_minterm, num_dont_care;
  int *minterm_list, *dont_care_list;
  int** minterm_table;
  int i,j,count = 0,temp,min;
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

  minterm_table = (int**)malloc(sizeof(int*) * num_minterm);
  for(i = 0; i < num_minterm; i++)
  {
    minterm_table[i] = (int*)malloc(sizeof(int) * num_variable+1);
  }

  
  for(i = 0; i < num_minterm; i++)
  {
    temp = minterm_list[i];
    for(j = num_variable; j > 0; j--)
    {
      minterm_table[i][j] = temp % 2;
      temp /= 2;

      if(minterm_table[i][j] == 1)
      {
        count++;
      }
    }
    minterm_table[i][0] = count;
    count = 0;
  }

  for(i = 0; i < num_minterm; i++)
  {
    min = i;
    for(j = i+1; j < num_minterm; j++)
    {
      if(minterm_table[min][0] > minterm_table[j][0])
      {
        min = j;
      }
    }
    temp2 = minterm_table[min];
    minterm_table[min] = minterm_table[i];
    minterm_table[i] = temp2;
  }

  for(i = 0; i < num_minterm; i++)
  {
    for(j = 0; j < num_variable+1; j++)
    {
      printf("%d ", minterm_table[i][j]);
    }
    printf("\n");
  }
  
  free(minterm_list);
  free(dont_care_list);
  for(i = 0; i < num_variable+1; i++)
  {
    free(minterm_table[i]);
  }
  free(minterm_table);
  return 0;
}


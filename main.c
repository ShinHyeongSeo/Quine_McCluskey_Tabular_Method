//Quine_McCluskey_Tabular_Method for logic design

#include <stdio.h>
#include <stdlib.h>

typedef struct st_minterm {
  int dec;
  int* bin;
  int count;
  struct st_minterm* right;
} minterm;

int main()
{
  int num_variable, num_minterm, num_dont_care;
  int *minterm_list, *dont_care_list;
  int** minterm_table;
  minterm* temp = NULL;
  minterm* root = (minterm*)malloc(sizeof(mitnerm));
  int i;

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

  free(minterm_list);
  free(dont_care_list);
  

  return 0;
}


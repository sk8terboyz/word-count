#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char str[100];
  FILE *fp;
  int lineCount, wordCount;
  char *wordDiv;
  char line[200];
  char *divider;

  //get file name
  printf("Enter in the file name : ");
  scanf("%s", str);

  //open the file
  fp = fopen(str, "r");

  if(fp == NULL)
  {
    printf("File could not be opened");
    return 1;
  }

//read in the file line by line
  while(fgets(line, sizeof(line), fp))
  {
    divider = strtok(line,"\n");
    if(divider != NULL)
    {
      lineCount++;
      wordCount++;
      wordDiv = strtok(divider," ");
      if(wordDiv != NULL)
      {
        wordCount++;
      }
    }
  }

  //close the file
  fclose(fp);
  //print out the amount of words and lines
  printf("The file has %d words and %d lines.\n", wordCount, lineCount);

  return 0;
}

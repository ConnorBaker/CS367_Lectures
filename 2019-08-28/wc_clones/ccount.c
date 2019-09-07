/*  Rules:
 *    1) A line is terminated with a '\n'
 *    2) A word is separated by a ' '
 *    3) A '\n' and a ' ' are both characters.
 *
 *    Write a program to count lines, words, and characters
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
    exit(2);
  }

  FILE *fp = fopen(argv[1], "r");
  if(fp == NULL) {
    printf("File error opening %s\n", argv[1]);
    exit(1);
  }

  int ch;

  int count_ch = 0;
  int count_wd = 0;
  int count_ln = 0;

  int is_word = 0;

  while((ch = fgetc(fp)) != EOF) {
    count_ch++;

    if(ch != '\n' && ch != ' ') {
      is_word = 1;
    }
    else {
      if(is_word == 1) {
        count_wd++;
        is_word = 0;
      }
    }
    
    if(ch == '\n') {
      count_ln++;
    }
  }

  if(is_word == 1) {
    count_wd++;
    is_word = 0;
  }

  fclose(fp);

  printf("Chars:  %d\n", count_ch);
  printf("Words:  %d\n", count_wd);
  printf("Lines:  %d\n", count_ln);

  return 0;
}

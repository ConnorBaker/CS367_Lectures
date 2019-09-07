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
    exit(-1);
  }

  FILE *in_file = fopen(argv[1], "r");
  if(in_file == NULL) {
    printf("Error opening file: %s\n", argv[1]);
    exit(-1);
  }

  int cur_c = -1;
  int pre_c = -1;

  int char_ctr = 0;
  int word_ctr = 0;
  int line_ctr = 0;

  int in_word = 0;

  while((cur_c = fgetc(in_file)) != EOF) {
    char_ctr++;
    
    if(cur_c == '\n') {
      line_ctr++;
    }

    if(cur_c != '\n' && cur_c != ' ') {
      in_word = 1;
    }
    else {
      if(in_word == 1) {
        word_ctr++;
        in_word = 0;
      }
    }

    
    pre_c = cur_c;
  }

  if(in_word == 1) {
    in_word = 0;
    word_ctr++;
  }

  fclose(in_file);

  printf("Characters:   %d\n", char_ctr);
  printf("Words:        %d\n", word_ctr);
  printf("Lines:        %d\n", line_ctr);
  return 0;
}

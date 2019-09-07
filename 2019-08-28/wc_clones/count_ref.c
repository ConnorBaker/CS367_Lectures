#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A very quick implementation of wc for lecture demo. 
// A logical bug was included for in-class discussion, if it came to that.
// Spoiler Alert: It didn't.  You guys are awesome. 

int main(int argc, char *argv[]) {
  char buffer[255]; // Makes a big assumption about line sizes... maybe fgetc was smarter! :) 
  // Also wastes a lot of memory while running.  Both are fine for this demo.
  
  // The three counters
  int line_count = 0; // Anything that ends with \n
  int word_count = 0; // Space or \n delimited
  int char_count = 0; // \n and space count

  // Check for one arg, which is filename
  if(argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(-1);
  }

  // Exit if file not found or any other file error
  // If specific error handling is desired, need to get errno
  FILE *fp = fopen(argv[1], "r");
  if(fp == NULL) {
    printf("File Error!  Exiting.\n");
    exit(-1);
  }

  // Iterate over each Line of the input file.
  while(fgets(buffer, sizeof(buffer), fp) != NULL) {
    char *b_ptr = buffer;
    word_count++; // Is it safe to start word counting here in all cases? 
    // Iterate over each character of the line
    while(*b_ptr != '\n') {
      char_count++;
      // Will this cover all cases to track word count accurately? 
      if(*b_ptr == ' ') {
        word_count++;
      }
      b_ptr++;
    }
    char_count++;
    line_count++;
  }
  
  printf("There were %d lines, %d words, and %d characters.\n", line_count, word_count, char_count);

  // Responsibly clean up the file.
  fclose(fp);
  fp = NULL;

  return 0;
}

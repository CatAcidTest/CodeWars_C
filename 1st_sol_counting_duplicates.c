#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

size_t duplicate_count(const char *text) {

  //return the total number of chars that repeat in a given string.
  char *copy = strdup(text);
  char *buf = calloc(strlen(text), sizeof(char));
  char *copy_p = copy;
  char *buf_start = buf;
  char *buf_end = buf;
  int flag = 0;
  int duplicates = 0;
  for(int i = 0; i < strlen(copy); i++) {
    copy[i] = tolower(copy[i]);
  }
  //iterate through our string
  for(int i = 0; i < strlen(copy); i++) {
    //check each element further in the string
    for(int j = i+1; j < strlen(copy); j++) {
      //if there is a character match
      if ( copy[i] == copy[j] ) {
        //iterate through our duplicates array buf and check to see if it is already there
        int flag = 0;
        //We use two pointers to keep track of our current position in the duplicates array and the end of the duplicates array.
        while (buf_start != buf_end) {
          //copy[i] contains the duplicate letter, and *buf_start provides us with the character at the current position in the array duplicate array
          //NOTE that when comparing something to something being pointed to, compare it to the pointer of the char.
          //If the duplicate char in the string is already in the duplicate array, set a flag to skip it.
          if (copy[i] == *buf_start) {
            flag = 1;
            break;
          }

          buf_start++;
        }
        //if the flag hasn't been set, then we can add the char into the duplicate array and increase the duplicate count by 1.
        if (flag == 0) {
          strncpy(buf_end, copy_p+i, 1);
          duplicates += 1;
          buf_end += sizeof(char);
        }
        buf_start = buf;
      }
    }
  }
  //printf("text %s duplicates: %d\n\n\n", text, duplicates);
  return duplicates;
}

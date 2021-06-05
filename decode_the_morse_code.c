#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};  
const char *ascii[55] = {"A",  "B",    "C",    "D",   "E", "F",    "G",   "H",    "I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",   "T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",     "3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",      ",",      "?",      "'",      "!",      "/",     "(",     ")",      "&",     ":",      ";",      "=",     "+",     "-",      "_",      "\"",     "$",       "@",      "SOS"};

char *decode_morse(const char* morse_code) {

  char *buf = calloc(strlen(morse_code), 1);
  char *b = buf;
  char *copy = strdup(morse_code);
  //strtok() makes changes to the original string, so its important to call it on a copy of the original string.
  char *tok = strtok(copy, " ");
  
  while(tok) {
    for(int i = 0; i < sizeof(morse)/sizeof(morse[0]); i++) {
      //strcmp outputs the number of differences between two strings, so !strcmp is actually a match !0 == !False == True
      if(!strcmp(tok, morse[i])) {
        if (tok != NULL) {
          printf("%s", tok);
        }
        //Copy the ascii equivalent of the morse code
        strcpy(b, ascii[i]);
        //Shift the pointer to point to the next available slot in buf
        b += strlen(ascii[i]);
        printf("%s\n", ascii[i]);
        break;
      }
    }
    //At this point, we can't call
    //print("tok is %d\n", tok);
    //This is
    
    //previous strtok replaced 1st space found with terminator, so look for another space *(tok-1) to find words
    //if tok is the first token after where we left off and before that is a ' '
    //Example for the case "HEY JUDE"
    //tok left off at Y, so the next tok will be J i.e. the below printf's will print tok is 'J'
    if ((tok = strtok(NULL, " ")) && *(tok-1) == ' ')
    {
      printf("tok is %s\n", tok);
      printf("tok is %s\n", tok-1);
      *b++ = ' '; 
    }
  }
  printf("%s\n", buf);
  //free(copy);
  return buf;

}

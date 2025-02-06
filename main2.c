#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>


int countWords(const char *sentence) {
    int wordCount = 0;
    int inWord = 0;

    while (*sentence != '\0') {
        if (!isspace(*sentence)) {
            if (!inWord) {
                wordCount++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
        sentence++;
    }

    return wordCount;
}

void sort_chars(char *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int compare(char *str1, char *str2) {
    int res;



    res = strcmp(str1, str2);
    return res;
}

char *process(char *str) {

    int s_len = strlen(str);
    char *res = calloc(s_len + 1, sizeof(char));

    int count_words = countWords(str);
    printf("колличество слов - %i\n", count_words);
    char* words[count_words];
    char* token;
    token = strtok(str, " ");

    int wordCount = 0;
    while (token != NULL && wordCount < count_words) {
        words[wordCount] = malloc(strlen(token) + 1);
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            printf("%d: %s\n", i + 1, words[i]);
            printf("%d: %s\n", j + 1, words[j+1]);
            printf("===\n");

            if (compare(words[j], words[j + 1]) > 0) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
 

    printf("новая последовательность:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%d: %s\n", i + 1, words[i]);
    }


    strcpy(res, "");
    for (int i = 0; i < wordCount; i++) {
        strcat(res, words[i]);
        if (i < wordCount - 1) {
            strcat(res, " ");
        }
    }

    printf("резудьтат - %s\n", res);


    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }

    return 0;
    
}


//char *process1(const char *str) {
  //  char *s = strdup(str);
   // int s_len = strlen(s);
    //char *res = calloc(s_len + 1, sizeof(char));
   // int len = 0;
   // char *word = strtok(s, " "); 
   // while (word != NULL) {
   
   //     printf("слово: \"%s\"\n", word);

     //   int w_len = strlen(word);
    //    printf("debug %i\n", w_len);
      //  if (w_len > 0) {
//    memcpy(res + len, word + 1, w_len + sizeof(char));
  //          len += w_len;
    //        res[len] = ' ';
      //      ++len;
       // }


      //  word = strtok(NULL, " "); 

   // }


  //  free(s);
  //  if (len > 0) {
   //     --len;
  //  }
  //  res[len] = '\0';
   // res = realloc(res, (len + 1) * sizeof(char) );
  //  return res;
// }



int main() {
    
    while (1) {
        char *input = readline("введите последовательность \n");
        if (input == NULL) {
            break;
        }
        char *output = process(input);

        free(input);
        free(output);
    }
    return 0;
}
#include <iostream>
#include <string.h>
using namespace  std;

int main() {
    int size, count=0;
    cin>>size;
    cin.ignore();

    char* text = new char[size+1];
    char** wordsToRemove = new char*[10];

    cin.getline(text, size+1);

    char currentWord[10];
    cin>>currentWord;

    while(strcmp(currentWord, "stop") != 0) {
        wordsToRemove[count] = new char[strlen(currentWord)+1];
        strcpy(wordsToRemove[count++], currentWord);
        cin>>currentWord;
    }

    char* occurrences;
    for (int i = 0; i < count; i++) {
        occurrences = strstr(text, wordsToRemove[i]);
        while (occurrences != nullptr) { // Find and remove all occurrences of the word
            memmove(occurrences, occurrences + strlen(wordsToRemove[i]), strlen(occurrences + strlen(wordsToRemove[i])) + 1);
            occurrences = strstr(occurrences, wordsToRemove[i]); // Move to the next occurrence
        }
    }

    cout << "Text after removing words:" << endl;
    cout << text << endl;

    delete[] text;
    for (int i = 0; i < count; ++i) {
        delete[] wordsToRemove[i];
    }
    delete[] wordsToRemove;

    return 0;
}

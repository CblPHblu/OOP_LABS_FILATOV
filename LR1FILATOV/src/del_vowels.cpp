#include "../include/del_vowels.h"

string del_vowels(string comment)
{
    char vowels[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y', '\0'};
    bool not_vowel = true;
    string rez;

    for (size_t i = 0; i < comment.length(); i++){
        
        for (size_t j = 0; j < 12; j++){
            if (comment[i] == vowels[j]){
                not_vowel = false;
            }
        }
        
        if (not_vowel){
            rez += comment[i];;
        }

        not_vowel = true;
    }
    return rez;
}

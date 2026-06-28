#include <assert.h>
#include <stdio.h>

void eliminate(char str[], char ch) {
    int i = 0;
    
    int j = 0;
    
    int found = 0;
    
    while (str[i] != '\0') {
        if (str[i] == ch) {
            j = i;
            found = 1;
            i++;
            break;
        }
        
        i++;
    }
    
    assert(found);
    
    while (str[i] != '\0') {
        str[j] = str[i];
        
        j++;
        i++;
    }
    
    str[j] = '\0';   
}

int main() {
    char str[] = "ABBA";
    eliminate(str, 'A');
    printf("%s", str);
}
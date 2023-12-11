#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "hello world";
    int count[26] = {0};
    int length = strlen(string);
    int i;
    
    for (i = 0; i < length; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            count[string[i] - 'a']++;
        }
    }
    
    for (i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            printf("'%c' appears %d times\n", i + 'a', count[i]);
        }
    }
    
    return 0;
}






#pragma once

uint32_t strlen(char* a)
{

    uint32_t length = 0;

    for(char* i = a; *i != '\0' ;i++)
    {
        length++;
    }


    return length;


}

char* reverseStr(char* str)
{


    uint8_t length = strlen(str);

    char buf;
    char* end = str + strlen(str) - 1;


    for(int i = 0; i < (strlen(str) / 2); i++)
    {
        buf = str[i];
        str[i] = *end;
        *end = buf;
        end--;
    }

    
    *(str + length) = '\0';
    
    return str;

}

uint32_t cmpstr(char* a,char* b)
{

    uint32_t lengtha = strlen(a);
    uint32_t lengthb = strlen(b);
    
    if(lengtha != lengthb)
        return 0;

    for(char* i = a; *i != '\0' ;i++)
    {
        if(*a != *b)
            return 0;
        a++;
        b++;
    }

    return 1;		
}


void printNum32(uint32_t x)
{

    static char strNum[10];

    for(int i = 10; i >= 10; i++)
    {
        strNum[i] = x % 10;
        x = x / 10;
    }

}

char* int_to_str(int x, char* buf)
{

    int i = 0;

    for(i = 0; x != 0; i++)
    {
        buf[i] = (x % 10) + 48;
        x = x / 10;
    }

    *(buf + i + 1) = '\0';

    buf = reverseStr(buf);
    
    return buf;

}

char* toupper(char* str)
{

    for(char* i = str; *i != '\0'; i++)
    {
        if(*i >= 'a' && *i <= 'z')
            *i -= 32;
    
    }

    return str;

}

char* tolower(char* str)
{
    for(char* i = str; *i != '\0'; i++)
    {
        if(*i >= 'A' && *i <= 'Z')
            *i += 32;
    
    }

    return str;
}


char* int_to_hex_str(int x, char* buf)
{

    char hex_values[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

    int i = 0;

    for(i = 0; x != 0; i++)
    {
        buf[i] = hex_values[x % 16];
        x = x / 16;
    }

    *(buf + i + 1) = '\0';

    buf = reverseStr(buf);
    
    return buf;

}

char* int_to_oct_str(int x, char* buf)
{
    int i = 0;

    for(i = 0; x != 0; i++)
    {
        buf[i] = (x % 8) + 48;
        x = x / 8;
    }

    *(buf + i + 1) = '\0';

    buf = reverseStr(buf);
    
    return buf;
}

char* strcpy(char* dest, char* src)
{
    while(*src)
    {
        *dest = *src;
        dest++;
        src++;
    }

    *(++dest) = '\0';
    return dest;

}
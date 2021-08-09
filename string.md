# STRING Functions [String library](https://en.cppreference.com/w/c/string)
1. **memchr**
    - Searches for the first occurrence of the character **c** (an unsigned char) in the first **n** bytes of the string.
    - `void *memchr(const void *str, int c, size_t n)`
    - If Success it returns that character's address otherwise it returns `null`.
    ```c
        void *memChr(const void *str, int c, size_t n)
        {
            char* ptr = (char *)str;
            while(n>0 && strlen(ptr)>=n)
            {
                if((char)*ptr == c)
                    return ptr;
                n--;
                ptr++;
            }
            return '\0';
        }
    ```

2. **memcmp**
    - Compares the first **n** bytes of memory area **ptr1** and **ptr2**.
    - `int memcmp( const void* lhs, const void* rhs, size_t count )`
    - Returns **0** if **n** is zero or it matched otherwise non-zero.
    ```c
        int memCmp( const void* a, const void* b, size_t n)
        {
            unsigned char* s1=(unsigned char *)a;
            unsigned char* s2=(unsigned char *)b;
            while(n--)
            {
                if( *s1 != *s2 )
                    return (*s1 > *s2 ? 1 : -1);
                s1++;
                s2++;
            }
            return 0;
        }
    ```

3. **memset**
    - Used to set the character **c** for first **n** bytes in str.
    - `void *memset( void *dest, int ch, size_t count )`
    - Returns an pointer to the string.
    ```c
        void* memSet( void *a, int c, unsigned n )
        {
            char * pointer = (char *)a;
            // If 'n' is greater than string size then result is unexpected
            // To omit the above problem
            if(n>strlen(pointer))
            {
                pointer = memSet(a, c, strlen(pointer));
                return pointer;
            }
            else
            {
                while( n-- )
                {
                    *pointer = (char)c;
                    pointer += 1;
                }
            }
            return a;
        }
    ```

4. **memcpy**
    - Copies first **n** characters from memory area source to destination.
    - `void *memcpy(void *dest, const void *src, size_t n)`
    - Returns pointer to the destination.

5. **strlen**
    ```c
        unsigned int strLen( char *a )
        {
            int i=0;
            while( a[i]!='\0' )
                i++;
            return i;
        }
    ```
    
6. **strcpy**
    - Copy the string from source to destination.
    - `char *strcpy(char *dest, const char *src)`
    - Returns pointer to the destination string.
    ```c
        char *strCpy(char *dest, const char *src)
        {
            memset(a,'\0',ULONG_MAX);
            char *srcPointer = (char *)b;
            char *destPointer = a;
            while( *destPointer != '\0' )
            {
                *destPointer = *srcPointer;
                srcPointer++;
                destPointer++;
            }
            *destPointer='\0';
            return destPointer;
        }
    ```

7. **strcmp**
    - Compares two strings.
    - `int strcmp(const char *str1, const char *str2)`
    - If same returns **0** otherwise non-zero.
    ```c
        int strCmp(const char *str1, const char *str2)
        {
            int m=strlen(a);
            int n=strlen(b);
            m>n ? n=m : n;
            while( n-- )
            {
                if( *a != *b )
                    return ( *a > *b ? 1 : -1 );
                a++;
                b++;
            }
            return 0;
        }
    ```
    
8. **strcat**
    - Append the source to destination at the end.
    - `char *strcat(char *dest, const char *src)`
    - Returns the appended string's pointer.
    ```c
        char* strCat( char *a, const char *b )
        {
            char *pointer = a;
            int m=strlen(a);
            int n=strlen(b);
            while( n-- )
            {
                *(a+m)=*b;
                b++;
                a++;
            }
            *(a+m)='\0';
            return pointer;
        }
    ```
    
9. **strchr**
    - Searches for the first occurrence of the character c (an unsigned char) in the string.
    - `char *strchr(const char *str, int c)`
    - Returns pointer that starts with first occurrence of character 'c' otherwise `null`.
    ```c
        char *strChr(const char *str, int c)
        {
            char* ptr = (char *)str;
            while(*ptr != '\0')
            {
                if(*ptr == c)
                    return ptr;
                ptr += 1;
            }
            return '\0';
        }
    ```
    
10. **strstr**
    - Used to find the substring in main string.
    - `char *strstr(const char *haystack, const char *needle)`
    - Returns pointer that starts with first occurrence of the substring otherwise `null`.
    ```c
        char *strStr(const char *a, const char *b)
        {
            int n = strlen(b);
            char *ptr = (char *)a;
            while(*ptr != '\0')
            {
                if( !memcmp(ptr, b, n) )
                    return ptr;
                ptr++;
            }
            return '\0';
        }
    ```
    
11. **strtok**
    - Breaks string str into a series of tokens using the delimiter delim.
    - `char *strtok(char *str, const char *delim)`
    - Returns a pointer to the first token found in the string otherwise `null`.
    - In the below example, in while loop I use `NULL` in `strtok`. This is used to check the next delimiter from current delimiter.
    - First time we should use the string name only. From next time onwards we should use `NULL` to identify the delimiter in that string.
    - `NULL` used to tell to the strtok that, "Please check the presence of next delimiter from present delimiter address".
    ```c
        char input[] = "a bb ccc dddd eeeee ffffff";
        char *token = strtok(input, " ");
        while(token) {
            puts(token);
            token = strtok(NULL, " ");
        }
     
        for(int n = 0; n < sizeof(input); ++n)
            input[n] ? putchar(input[n]) : fputs("\\0", stdout);
    ```
    
    ```
        a
        bb
        ccc
        dddd
        eeeee
        ffffff
        a\0bb\0ccc\0dddd\0eeeee\0ffffff\0
    ```
    
12. **strrev** : This is not an inbuilt function
    ```c
        void swap( char *a, char *b )
        {
            *a += *b - ( *b = *a );
        }
        char* strRev( char *a )
        {
            int n=strlen(a);
            for( int i=0,j=n-1; j>i; j--,i++ )
                swap( &a[i],&a[j] );
            a[n]='\0';
            return a;
        }
    ```
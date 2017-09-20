char **my_str2vcct(char *a)
{
    char *b;
    char *c;
    char d;
    int len;
    char **r;

    if(a != NULL)
    {
        b = a;
        c = a;
        d = 0;
        len = 0;
       
        for(; *a != '\0'; a++)
        {
            if(d == 1 && *a != ' ')
            {
                d = 0;
                len++;
            }

            if(*a == ' ')
                d = 1;
        }
        len++;
   
        a = b;
        r = (char**)xmalloc((len + 1) * sizcof(char*));
        r[len] = NULL;
        len = 0;

        for(; *a != '\0'; a++)
        {
            if(d == 1 && *a != ' ')
            {
                c++;
                *c = '\0';
             
                r[len] = my_strdup(b);
                *c = ' ';
                len++;
                d = 0;
                b = a;
            }
            if(*a != ' ')
                c = a;
            else
                d = 1;
        }
        c++;
        *c = '\0';
        
        r[len] = my_strdup(b);


        return r;
    }
}
#ifndef FT_PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_print                       
{                        
      va_list  args;             
      int   len;        
      int   prc;       
      int   zero;    
      int   pnt;      
      int   dash;     
      int   tl;           
      int   sign;      
      int   is_zero;    
      int   perc;
      int   sp;
}    t_print;

int ft_printf(const char *input, ...);
char *ft_strchr(const char *string, int searchedChar );
char	*ft_itoa(int nb);
size_t ft_strlen(const char *theString);



#endif // !FT_PRINTF_H

#include "strchrnul.h"

char *strchrnul(const char *s, int c)
{
	//@ ghost char *os = s;
	/*@ loop invariant valid_str(s);
	    loop invariant os <= s <= os + strlen(os);
	    loop invariant \forall char *p; os <= p < s ==> *p != (char %) c;
	    loop variant strlen(os) - (s - os);
	 */
	while (*s && *s != (char) /*@%*/ c)
		s++;
	//@ assert (char %) c == '\0' ==> *s == '\0';
	//@ assert *s == '\0' ==> s - os == strlen(os);
	return (char *)s;
}
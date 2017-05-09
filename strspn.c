#include "strspn.h"

size_t strspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	size_t count = 0;

	/*@ loop invariant s <= p <= s + strlen(s);
	    loop invariant 0 <= count <= strlen(s);
	    loop invariant count == p - s;
	    loop invariant \forall char *c; s <= c < p ==>
	                   (\exists char *t; accept <= t < accept + strlen(accept) && *c == *t);
	    loop variant strlen(s) - (p - s);
	 */
	for (p = s; *p != '\0'; ++p) {
		/*@ loop invariant accept <= a <= accept + strlen(accept);
		    loop invariant \forall char *c; accept <= c < a ==> *c != *p;
		    loop variant strlen(accept) - (a - accept);
		 */
		for (a = accept; *a != '\0'; ++a) {
			if (*p == *a)
				break;
		}
		if (*a == '\0')
			return count;
		++count;
	}
	return count;
}
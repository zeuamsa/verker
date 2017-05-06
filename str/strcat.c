#include "strcat.h"

/*@ requires valid_str(src);
    requires valid_str(dest);
    requires \valid(dest+(0..strlen(dest)+strlen(src))); //-1
    assigns dest[strlen(dest)..strlen(dest)+strlen(src)-1]; //-1
    ensures \result == dest;
    ensures valid_str(\result);
    ensures \forall integer i; 0 <= i < strlen(\old(dest)) ==>
            dest[i] == \result[i];
    ensures \forall integer i;
            strlen(\old(dest)) <= i < strlen(\old(dest)) + strlen(src) ==>
            src[i - strlen(\old(dest))] == \result[i];
 */
char *strcat(char *dest, const char *src)
{
	char *tmp = dest;

	//@ assert valid_str(tmp);
	//@ ghost size_t dest_len = strlen(tmp);

	/*@ loop invariant tmp <= dest <= tmp + dest_len;
	    loop invariant valid_str(dest);
	    loop variant dest_len - (dest - tmp);
	 */
	while (*dest)
		dest++;
	//@ assert *dest == '\0';
	//@ assert dest == tmp + dest_len;
	//@ ghost char *osrc = src;
	//@ ghost char *mdest = dest;

	/*@ loop invariant osrc <= src <= osrc + strlen(osrc);
	    loop invariant mdest <= dest <= mdest + strlen(osrc);
	    loop invariant src - osrc == dest - mdest;
	    loop invariant valid_str(src);
	    loop invariant \forall integer i; 0 <= i < src - osrc ==>
	                   mdest[i] == osrc[i];
	    loop assigns mdest[0..strlen(osrc)];
	    loop variant strlen(osrc) - (src - osrc);
	 */
	while ((*dest++ = *src++) != '\0')
		;
	//@ assert dest[-1] == '\0' && src[-1] == '\0';
	//@ assert dest - 1 == tmp + dest_len + strlen(osrc);
	//@ assert tmp == \at(dest,Pre);
	return tmp;
}

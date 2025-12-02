#include "arr.h"
#include "defs.h"
#include <malloc.h>
#include <math.h>


void rsz_arr_f ( struct generic_arr ptr arr , u8 sz )
{
	u64 spowmul = arr->powmul * arr->powmul;
	if ( spowmul < arr->len )
	{
		++arr->powmul;
	retry:;
		void * inb = realloc ( arr->get , sz * ( arr->powmul * arr->powmul ));
		if ( inb )
		{
			arr->get = inb;
		}
		else
		{
			printf ( "Failed to resize array! Retrying. This may cause a loop.");
			goto retry;
		}
	}
}

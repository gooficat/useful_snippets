#include "arr.h"
#include "defs.h"
#include <malloc.h>
#include <math.h>


void rsz_arr_f ( struct generic_arr ptr arr , u8 sz )
{
	u64 spowmul = pow ( 2 , arr->powmul );
	if ( spowmul < arr->len )
	{
		while ( ( spowmul = pow ( 2, ++arr->powmul ) ) < arr->len );
	retry:;
		void * inb = realloc ( arr->get , sz * spowmul );
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

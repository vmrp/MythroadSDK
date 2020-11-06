/*
========================
=
= FixedByFrac (FixedMul)
=
= multiply two 16/16 bit, 2's complement fixed point numbers
=
========================
*/
#ifdef __ARM7_C
typedef __int64 int64_t;
		long FixedByFrac(long a, long b)
		{
			int64_t ra = a;
			int64_t rb = b;
			int64_t r;
			
			r = ra * rb;
			r >>= TILESHIFT;
			return (long)r;
		}
#endif

#ifdef __WIN32_C
typedef _int64 int64_t;
		long FixedByFrac(long a, long b)
		{
			int64_t ra = a;
			int64_t rb = b;
			int64_t r;
			
			r = ra * rb;
			r >>= TILESHIFT;
			return (long)r;
		}
#endif

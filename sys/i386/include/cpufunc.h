/*
 * Functions to provide access to special i386 instructions.
 * XXX - bezillions more are defined in locore.s but are not declared anywhere.
 *
 *	$Id: cpufunc.h,v 1.5 1993/11/25 01:31:07 wollman Exp $
 */

#ifndef _MACHINE_CPUFUNC_H_
#define _MACHINE_CPUFUNC_H_ 1

#include <sys/cdefs.h>
#include <sys/types.h>

#ifdef	__GNUC__

static inline int bdb(void)
{
	extern int bdb_exists;

	if (!bdb_exists)
		return (0);
	__asm("int $3");
	return (1);
}

static inline void
disable_intr(void)
{
	__asm __volatile("cli");
}

static inline void
enable_intr(void)
{
	__asm __volatile("sti");
}

/*
 * This roundabout method of returning a u_char helps stop gcc-1.40 from
 * generating unnecessary movzbl's.
 */
#define	inb(port)	((u_char) u_int_inb(port))

static inline u_int
u_int_inb(u_int port)
{
	u_char	data;
	/*
	 * We use %%dx and not %1 here because i/o is done at %dx and not at
	 * %edx, while gcc-2.2.2 generates inferior code (movw instead of movl)
	 * if we tell it to load (u_short) port.
	 */
	__asm __volatile("inb %%dx,%0" : "=a" (data) : "d" (port));
	return data;
}

static inline void
outb(u_int port, u_char data)
{
	register u_char	al asm("ax");

	al = data;		/* help gcc-1.40's register allocator */
	__asm __volatile("outb %0,%%dx" : : "a" (al), "d" (port));
}

static inline
int
imin(a, b)
	int a, b;
{

	return (a < b ? a : b);
}

static inline
int
imax(a, b)
	int a, b;
{

	return (a > b ? a : b);
}

static inline
unsigned int
min(a, b)
	unsigned int a, b;
{

	return (a < b ? a : b);
}

static inline
unsigned int
max(a, b)
	unsigned int a, b;
{

	return (a > b ? a : b);
}

static inline
long
lmin(a, b)
	long a, b;
{

	return (a < b ? a : b);
}

static inline
long
lmax(a, b)
	long a, b;
{

	return (a > b ? a : b);
}

static inline
unsigned long
ulmin(a, b)
	unsigned long a, b;
{

	return (a < b ? a : b);
}

static inline
unsigned long
ulmax(a, b)
	unsigned long a, b;
{

	return (a > b ? a : b);
}

static inline
int
ffs(mask)
	register long mask;
{
	register int bit;

	if (!mask)
		return(0);
	for (bit = 1;; ++bit) {
		if (mask&0x01)
			return(bit);
		mask >>= 1;
	}
}

static inline
int
bcmp(v1, v2, len)
	void *v1, *v2;
	register unsigned len;
{
	register u_char *s1 = v1, *s2 = v2;

	while (len--)
		if (*s1++ != *s2++)
			return (1);
	return (0);
}

static inline
size_t
strlen(s1)
	register const char *s1;
{
	register size_t len;

	for (len = 0; *s1++ != '\0'; len++)
		;
	return (len);
}

#else /* not __GNUC__ */

int	bdb		__P((void));
void	disable_intr	__P((void));
void	enable_intr	__P((void));
u_char	inb		__P((u_int port));
void	outb		__P((u_int port, u_int data));	/* XXX - incompat */

#endif	/* __GNUC__ */

#define	really_u_int	int	/* XXX */
#define	really_void	int	/* XXX */

void	load_cr0	__P((u_int cr0));
really_u_int	rcr0	__P((void));

#ifdef notyet
really_void	setidt	__P((int idx, /*XXX*/caddr_t func, int typ, int dpl));
#endif

#undef	really_u_int
#undef	really_void

#endif /* _MACHINE_CPUFUNC_H_ */

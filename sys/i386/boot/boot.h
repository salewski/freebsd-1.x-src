/*
 * Ported to boot 386BSD by Julian Elischer (julian@tfs.com) Sept 1992
 *
 * Mach Operating System
 * Copyright (c) 1992, 1991 Carnegie Mellon University
 * All Rights Reserved.
 * 
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 * 
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 * 
 * Carnegie Mellon requests users of this software to return to
 * 
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 * 
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 */

/*
 * HISTORY
 * $Log: boot.h,v $
 * Revision 1.2  1993/07/13 18:15:25  root
 * New boot blocks, from Bruce Evans, and NetBSD fixes.  Allows kernel to
 * be loaded above 1MB.  Same boot code for floppies now.  Speed improvements.
 * etc etc etc. (I don't have much history on this, but then have been tested)
 *
 * Revision 1.1  1993/03/21  18:08:29  cgd
 * after 0.2.2 "stable" patches applied
 *
 * Revision 2.2  92/04/04  11:35:03  rpd
 * 	Fabricated from 3.0 bootstrap.  But too many things are global.
 * 	[92/03/30            mg32]
 * 
 */

#include <sys/types.h>
#include <sys/param.h>
#include <ufs/quota.h>
#include <ufs/fs.h>
#include <ufs/inode.h>

extern char *devs[], *name, *iodest;
extern struct fs *fs;
extern struct inode inode;
extern int dosdev, unit, part, maj, boff, poff, bnum, cnt;
extern	long int	ouraddr;

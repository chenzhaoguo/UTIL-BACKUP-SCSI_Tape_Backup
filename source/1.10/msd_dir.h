/*****************************************************************************
 * $Id: msd_dir.h,v 1.2 1992/09/02 20:08:24 ak Exp $
 *****************************************************************************
 * $Log: msd_dir.h,v $
 * Revision 1.2  1992/09/02  20:08:24  ak
 * Version AK200
 * - Tape access
 * - Quick file access
 * - OS/2 extended attributes
 * - Some OS/2 fixes
 * - Some fixes of Kai Uwe Rommel
 *
 * Revision 1.1.1.1  1992/09/02  19:22:05  ak
 * Original GNU Tar 1.10 with some filenames changed for FAT compatibility.
 *
 * Revision 1.1  1992/09/02  19:22:03  ak
 * Initial revision
 *
 *****************************************************************************/

/*
 * @(#)msd_dir.h 1.4 87/11/06	Public Domain.
 *
 *  A public domain implementation of BSD directory routines for
 *  MS-DOS.  Written by Michael Rendell ({uunet,utai}michael@garfield),
 *  August 1897
 */

#define	rewinddir(dirp)	seekdir(dirp, 0L)

#define	MAXNAMLEN	12

#ifdef __TURBOC__
typedef int ino_t;
typedef int dev_t;
#endif

struct direct {
	ino_t	d_ino;			/* a bit of a farce */
	int	d_reclen;		/* more farce */
	int	d_namlen;		/* length of d_name */
	char	d_name[MAXNAMLEN + 1];		/* garentee null termination */
};

struct _dircontents {
	char	*_d_entry;
	struct _dircontents	*_d_next;
};

typedef struct _dirdesc {
	int		dd_id;	/* uniquely identify each open directory */
	long		dd_loc;	/* where we are in directory entry is this */
	struct _dircontents	*dd_contents;	/* pointer to contents of dir */
	struct _dircontents	*dd_cp;	/* pointer to current position */
} DIR;

extern	DIR		*opendir();
extern	struct direct	*readdir();
extern	void		seekdir();
extern	long		telldir();
extern	void		closedir();

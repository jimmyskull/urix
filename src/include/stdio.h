/**
 * @file stdio.h
 * @brief Standard buffered input/output.
 * @author Paulo Urio
 * @date 2012
 * @copyright FreeBSD License
 */

#ifndef _STDIO_H_
#define _STDIO_H_

#include <stddef.h>

#define	BUFSIZ		4096	/** Size of stdio.h buffers */
#define	EOF		(-1)	/**< End-of-file return value */

/** Maximum size in bytes of the longest filename string that the
 * implementation guarantees can be opened. */
#define	FILENAME_MAX	NAME_MAX
/** Number of streams which the implementation guarantees can be open
 * simultaneously. The value will be at least eight. */
#define	FOPEN_MAX	20
/** Minimum number of unique filenames generated by tmpnam(). Maximum number of times an application can call tmpnam() reliably. The value of TMP_MAX will be at least 10,000. */
#define	TMP_MAX

/** @{ */
#define	_IOFBF		0x000	/**< Input/output fully buffered */
#define	_IOLBF		0x001	/**< Input/output line buffered */
#define	_IONBF		0x002	/**< Input/output unbuffered */
/** @} */

/** @{ */
/** Maximum size of character array to hold ctermid() output. */
#define	L_ctermid
/** Maximum size of character array to hold cuserid() output. (LEGACY) */
#define	L_cuserid
/** Maximum size of character array to hold tmpnam() output. */
#define	L_tmpnam
/** @} */

/* SEEK_CUR, SEEK_END and SEEK_SET are defined also in unistd.
 * POSIX looks like a mess. */

/** @{ */
/* The following macro name is defined as a string constant: */
#define P_tmpdir	"/tmp"	/**< Default directory prefix for tempnam() */
/** The size needed for an array of char large enough to hold a temporary file
 * name string generated by the tmpnam function */
#define	L_tmpnam	(sizeof(P_tmpdir) + 1 + FILENAME_MAX)
/** @} */

/** @{ */
/* The following macro names are defined as expressions of type pointer
 * to FILE: */
#define stderr	/**< Standard error output stream */
#define stdin	/**< Standard input stream */
#define stdout	/**< Standard output stream */
/** @} */

/** A structure containing information about a file */
typedef struct __iobuf {
	int		_count;
	int		_fd;
	int		_flags;
	int		_bufsiz;
	unsigned char	*_buf;
	unsigned char	*_ptr;
} FILE;

/** Type containing all information needed to specify uniquely every position
 * within a file */
typedef long int	fpos_t;

extern FILE __stdin, __stdout, __stderr;

#endif /* _STDIO_H_ */
/* confdefs.h */
#define PACKAGE_NAME "LuminariMUD"
#define PACKAGE_TARNAME "luminarimud"
#define PACKAGE_VERSION "2.5002-beta"
#define PACKAGE_STRING "LuminariMUD 2.5002-beta"
#define PACKAGE_BUGREPORT "bugs@luminarimud.com"
#define PACKAGE_URL ""
#define PACKAGE "luminarimud"
#define VERSION "2.5002-beta"
#define CIRCLE_UNIX 1
#define CIRCLE_CRYPT 1
#define HAVE_JSON_C 1
#define HAVE_STDIO_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_STRINGS_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_UNISTD_H 1
#define STDC_HEADERS 1
#define HAVE_SYS_WAIT_H 1
#define HAVE_FCNTL_H 1
#define HAVE_SYS_FCNTL_H 1
#define HAVE_ERRNO_H 1
#define HAVE_STRING_H 1
#define HAVE_STRINGS_H 1
#define HAVE_LIMITS_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_SELECT_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_UNISTD_H 1
#define HAVE_MEMORY_H 1
#define HAVE_CRYPT_H 1
#define HAVE_ASSERT_H 1
#define HAVE_ARPA_TELNET_H 1
#define HAVE_ARPA_INET_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_SOCKET_H 1
#define HAVE_SYS_RESOURCE_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_NETDB_H 1
#define HAVE_SIGNAL_H 1
#define HAVE_SYS_UIO_H 1
#define HAVE_MCHECK_H 1
#define HAVE_TIME_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_DECL_STRUCT_TIMEVAL 0
#define HAVE_STRUCT_IN_ADDR 1
#define HAVE_VPRINTF 1
#define HAVE_GETTIMEOFDAY 1
#define HAVE_SELECT 1
#define HAVE_SNPRINTF 1
#define HAVE_STRCASECMP 1
#define HAVE_STRDUP 1
#define HAVE_STRERROR 1
#define HAVE_STRLCPY 1
#define HAVE_STRNCASECMP 1
#define HAVE_STRSTR 1
#define HAVE_VSNPRINTF 1
#define HAVE_INET_ADDR 1
/* end confdefs.h.  */
/* Define inet_aton to an innocuous variant, in case <limits.h> declares inet_aton.
   For example, HP-UX 11i <limits.h> declares gettimeofday.  */
#define inet_aton innocuous_inet_aton

/* System header to define __stub macros and hopefully few prototypes,
   which can conflict with char inet_aton (); below.  */

#include <limits.h>
#undef inet_aton

/* Override any GCC internal prototype to avoid an error.
   Use char because int might match the return type of a GCC
   builtin and then its argument prototype would still apply.  */
#ifdef __cplusplus
extern "C"
#endif
char inet_aton ();
/* The GNU C library defines this for functions which it implements
    to always fail with ENOSYS.  Some functions are actually named
    something starting with __ and the normal name is an alias.  */
#if defined __stub_inet_aton || defined __stub___inet_aton
choke me
#endif

int
main (void)
{
return inet_aton ();
  ;
  return 0;
}

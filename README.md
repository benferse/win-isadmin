# win-isadmin
A simple command line utility to tell if we're running as admin on Windows 7 and above. The semantics for how the administrator SID is filtered out on Vista make this trickier there, but [support for Vista has ended after all](https://support.microsoft.com/en-us/help/22882/windows-vista-end-of-support "RIP Vista").

Note that the return value follows expected exit status convention. A return of zero means you are in fact an administrator (i.e. the "is admin" check was successful), and non-zero if you aren't. Don't make the mistake of interpreting it as a boolean -_-
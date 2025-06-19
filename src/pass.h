#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#include <shobjidl.h>
std::string get_downloads_path() {
    PWSTR path_tmp = nullptr;
    std::string path; // GUID for Downloads

    const KNOWNFOLDERID folderid_downloads = FOLDERID_Downloads; // Use FOLDERID_Downloads to get the Downloads folder on Windows
    if (SUCCEEDED(SHGetKnownFolderPath(folderid_downloads, 0, NULL, &path_tmp))) {
        char charPath[MAX_PATH];
        wcstombs(charPath, path_tmp, MAX_PATH);
        path = std::string(charPath);
        CoTaskMemFree(path_tmp);
    }
    return path;
}
#else
std::string get_downloads_path() {
    std::string result;
    char buffer[256];
    FILE* pipe = popen("xdg-user-dir DOWNLOAD", "r"); // Use xdg-user-dir to get the Downloads directory on Linux
    if (!pipe) return ""; // If the pipe could not be opened, return an empty string
    if (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result = buffer;
        // Remove trailing newline character if present
        if (!result.empty() && result[result.size()-1] == '\n') result.pop_back(); 
    }
    pclose(pipe);
    return result;
}
#endif
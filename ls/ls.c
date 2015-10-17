#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>

void ls(const char* const path) {
    // recursively list the contents of directories, starting from 'path'.

    DIR *pDir;
    struct dirent *pFile;
    struct stat st;

    char pPathBuffer[PATH_MAX];
    int pathLen;

    pDir = opendir(path);
    while((pFile = readdir(pDir)) != NULL)
    {
        if (!strcmp(pFile->d_name, ".") || !strcmp(pFile->d_name, "..")) {
            continue;
        }

        pathLen = snprintf(
            pPathBuffer,
            PATH_MAX,
            "%s/%s",
            path,
            pFile->d_name);

        if (pathLen >= PATH_MAX) {
            printf("Long path name skipped: %s/%s", path, pFile->d_name);
            continue;
        }

        printf("%s", pPathBuffer);
        lstat(pPathBuffer, &st);
        if (S_ISDIR(st.st_mode)) {
            printf("/\n");
            ls(pPathBuffer);
        } else {
            printf("\n");
        }
    }
    closedir(pDir);
}

void main()
{
    ls(".");
}

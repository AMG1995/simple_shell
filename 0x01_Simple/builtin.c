#include "shell.h"

int _forexit(info_t *info) {
    if (info->argv[1]) {
        int exit_status = _erratoi(info->argv[1]);
        if (exit_status != -1) {
            info->err_num = exit_status;
            return -2;
        } else {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
        }
    }
    info->err_num = -1;
    return -2;
}

int _cd(info_t *info) {
    char *target_dir = (info->argv[1]) ? info->argv[1] : _getenv(info, "HOME=");
    char *current_dir;

    if (!target_dir) {
        _puts("HOME environment variable not set\n");
        return 1;
    }

    current_dir = getcwd(NULL, 0);
    if (!current_dir) {
        _puts("getcwd failure\n");
        return 1;
    }

    if (_strcmp(target_dir, "-") == 0) {
        target_dir = _getenv(info, "OLDPWD=");
        if (!target_dir) {
            _puts(current_dir);
            _putchar('\n');
            free(current_dir);
            return 0;
        }
    }

    if (chdir(target_dir) == -1) {
        print_error(info, "can't cd to ");
        _eputs(target_dir);
        _eputchar('\n');
        free(current_dir);
        return 1;
    }

    _setenv(info, "OLDPWD", current_dir);
    _setenv(info, "PWD", getcwd(NULL, 0));
    free(current_dir);
    return 0;
}

int _help(info_t *info) {
    _puts("Help: This is a simple shell. Not all features are implemented yet.\n");
    return 0;
}

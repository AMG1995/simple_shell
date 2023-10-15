#include "shell.h"

typedef struct env_var {
    char *name;
    char *value;
} env_var_t;

int _myenv(info_t *info) {
    print_list_str(info->env);
    return 0;
}

char *_getenvi(info_t *info, const char *name) {
    list_t *node = info->env;
    while (node) {
        env_var_t *env = (env_var_t *)node->ptr;
        if (strcmp(env->name, name) == 0) {
            return env->value;
        }
        node = node->next;
    }
    return NULL;
}

int _setenvi(info_t *info, const char *name, const char *value) {
    list_t *node = info->env;
    while (node) {
        env_var_t *env = (env_var_t *)node->ptr;
        if (strcmp(env->name, name) == 0) {
            free(env->value);
            env->value = strdup(value);
            return 0;
        }
        node = node->next;
    }
    // If not found, add it to the list
    env_var_t *new_env = malloc(sizeof(env_var_t));
    new_env->name = strdup(name);
    new_env->value = strdup(value);
    add_node_end(&info->env, new_env, 0);
    return 0;
}

int _unsetenvi(info_t *info, const char *name) {
    list_t *node = info->env;
    while (node) {
        env_var_t *env = (env_var_t *)node->ptr;
        if (strcmp(env->name, name) == 0) {
            free(env->name);
            free(env->value);
            free(env);
            delete_node_at_index(&info->env, node, 0);
            return 0;
        }
        node = node->next;
    }
    return 1; // Not found
}

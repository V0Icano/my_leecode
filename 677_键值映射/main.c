#include <string.h>
#include <stdlib.h>

struct list_node {
    struct list_node* next;
    char* key;
    int val;
};

typedef struct {
    struct list_node* node;
} MapSum;

/** Initialize your data structure here. */
MapSum g_list_head = {0};
MapSum* mapSumCreate() {
    return &g_list_head;
}

struct list_node* find_node_in_list(char* key, MapSum* obj)
{
    struct list_node* find_node = obj->node;
    while (find_node != NULL) {
        if (find_node->key == NULL) {
            find_node = find_node->next;
            continue;
        }
        if (strcmp(find_node->key, key) == 0) {
            return find_node;
        } else {
            find_node = find_node->next;
        }
    }
    return find_node;
}
struct list_node* get_last_node(MapSum* obj)
{
    struct list_node* temp_node = obj->node;

    while (temp_node != NULL) {
        if (temp_node->next == NULL) {
            return temp_node;
        }
        temp_node = temp_node->next;
    }
    return temp_node;
}

void mapSumInsert(MapSum* obj, char * key, int val) {
    struct list_node* node = NULL;
    size_t len = 0;
    struct list_node* last_node = NULL;
    if (obj == NULL || key == NULL) {
        return;
    }
    node = find_node_in_list(key, obj);
    if (node == NULL) {
        node = (struct list_node*)malloc(sizeof(struct list_node));
        #if 1
        if (node == NULL) {
            return;
        }
        memset(node, 0, sizeof(struct list_node));
        last_node = get_last_node(obj);
        if (last_node == NULL) {
            obj->node = node;
        } else {
            last_node->next = node;
        }
        #endif
    }
    if (node->key == NULL) {
        len = strlen(key) + 1;
        node->key = (char*)malloc(len);
        strcpy(node->key, key);
    }
    node->val = val;

}

int mapSumSum(MapSum* obj, char * prefix) {
    size_t len = 0;
    int sum = 0;
    struct list_node* temp_node = obj->node;

    if (obj == NULL || prefix == NULL) {
        return sum;
    }

    len = strlen(prefix);
    while (temp_node != NULL) {
        if (strncmp(temp_node->key, prefix, len) == 0) {
            sum += temp_node->val;
        }
        temp_node = temp_node->next;
    }
    return sum;
}

void list_free(struct list_node** temp_node)
{
    if (*temp_node == NULL) {
        return;
    }
    list_free(&((*temp_node)->next));
    free((*temp_node)->key);
    (*temp_node)->key = NULL;
    free(*temp_node);
    *temp_node = NULL;
}
void mapSumFree(MapSum* obj) {
    if (obj == NULL) {
        return;
    }
    list_free(&obj->node);
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);
 
 * int param_2 = mapSumSum(obj, prefix);
 
 * mapSumFree(obj);
*/
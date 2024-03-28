#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

typedef struct {
    GHashTable *hash;
    guint32 index;
    char *data;
} MonoDynamicStream;

void make_room_in_stream(MonoDynamicStream *sh, guint32 size) {
    // Implementation of make_room_in_stream function
    // ...
}

guint32 string_heap_insert(MonoDynamicStream *sh, const char *str) {
    guint32 idx;
    guint32 len;
    gpointer oldkey, oldval;

    if (g_hash_table_lookup_extended(sh->hash, str, &oldkey, &oldval))
        return GPOINTER_TO_UINT(oldval);

    len = strlen(str) + 1;
    idx = sh->index;
    make_room_in_stream(sh, idx + len);

    g_hash_table_insert(sh->hash, g_strdup(str), GUINT_TO_POINTER(idx));
    memcpy(sh->data + idx, str, len);
    sh->index += len;

    return idx;
}

int main() {
    // Create a MonoDynamicStream instance
    MonoDynamicStream stream;
    stream.hash = g_hash_table_new(g_str_hash, g_str_equal);
    stream.index = 0;
    stream.data = malloc(100 * sizeof(char)); // Adjust the size as needed

    // Test the string_heap_insert function
    const char *str = "Hello, world!";
    guint32 result = string_heap_insert(&stream, str);
    printf("Inserted string '%s' at index %u\n", str, result);

    // Clean up
    g_hash_table_destroy(stream.hash);
    free(stream.data);

    return 0;
}

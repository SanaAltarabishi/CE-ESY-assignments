#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 25

typedef struct {
    char buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} Buffer;

//التهيئة :
void init(Buffer *cb) {
    cb->head  = 0;
    cb->tail  = 0;
    cb->count = 0;
}

// لحالة الامتلاء :
int isFull(Buffer *cb) {
    return cb->count == BUFFER_SIZE;
}

// لحالة الفراغ :
int isEmpty(Buffer *cb) {
    return cb->count == 0;
}

// الكتابة :
void write_cb(Buffer *cb, char data) {
    if (isFull(cb)) {
        printf("Overflow Buffer is full'%c'\n", data);
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count++;
}

// القراءة :

char read_cb(Buffer *cb) {
    if (isEmpty(cb)) {
        printf("Underflow, Buffer is empty\n");
        return '\0';
    }
    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count--;
    return data;
}

int main() {
    Buffer cb;
    init(&cb);

    char name[100];
    char suffix[] = "CE-ESY";
    char full_name[110];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    int len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
        len--;
    }

    snprintf(full_name, sizeof(full_name), "%s%s", name, suffix);
    int total_len = strlen(full_name);

    printf("\nFull string to store: \"%s\" (%d characters)\n", full_name, total_len);
    printf("Buffer size: %d\n", BUFFER_SIZE);

    printf("Writing....\n");
    for (int i = 0; i < total_len; i++) {
        write_cb(&cb, full_name[i]);
    }

    printf("Characters stored : %d / %d\n", cb.count, BUFFER_SIZE);
    printf("Reading from buffer\n");
    printf("Output: ");
    while (!isEmpty(&cb)) {
        char c = read_cb(&cb);
        printf("%c", c);
    }
    printf("\n");


    if (isEmpty(&cb)) {
        printf("Buffer is now empty. All data has been read successfully.\n");
    }

    return 0;
}

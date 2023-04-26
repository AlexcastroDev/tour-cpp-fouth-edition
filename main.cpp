#include <iostream> // instruction to compiler include the standard Stream I/O
#include "square.h" // include the square class
#include "uv.h" // include the libuv library
#include <unistd.h>

using namespace std; // makes names from std visible without std::

typedef struct {
    uv_fs_t req;
    uv_buf_t buf;
    uv_loop_t *loop;
    void (*callback)(const char*);
} file_t;

file_t* file;

#define BUF_SIZE 1024

void on_open(uv_fs_t* open_req);

void on_close(uv_fs_t* req);

void on_read(uv_fs_t* req);

void readfile(uv_loop_t* loop, const char* filename, void (*callback)(const char*)) {
    file = (file_t*) malloc(sizeof(file_t));
    file->callback = callback;
    file->loop = loop;
    file->buf = uv_buf_init((char*) malloc(BUF_SIZE), BUF_SIZE);
    uv_fs_open(loop, &file->req, filename, O_RDONLY,0, (uv_fs_cb) on_open);
}

void on_read(uv_fs_t* open_req) {
    printf("File readed successfully!\n");
    int result = open_req->result;
    if (result < 0) {
        fprintf(stderr, "Read error: %s\n", uv_strerror(result));
    } else {
        file->callback(file->buf.base);
    }
    uv_fs_close(file->loop, &file->req, result, on_close);
}

void on_open(uv_fs_t* open_req) {
    if (open_req->result >= 0) {
        printf("File opened successfully!\n");
        uv_fs_read(file->loop, &file->req, open_req->result, &file->buf, 1, -1, on_read);
    }
}

void on_close(uv_fs_t* req) {
    uv_fs_req_cleanup(req);
}

char* get_project_root() {
    char cwd[1024];
    char* project_root = NULL;

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        return NULL;
    }

    // go up to parent directory recursively until we find a file or directory
    // that is unique to our project
    while (1) {
        // check if we found the project root
        if (access("CMakeLists.txt", F_OK) == 0) {
            project_root = strdup(cwd);
            break;
        }
        if (access(".git", F_OK) == 0) {
            project_root = strdup(cwd);
            break;
        }
        // go up to parent directory
        if (chdir("..") == -1) {
            perror("chdir() error");
            break;
        }
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd() error");
            break;
        }
    }

    return project_root;
}

// ReadFile implementation
int main() {
    uv_loop_t* loop = uv_default_loop();

    // Get the absolute path to the file
    char* cwd = get_project_root();
    char* filename = "/notes.md";
    char* path = new char[strlen(cwd) + strlen(filename) + 1];
    strcpy(path, cwd);
    strcat(path, filename);

    // Print file path
    printf("File path: %s\n", path);

    readfile(loop, path, [](const char* data) {
        printf("File contents: %s\n", data);
    });

    // Run the event loop
    uv_run(loop, UV_RUN_DEFAULT);

    // Clean up
    free(path);
    uv_loop_close(loop);

    return 0;
}


// SetInterval implementation
//int counter = 0;
//void on_timeout(uv_timer_t* handle) {
//    printf("Timeout!\n");
//    if(++counter >= 10) {
//        uv_timer_stop(handle);
//    }
//}

//int main() {
//    uv_loop_t *loop = uv_default_loop();
//    uv_timer_t timer;
//    uv_timer_init(loop, &timer);
//    uv_timer_start(&timer, on_timeout, 1000, 1000);
//    uv_run(loop, UV_RUN_DEFAULT);
//    uv_loop_close(loop);
//    }

// Class Triangle implementation

//double square(double x) {
//    return x * x;
//}

//void print_square(double x) {
//    cout << "The name of " << x << " is " << square(x) << "\n";
//}

//struct Triangle {
//    double base;
//    double height;
//};

//int main() {
//    //std::cout << "Hello"; // the operator << "put to" writes it seconds argument onto its first
//    cout << "Hello \n";
//    print_square(3.14);
//
//    // Types, variables and Arithmetic
//
//    // int [ ] [ ] [ ] [ ]
//    int value1 = 3;
//    cout << "Size of integer is: " << sizeof value1 << "\n"; // always 4 byte
//
//    // boolean  [ ]
//    bool value2 = false; // if set string, the stdout is "1", so boolean is 0 or 1
//    cout << "Size of boolean is: " << sizeof value2 << "\n"; // always 1 byte
//
//    // char  [ ]
//    char value3 = 'a'; // a-Z, 1-9
//    cout << "Size of char is: " << sizeof value3 << "\n"; // always 1 byte
//
//    // double  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
//    double value4 = 3.14; // Double precision floating-point number: 3.14 and 299793.0
//    cout << "Size of double is: " << sizeof value4 << "\n"; // always 8 byte
//
//    cout << value1;
//    cout << "\n";
//    cout << value2;
//    cout << "\n";
//    cout << value3;
//    cout << "\n";
//    cout << value4;
//    cout << "\n";
//
//    // Reading class
//    Square area = Square(3.14);
//    cout << "The area of the square is: " << area.getArea() << "\n";
//    Triangle triangle = { 3.14, 3.14 };
//    cout << "The Triangle has a base of: " << triangle.base << " and a height of: " << triangle.height << "\n";
//
//    return 0;
//}

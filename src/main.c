#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "./../include/clay/clay.h"
#define CLAY_IMPLEMENTATION
#include "./../include/raylib/raylib.h"
#include "./../include/raylib/clay_renderer_raylib.c"

void error_handler(Clay_ErrorData error) {
    perror("recieved clay error!\n");
}

const float W_WIDTH = 1280.00f;
const float W_HEIGHT = 720.00f;

int main(int argc, char *argv[]) {
    Clay_Raylib_Initialize((int)W_WIDTH, (int)W_HEIGHT, "ARAB GUI", !FLAG_WINDOW_RESIZABLE);

    uint64_t clayMemSize = Clay_MinMemorySize();
    Clay_Arena memArena = { // memory arena assigned to program
        .memory = malloc(clayMemSize),
        .capacity = clayMemSize
    };
    Clay_Dimensions dims = {
        .width = W_WIDTH,
        .height = W_HEIGHT
    };
    Clay_Initialize(memArena, dims, (Clay_ErrorHandler){error_handler});

    SetTargetFPS(60);

    // main loop
    while (WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(YELLOW);
        EndDrawing();
    }

	return 0;
}

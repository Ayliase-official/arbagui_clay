#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

#include "./../include/clay/clay.h"
#define CLAY_IMPLEMENTATION
#include "./../include/raylib/raylib.h"
#include "./../include/raylib/clay_renderer_raylib.c"

#define AUDIO_DEVICE_FORMAT 

void error_handler(Clay_ErrorData error) {
    perror("recieved clay error!\n");
}

const float W_WIDTH = 1280.00f;
const float W_HEIGHT = 720.00f;
=======

int main(int argc, char *argv[]) {
<<<<<<< HEAD
    const int W_FULL_WIDTH = GetScreenWidth();
    const int W_FULL_HEIGHT = GetScreenHeight();

    Clay_Raylib_Initialize(W_WIDTH, W_HEIGHT, "ARAB GUI", FLAG_FULLSCREEN_MODE | FLAG_MSAA_4X_HINT);

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

    const Clay_Color BG = (Clay_Color){190.00, 190.00, 190.00, 255.00};


    Image logo_image = LoadImage("./../assets/images/logo.png");
    ImageResizeNN(&logo_image, 836, 350);
    Texture logo_texture = LoadTextureFromImage(logo_image);

    Sound welcome = LoadSound("./../assets/audios/voice-ques/English/welcome.mp3");
    InitAudioDevice();
    
    // main loop
    while (!WindowShouldClose()) {
        PlaySound(welcome);
        Clay_BeginLayout();

        CLAY(
                CLAY_ID("Main"),
                CLAY_LAYOUT({ 
                    .layoutDirection = CLAY_TOP_TO_BOTTOM,
                    .sizing = { CLAY_SIZING_GROW(), CLAY_SIZING_GROW() },
                    .childGap = 10,
                    .padding = {10, 10},
                    .childAlignment = { CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_TOP }
                    }),
                CLAY_RECTANGLE({
                    .color = BG,
                    })
        ) {
            // add image
            CLAY(
                    CLAY_ID("Logo"),
                    CLAY_LAYOUT({
                        .sizing = { CLAY_SIZING_FIXED(836), CLAY_SIZING_FIXED(350) },
                        .padding = { 5, 20 }
                        }),
                    CLAY_IMAGE({ .sourceDimensions = { 836, 350 }, .imageData = &logo_texture})
                    ) {};
        };

        Clay_RenderCommandArray renderCmd = Clay_EndLayout();

        BeginDrawing();
        ClearBackground(YELLOW);
        Clay_Raylib_Render(renderCmd);
        EndDrawing();
    }

    UnloadSound(welcome);
    CloseAudioDevice();

=======
// #include <unistd.h>

#include "./../include/clay/lay.h"
#include "./../include/raylib/caly_renderer_raylib.h"

int main(int argc, char *argv[]) {
	// fork();
	printf("hello world!\n");
>>>>>>> parent of b5d12ec (meson failed; have to use the provided cmake template from clay)
	return 0;
}
=======

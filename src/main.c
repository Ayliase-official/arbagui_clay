#define CLAY_IMPLEMENTATION
#include "./../include/clay/clay.h"
#include "./../include/raylib/clay_renderer_raylib.c"
#include <stdio.h>

void error_handler(Clay_ErrorData error) {
    perror("recieved clay error!\n");
}

void hover_handle(Clay_ElementId _, Clay_PointerData pointerData, intptr_t userData) {
    printf("button hovered!");
}

const Clay_Color BG = (Clay_Color){ 190.00, 190.00, 190.00, 255.00 };
const Clay_Color BUTTON_IDLE_COLOR = (Clay_Color){ 0, 128, 128, 255 };
const Clay_Color BUTTON_HOVER_COLOR = (Clay_Color){ 130, 130, 130, 255 };

const float W_WIDTH = 1280.00f;
const float W_HEIGHT = 720.00f;

const int FONT_ID_SUBTITLE = 0;
const int FONT_SIZE_SUBTITLE = 26;
const Clay_Color FONT_COLOR_SUBTITLE = (Clay_Color) { 230, 41, 55, 255 };

const int FONT_ID_BUTTON = 1;
const int FONT_SIZE_BUTTON = 18;
const Clay_Color FONT_COLOR_BUTTON = (Clay_Color) { 255, 255, 255, 255 };


int main(int argc, char *argv[]) {
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

    // mouse
    Vector2 mousePosition = GetMousePosition();
    Clay_SetPointerState((Clay_Vector2){ mousePosition.x, mousePosition.y }, IsMouseButtonDown(0));

    // make sure to defer all these
    // Aaroth logo
    Image aaroth_logo_image = LoadImage("./../assets/images/p1/aaroth-logo.png");
    Texture aaroth_logo_texture = LoadTextureFromImage(aaroth_logo_image);
    UnloadImage(aaroth_logo_image);
    // MIT logo
    Image mit_logo_image = LoadImage("./../assets/images/p1/mit-logo.png");
    Texture mit_logo_texture = LoadTextureFromImage(mit_logo_image);
    UnloadImage(mit_logo_image);
    // CREiYA logo
    Image creiya_logo_image = LoadImage("./../assets/images/p1/creiya-logo.png");
    Texture creiya_logo_texture = LoadTextureFromImage(creiya_logo_image);
    UnloadImage(creiya_logo_image);
    // device logo
    Image device_logo_image = LoadImage("./../assets/images/p1/device-logo.png");
    Texture device_logo_texture = LoadTextureFromImage(device_logo_image);
    UnloadImage(device_logo_image);

   Clay_SetMeasureTextFunction(Raylib_MeasureText);
   Raylib_fonts[FONT_ID_SUBTITLE] = (Raylib_Font) {
       .font = LoadFontEx("./../assets/fonts/NimbusSans-Regular.otf", FONT_SIZE_SUBTITLE, 0, 0),
       .fontId = FONT_ID_SUBTITLE
   };
   Raylib_fonts[FONT_ID_BUTTON] = (Raylib_Font) {
       .font = LoadFontEx("./../assets/fonts/NimbusSans-Regular.otf", FONT_SIZE_BUTTON, 0, 0),
       .fontId = FONT_ID_BUTTON
   };

    // main loop
    while (!WindowShouldClose()) {
        Clay_BeginLayout();
        CLAY(CLAY_ID("main"),
            CLAY_LAYOUT({ 
                .layoutDirection = CLAY_TOP_TO_BOTTOM,
                .sizing = { CLAY_SIZING_GROW(), CLAY_SIZING_GROW() },
                }),
            CLAY_RECTANGLE({ .color = BG })
            ) {

            CLAY(CLAY_ID("banner"),
                CLAY_LAYOUT({
                    .layoutDirection = CLAY_LEFT_TO_RIGHT,
                    .sizing = { CLAY_SIZING_GROW(), CLAY_SIZING_FIXED(150) },
                    .padding = {10, 10},
                    .childAlignment = { .y = CLAY_ALIGN_Y_CENTER }
                    })
            ) {
                CLAY(CLAY_ID("mit-logo"),
                    CLAY_LAYOUT({ .sizing = { CLAY_SIZING_FIXED(190), CLAY_SIZING_FIXED(74) } }),
                    // CLAY_RECTANGLE({ .color = { 0, 0, 0, 255 }}),
                    CLAY_IMAGE({.sourceDimensions = { 190, 74 }, .imageData = &mit_logo_texture})
                ) {};
                CLAY(CLAY_ID("Spacer"),
                    CLAY_LAYOUT({
                    .sizing = { CLAY_SIZING_GROW(), CLAY_SIZING_GROW() }
                    })
                ) {};
                CLAY(CLAY_ID("creiya_logo"),
                    CLAY_LAYOUT({ .sizing = { CLAY_SIZING_FIXED(244), CLAY_SIZING_FIXED(135) } }),
                    CLAY_IMAGE({.sourceDimensions = { 244, 135 }, .imageData = &creiya_logo_texture})
                ) {};
            };
            
            CLAY(CLAY_ID("title"),
                CLAY_LAYOUT({
                    .layoutDirection = CLAY_TOP_TO_BOTTOM,
                    .sizing = { CLAY_SIZING_GROW(), CLAY_SIZING_GROW() },
                    .childAlignment = { CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_TOP },
                    .childGap = 30
                    })
            ) { 
                CLAY(CLAY_ID("arba-logo"),
                    CLAY_LAYOUT({ .sizing = { CLAY_SIZING_FIXED(418), CLAY_SIZING_FIXED(175) } }),
                    CLAY_IMAGE({.sourceDimensions = { 418, 175 }, .imageData = &aaroth_logo_texture })
                ) { };
                CLAY(CLAY_ID("device-logo"),
                    CLAY_LAYOUT({ .sizing = { CLAY_SIZING_FIXED(258), CLAY_SIZING_FIXED(54) } }),
                    CLAY_IMAGE({.sourceDimensions = { 258, 54}, .imageData = &device_logo_texture})
                ) { };
                CLAY(CLAY_ID("next-button"),
                    CLAY_LAYOUT({
                        // .sizing = { CLAY_SIZING_FIXED(500), CLAY_SIZING_FIXED(50) },
                        .padding = { 30, 10 },
                        .childAlignment = { CLAY_ALIGN_X_CENTER, CLAY_ALIGN_Y_CENTER }
                    }),
                    CLAY_RECTANGLE({
                        .color = Clay_Hovered() ? BUTTON_HOVER_COLOR : BUTTON_IDLE_COLOR,
                        .cornerRadius = 10
                    }),
                    Clay_OnHover(hover_handle, 0)
                ) {
                    CLAY(CLAY_ID("next-button-label"),
                        CLAY_TEXT(
                            CLAY_STRING("Enter LOGIN pin"),
                            CLAY_TEXT_CONFIG({
                                .textColor = FONT_COLOR_BUTTON,
                                .fontId = FONT_ID_BUTTON,
                                .fontSize = FONT_SIZE_BUTTON,
                            })
                        )) {};
                };
                CLAY(CLAY_ID("subtitle"),
                    CLAY_TEXT(
                        CLAY_STRING("Advanced Body Composition Analyzer"),
                        CLAY_TEXT_CONFIG({
                            .textColor = FONT_COLOR_SUBTITLE,
                            .fontId = FONT_ID_SUBTITLE,
                            .fontSize = FONT_SIZE_SUBTITLE,
                        })
                    )
                ) {};
            }
        };
        Clay_RenderCommandArray renderCmd = Clay_EndLayout();

        BeginDrawing();
        ClearBackground(YELLOW);
        Clay_Raylib_Render(renderCmd);
        EndDrawing();
    }

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "raylib.h"

#define SCREEN_WIDTH 360
#define SCREEN_HEIGHT 640

void init_state(Texture2D *background);
float grow_shrink(float scaleFactor);
int get_rand_xpos();
int get_rand_index();

int main(int argc, char **argv) {
    float scrollingSpeed = 0.0f;
    float scrollingSpeed2 = 0.0f;
    float scale = 1.0f;
    bool falling = true;
    int xpos = get_rand_xpos();
    int index;
    Texture2D background;
    
    // INIT
    init_state(&background);
    Texture2D coin = LoadTexture("../resources/coin.png");
    Texture2D tits = LoadTexture("../resources/tits.png");
    Texture2D arr[] = {coin, tits};
    
    Music music = LoadMusicStream("../audio/music/MapleLeafKushALitJourneyThroughThe6ixMaster.mp3");
    music.looping = true;
    float pitch = 1.0f;
    
    PlayMusicStream(music);
    music.looping = true;

    // GAME LOOP
    while (!WindowShouldClose()) {
        // UPDATE
        UpdateMusicStream(music);

        scrollingSpeed -= 0.5f;
        scrollingSpeed2 -= 0.5f;

        if (scrollingSpeed <= -background.width) 
            scrollingSpeed = 0;
        
        if (scrollingSpeed2 <= -(SCREEN_HEIGHT + 40)) {
            scrollingSpeed2 = 40;
            falling = false;
        }

        if (!falling) {
            xpos = get_rand_xpos();
            index = get_rand_index();
            falling = true;
        }
                  
        // DRAW
        BeginDrawing();

            ClearBackground(DARKGRAY);

            // Draw background image twice
            DrawTextureEx(background, (Vector2){ -20, scrollingSpeed }, 0.0f, 1.0f, WHITE);
            DrawTextureEx(background, (Vector2){ -20, background.width + scrollingSpeed }, 0.0f, 1.0f, WHITE);
            
            DrawTextureEx(arr[index], (Vector2){ xpos, -scrollingSpeed2}, 0.0f, 4.0f, WHITE);

        EndDrawing();
    }

    // DE-INIT AND FREE
    UnloadTexture(background);  // Unload background texture
    UnloadTexture(coin);
    UnloadTexture(tits);
    CloseWindow();              // Close window and OpenGL context

    return 0;
}

void init_state(Texture2D *background) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "marijuana scroll");

    InitAudioDevice();

    *background = LoadTexture("../resources/background.png");

    SetTargetFPS(60);
}

int get_rand_xpos() {
    int rand_xpos;
    srand(time(NULL));
    rand_xpos = rand() % 297;
    return rand_xpos;
}

int get_rand_index() {
    int rand_index;
    srand(time(NULL));
    rand_index = rand() % 2;
    return rand_index;
}

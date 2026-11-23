#include <iostream>
#include <vector>
#include "raylib.h"
#include "MainHelperList.h"
#include "Topics.h"
#include "GameDrawing.h"

using namespace std;

const int MAP_WIDTH = 892;
const int MAP_HEIGHT = 751;
const int PLAYER_SIZE = 50;

// Topic hitboxes follow the same order as setTopics() in Topics.cpp.
const vector<Rectangle> topicHitboxes = {
    {203, 0, 90, 100},      // 0 Tetris
    {42, 35, 145, 165},    // 1 Atari 2600
    {185, 105, 99, 110},   // 2 Space Invaders
    {5, 290, 190, 115},    // 3 Magnavox Odyssey
    {205, 295, 85, 108},   // 4 Atari Pong
    {3, 235, 198, 60},     // 5 First Gaming Consoles
    {386, 402, 214, 175},  // 6 Spacewar!
    {423, 575, 145, 77},   // 7 Tennis for Two
    {423, 649, 145, 67},   // 8 OXO
    {643, 300, 246, 165},  // 9 Spasim
    {263, 108, 228, 244}, // 10 Arcade Games
    {487, 108, 220, 244}  // 11 Mainframe Games
};

void MovePlayer(float& x, float& y, float deltaTime) {
    const float speed = 300.0f;
    if (IsKeyDown(KEY_D)) x += speed * deltaTime;
    if (IsKeyDown(KEY_A)) x -= speed * deltaTime;
    if (IsKeyDown(KEY_W)) y -= speed * deltaTime;
    if (IsKeyDown(KEY_S)) y += speed * deltaTime;

    if (x < 0) x = 0;
    if (x > MAP_WIDTH - PLAYER_SIZE) x = MAP_WIDTH - PLAYER_SIZE;
    if (y < 0) y = 0;
    if (y > MAP_HEIGHT - PLAYER_SIZE) y = MAP_HEIGHT - PLAYER_SIZE;
}

int FindHoveredTopic(float x, float y) {
    Rectangle player = {x, y, (float)PLAYER_SIZE, (float)PLAYER_SIZE};
    for (int i = 0; i < (int)topicHitboxes.size(); i++) {
        if (CheckCollisionRecs(player, topicHitboxes.at(i))) return i;
    }
    return -1;
}

int main() {
    vector<topics> allTopics = setTopics();

    // Original terminal introduction, preserved.
    cout << "Welcome to \"Early Computer Games\" Digital Tour!" << endl << endl;
    wait(1.5);
    cout << "Please give the name we can refer you by..." << endl;
    string userName;
    cin >> userName;
    cout << endl << "Glad to have you here " << userName << "!" << endl << endl;
    wait(1.5);
    cout << "Before we start, let's give you a quick recap on Early Computer Games." << endl;

    InitWindow(MAP_WIDTH, 810, "Early Computer Games Digital Tour");
    SetExitKey(KEY_NULL); // Escape closes a popup, not the program.
    SetTargetFPS(60);

    Texture2D background = LoadTexture("setting.png");
    vector<Texture2D> topicImages;
    for (int i = 0; i < (int)allTopics.size(); i++) {
        topicImages.push_back(LoadTexture(allTopics.at(i).getImage().c_str()));
    }

    float playerX = 100;
    float playerY = 100;
    int selectedTopic = -1;
    bool popupOpen = false;
    bool showHitboxes = false;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_F1)) showHitboxes = !showHitboxes;
        if (popupOpen && (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_BACKSPACE))) {
            popupOpen = false;
        }

        if (!popupOpen) MovePlayer(playerX, playerY, GetFrameTime());
        int hoveredTopic = FindHoveredTopic(playerX, playerY);
        if (!popupOpen && hoveredTopic != -1 && IsKeyPressed(KEY_SPACE)) {
            selectedTopic = hoveredTopic;
            popupOpen = true;
        }

        // All raylib drawing happens inside Drawing/GameDrawing.cpp.
        DrawGame(playerX, playerY, PLAYER_SIZE, PLAYER_SIZE, background,
                 topicHitboxes, allTopics, topicImages,
                 hoveredTopic, selectedTopic, popupOpen, showHitboxes);
    }

    for (Texture2D image : topicImages) {
        if (image.id != 0) UnloadTexture(image);
    }
    if (background.id != 0) UnloadTexture(background);
    CloseWindow();
    return 0;
}

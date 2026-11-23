#include "GameDrawing.h"
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

// Draw text one word at a time, starting a new line when necessary.
static void DrawWrappedDescription(string text, int x, int y,
                                   int maxWidth, int size, Color color) {
    istringstream stream(text);
    string word;
    string line = "";

    while (stream >> word) {
        string newLine = line;
        if (line != "") newLine += " ";
        newLine += word;

        if (line != "" && MeasureText(newLine.c_str(), size) > maxWidth) {
            // .c_str() provides the C-style string required by raylib's DrawText.
            DrawText(line.c_str(), x, y, size, color);
            y += size + 7;
            line = word;
        } else {
            line = newLine;
        }
    }
    if (line != "") DrawText(line.c_str(), x, y, size, color);
}

static void DrawTopicPopup(const topics& topic, Texture2D image, int selectedTopic) {
    // Darken the map, then draw a white panel on top of it.
    DrawRectangle(0, 0, 892, 810, Fade(BLACK, 0.83f));
    DrawRectangleRounded({95, 40, 702, 715}, 0.025f, 8, RAYWHITE);
    DrawRectangleRoundedLinesEx({95, 40, 702, 715}, 0.025f, 8, 3, DARKGRAY);

    DrawRectangle(115, 62, 662, 57, Color{25, 37, 59, 255});
    DrawText(topic.getTitle().c_str(), 128, 77, 27, WHITE);
    if (topic.getYear() > 0) {
        DrawText(TextFormat("%d", topic.getYear()), 705, 82, 19, GOLD);
    }

    // Keep each topic image's original aspect ratio.
    Rectangle imageArea = {143, 139, 606, 299};
    DrawRectangleRec(imageArea, BLACK);
    if (image.id != 0 && image.width > 0 && image.height > 0) {
        float factor = min(imageArea.width / image.width,
                           imageArea.height / image.height);
        Rectangle dest = {
            imageArea.x + (imageArea.width - image.width * factor) / 2,
            imageArea.y + (imageArea.height - image.height * factor) / 2,
            image.width * factor,
            image.height * factor
        };
        DrawTexturePro(image, {0, 0, (float)image.width, (float)image.height},
                       dest, {0, 0}, 0.0f, WHITE);
    } else {
        DrawText("Image missing", 330, 270, 25, RED);
    }

    DrawText("ABOUT THIS TOPIC", 143, 455, 23, DARKBLUE);
    DrawWrappedDescription(topic.getInfo(), 143, 489, 606, 19, DARKGRAY);
    if (selectedTopic == 3) {
        DrawText("Photo shows Odyssey 2, a later Magnavox console.",
                 143, 701, 15, DARKGRAY);
    }
    DrawText("PRESS ESC OR BACKSPACE TO CLOSE", 264, 724, 17, MAROON);
}

void DrawGame(float playerX, float playerY, int playerWidth, int playerHeight,
              Texture2D background, const vector<Rectangle>& hitboxes,
              const vector<topics>& allTopics,
              const vector<Texture2D>& topicImages,
              int hoveredTopic, int selectedTopic,
              bool popupOpen, bool showHitboxes) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(background, 0, 0, WHITE);

    // F1 toggles hitbox outlines for debugging.
    if (showHitboxes) {
        for (int i = 0; i < (int)hitboxes.size(); i++) {
            DrawRectangleLinesEx(hitboxes.at(i), 2,
                                 i == hoveredTopic ? GOLD : RED);
        }
    }

    DrawRectangle((int)playerX, (int)playerY, playerWidth, playerHeight, BLUE);
    DrawRectangle(5, 5, 210, 35, BLACK);
    DrawText(TextFormat("X: %.0f  Y: %.0f", playerX, playerY),
             10, 12, 20, WHITE);

    DrawRectangle(0, 751, 892, 59, BLACK);
    DrawText("WASD - Move | SPACE - Select Topic | ESC - Close | F1 - Hitboxes",
             10, 769, 18, WHITE);

    if (!popupOpen && hoveredTopic >= 0 && hoveredTopic < (int)allTopics.size()) {
        DrawRectangle(280, 45, 600, 37, Fade(BLACK, 0.95f));
        string prompt = "SPACE: " + allTopics.at(hoveredTopic).getTitle();
        // .c_str() provides the C-style string required by raylib's DrawText.
        DrawText(prompt.c_str(), 292, 54, 19, GOLD);
    }

    if (popupOpen && selectedTopic >= 0 &&
        selectedTopic < (int)allTopics.size() &&
        selectedTopic < (int)topicImages.size()) {
        DrawTopicPopup(allTopics.at(selectedTopic),
                       topicImages.at(selectedTopic), selectedTopic);
    }
    EndDrawing();
}

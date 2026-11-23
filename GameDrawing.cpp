#include "GameDrawing.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// This function makes long descriptions fit inside the popup
void DrawWrappedDescription(string text, int x, int y, int maxWidth, int size, Color color) {

    string word = "";
    string line = "";

    // Go through the description one character at a time
    for (int i = 0; i <= text.length(); i++) {
        // Check if we reached a space or the end of the description
        if (i == text.length() || text.at(i) == ' ') {
            string newLine = line;
            if (line != "") {
                newLine += " ";
            }
            newLine += word;
            // Check if adding the word makes the line too long
            if (line != "" && MeasureText(newLine.c_str(), size) > maxWidth) {
                // .c_str() converts a C++ string for raylib's text functions
                DrawText(line.c_str(), x, y, size, color);
                // Move down to the next line
                y += size + 7;
                // Start a new line
                line = word;
            }
            else {
                line = newLine;
            }
            word = "";
        }
        else {
            // Add the current character to the word
            word += text.at(i);
        }
    }

    // Draw the final line
    if (line != "") {
        DrawText(line.c_str(), x, y, size, color);
    }
}
// This function draws the popup for the selected topic
void DrawTopicPopup(topics topic, Texture2D image, int selectedTopic) {

    // Darken the background
    DrawRectangle(0, 0, 892, 810, Fade(BLACK, 0.83f));
    // White popup background
    DrawRectangleRounded({95, 40, 702, 715}, 0.025f, 8, RAYWHITE);
    // Popup border
    DrawRectangleRoundedLinesEx({95, 40, 702, 715}, 0.025f, 8, 3, DARKGRAY);
    // Dark blue title bar
    DrawRectangle(115, 62, 662, 57, Color{25, 37, 59, 255});
    // Display topic title
    DrawText(topic.getTitle().c_str(), 128, 77, 27, WHITE);
    // Display topic year
    if (topic.getYear() > 0) {
        DrawText(TextFormat("%d", topic.getYear()), 705, 82, 19, GOLD);
    }
    // Black background for the topic image
    DrawRectangle(143, 139, 606, 299, BLACK);
    // Display topic image
    if (image.id != 0 && image.width > 0 && image.height > 0) {
        // Calculate how much to resize the image
        float scaleX = 606.0f / image.width;
        float scaleY = 299.0f / image.height;
        float scale = scaleX;
        if (scaleY < scaleX) {
            scale = scaleY;
        }
        // Calculate the new dimensions
        float width = image.width * scale;
        float height = image.height * scale;
        // Center the image inside the black rectangle
        float x = 143 + (606 - width) / 2;
        float y = 139 + (299 - height) / 2;
        // Draw the image
        DrawTextureEx(image, {x, y}, 0, scale, WHITE);
    }

    // Description heading
    DrawText("ABOUT THIS TOPIC", 143, 455, 23, DARKBLUE);

    // Draw the topic description using the wrapping function
    DrawWrappedDescription(topic.getInfo(), 143, 489, 606, 19, DARKGRAY);

    // Special note for Magnavox Odyssey
    if (selectedTopic == 3) {
        DrawText(
            "Photo shows Odyssey 2, a later Magnavox console.",
            143, 701, 15, DARKGRAY
        );
    }
    // Instructions for closing the popup
    DrawText("PRESS ESC OR BACKSPACE TO CLOSE", 264, 724, 17, MAROON);
}

// This function draws everything in the game window
void DrawGame( float playerX,float playerY,
    int playerWidth,
    int playerHeight,
    Texture2D background,
    vector<Rectangle> hitboxes,
    vector<topics> allTopics,
    vector<Texture2D> topicImages,
    int hoveredTopic,
    int selectedTopic,
    bool popupOpen,
    bool showHitboxes
) 
{

    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw the background image
    DrawTexture(background, 0, 0, WHITE);

    // Draw hitboxes when F1 is pressed
    if (showHitboxes) {

        for (int i = 0; i < hitboxes.size(); i++) {

            // Gold outline for the hitbox the player is touching
            if (i == hoveredTopic) {
                DrawRectangleLinesEx(hitboxes.at(i), 2, GOLD);
            }
            else {
                DrawRectangleLinesEx(hitboxes.at(i), 2, RED);
            }
        }
    }

    // Draw the blue player rectangle
    DrawRectangle((int)playerX, (int)playerY, playerWidth, playerHeight, BLUE);

    // Black background for XY coordinates
    DrawRectangle(5, 5, 210, 35, BLACK);

    // Display player coordinates
    DrawText(
        TextFormat("X: %.0f  Y: %.0f", playerX, playerY),
        10, 12, 20, WHITE
    );

    // Black background for controls
    DrawRectangle(0, 751, 892, 59, BLACK);

    // Display controls
    DrawText(
        "WASD - Move | SPACE - Select Topic | ESC - Close | F1 - Hitboxes",
        10, 769, 18, WHITE
    );

    // Display the selected topic's popup
    if (popupOpen && selectedTopic >= 0 &&
        selectedTopic < allTopics.size() &&
        selectedTopic < topicImages.size()) {

        DrawTopicPopup(
            allTopics.at(selectedTopic),
            topicImages.at(selectedTopic),
            selectedTopic
        );
    }

    EndDrawing();
}

#ifndef GAME_DRAWING_H
#define GAME_DRAWING_H

#include "raylib.h"
#include "Topics.h"
#include <vector>

// All drawing functions live here so main.cpp stays focused on game logic.
void DrawGame(float playerX, float playerY, int playerWidth, int playerHeight,
              Texture2D background, const std::vector<Rectangle>& hitboxes,
              const std::vector<topics>& allTopics,
              const std::vector<Texture2D>& topicImages,
              int hoveredTopic, int selectedTopic,
              bool popupOpen, bool showHitboxes);

#endif

#pragma once
class Sprite;
#include "Easing.hpp"
#include "Vector2.hpp"
#include <string>
class Frame {
public:
	Frame() {};
	Frame(const std::string& pImage, const std::string& pLyric, const int pTiming);
	bool hasImage() const;
	bool hasLyric() const;
	void fade(const int startTime, const int endTime, const float startFade, const float endFade) const;
	// https://stackoverflow.com/questions/5354459/c-how-to-get-the-image-size-of-a-png-file-in-directory
	void findPNGDimensions(int& width, int& height) const;
	void move(const int startTime, const int endTime, const Vector2& startPosition, const Vector2& endPosition) const;
	void scale(const int startTime) const;
	int timing;
	std::string image;
	std::string lyric;
private:
	static constexpr float scaleFactor = 0.3f;
	static constexpr float textScaleFactor = 0.2f;
	static constexpr float width = 0.3f * 1280.0f;
	static constexpr float height = 0.3f * 720.0f;
	int textMargin = 4.0f;
	int textPadding = 5.0f;
	int textWidth;
	int textHeight;
	Sprite* background;
	Sprite* top;
	Sprite* bot;
	Sprite* left;
	Sprite* right;
	// Due to pixel errors, can't get top/bot/left/right lines to work properly
	Sprite* textBorder;
	Sprite* textBackground;
	Sprite* text;
};
#include "Frame.hpp"
#include "Easing.hpp"
#include "Storyboard.hpp"
#include <winsock.h>
Frame::Frame(const std::string& pImage, const std::string& pLyric, const int pTiming)
	: image{ pImage }, lyric{ pLyric }, timing{ pTiming } {
	if (hasImage()) {
		background = Storyboard::CreateSprite(image);
		top = Storyboard::CreateSprite("@");
		bot = Storyboard::CreateSprite("@");
		left = Storyboard::CreateSprite("@");
		right = Storyboard::CreateSprite("@");
		if (hasLyric()) {
			textBorder = Storyboard::CreateSprite("@", Vector2::Zero, Layer::Foreground, Origin::TopLeft);
			textBackground = Storyboard::CreateSprite("!", Vector2::Zero, Layer::Foreground, Origin::TopLeft);
			text = Storyboard::CreateSprite(lyric, Vector2::Zero, Layer::Foreground, Origin::TopLeft);
			findPNGDimensions(textWidth, textHeight);
		}
	}
}
bool Frame::hasImage() const {
	if (image != "") {
		return true;
	}
	else {
		return false;
	}
}
bool Frame::hasLyric() const {
	if (lyric != "") {
		return true;
	}
	else {
		return false;
	}
}
void Frame::fade(const int startTime, const int endTime, const float startFade, const float endFade) const {
	if (hasImage()) {
		background->Fade(startTime, endTime, startFade, endFade);
		top->Fade(startTime, endTime, startFade, endFade);
		bot->Fade(startTime, endTime, startFade, endFade);
		left->Fade(startTime, endTime, startFade, endFade);
		right->Fade(startTime, endTime, startFade, endFade);
		if (hasLyric()) {
			textBorder->Fade(startTime, endTime, startFade, endFade);
			textBackground->Fade(startTime, endTime, startFade, endFade);
			text->Fade(startTime, endTime, startFade, endFade);
		}
	}
}
void Frame::findPNGDimensions(int& width, int& height) const {
	std::ifstream in(R"(X:\osu!\Songs\824592 Mrs GREEN APPLE - Ao to Natsu\)" + lyric + ".png");
	in.seekg(16);
	in.read((char *)&width, 4);
	in.read((char *)&height, 4);
	width = ntohl(width);
	height = ntohl(height);
}
void Frame::move(const int startTime, const int endTime, const Vector2& startPosition, const Vector2& endPosition) const {
	if (hasImage()) {
		background->Move(startTime, endTime, startPosition, endPosition);
		top->Move(startTime, endTime, startPosition + Vector2(0, height / 2.0f), endPosition + Vector2(0, height / 2.0f));
		bot->Move(startTime, endTime, startPosition - Vector2(0, height / 2.0f), endPosition - Vector2(0, height / 2.0f));
		left->Move(startTime, endTime, startPosition - Vector2(width / 2.0f, 0), endPosition - Vector2(width / 2.0f, 0));
		right->Move(startTime, endTime, startPosition + Vector2(width / 2.0f, 0) , endPosition + Vector2(width / 2.0f, 0));
		if (hasLyric()) {
			const auto backgroundOffset = Vector2(-width / 2.0f, height / 2.0f) + Vector2(textMargin, -textMargin);
			textBorder->Move(startTime, endTime, startPosition + backgroundOffset + Vector2(-1, 1), endPosition + backgroundOffset + Vector2(-1, 1));
			textBackground->Move(startTime, endTime, startPosition + backgroundOffset, endPosition + backgroundOffset);
			const auto textOffset = backgroundOffset + Vector2(textPadding, -textPadding);
			text->Move(startTime, endTime, startPosition + textOffset, endPosition + textOffset);
		}
	}
}
void Frame::scale(const int startTime) const {
	if (hasImage()) {
		background->Scale(startTime, startTime, scaleFactor, scaleFactor);
		top->ScaleVector(startTime, startTime, Vector2(width + 1, 1), Vector2(width + 1, 1));
		bot->ScaleVector(startTime, startTime, Vector2(width + 1, 1), Vector2(width + 1, 1));
		left->ScaleVector(startTime, startTime, Vector2(1, height + 1), Vector2(1, height + 1));
		right->ScaleVector(startTime, startTime, Vector2(1, height + 1), Vector2(1, height + 1));
		if (hasLyric()) {
			const auto scale = Vector2(textWidth * textScaleFactor + textPadding * 2, textHeight * textScaleFactor + textPadding * 2);
			textBorder->ScaleVector(startTime, startTime, scale + Vector2(2, 2), scale + Vector2(2, 2));
			textBackground->ScaleVector(startTime, startTime, scale, scale);
			text->Scale(startTime, startTime, textScaleFactor, textScaleFactor);
		}
	}
}

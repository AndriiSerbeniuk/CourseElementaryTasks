#include "envelope.h"
#include <stdexcept>

Envelope::Envelope() : width_(1), height_(1) {}

Envelope::Envelope(float width, float height) {
  if (width <= 0 || height <= 0)
    throw std::invalid_argument("Size of " + std::to_string(width) + "*" + 
      std::to_string(height) + " is invalid. Each side must be > 0.");
	// Flip the envelope onto a bigger side
	if (height > width)
	{
		width_ = height;
		height_ = width;
	}
	else
	{
		width_ = width;
		height_ = height;
	}
}

Envelope::~Envelope() {}

float Envelope::get_width() const {
	return width_;
}

float Envelope::get_height() const {
	return height_;
}

bool Envelope::operator == (const Envelope& other) const {
	return width_ == other.width_ && height_ == other.height_;
}

bool Envelope::operator != (const Envelope& other) const {
	return width_ != other.width_ || height_ != other.height_;
}

bool Envelope::operator > (const Envelope& other) const {
	return width_ > other.width_ && height_ > other.height_;
}

bool Envelope::operator >= (const Envelope& other) const {
	return *this > other || width_ == other.width_ || height_ == other.height_;
}

bool Envelope::operator < (const Envelope& other) const {
	return width_ < other.width_ && height_ < other.height_;
}

bool Envelope::operator <= (const Envelope& other) const {
	return *this < other || width_ == other.width_ || height_ == other.height_;
}

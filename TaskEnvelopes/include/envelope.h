#pragma once

// Envelope with width and height. Width >= height
class Envelope {
private:
	float width_;
  float height_;

public:
  Envelope();
  Envelope(float width, float height);
  virtual ~Envelope();

  float get_width() const;
  float get_height() const;
  // Checks exact equality of widths and heights
  bool operator == (const Envelope& other) const;
  // Checks inequality of widths or heights
  bool operator != (const Envelope& other) const;
  // Checks if left envelope's width and height are greater than the right's
  bool operator > (const Envelope& other) const;
  // Checks if left envelope's width and height are greater than the right's,
  // or any of the sides are equal
  bool operator >= (const Envelope& other) const;
  // Checks if left envelope's width and height are lesser than the right's
  bool operator < (const Envelope& other) const;
  // Checks if left envelope's width and height are lesser than the right's,
  // or any of the sides are equal
  bool operator <= (const Envelope& other) const;
};
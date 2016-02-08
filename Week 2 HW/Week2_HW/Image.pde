class Image {
  // variables
  PImage face;
  PVector pos, speed;
  float faceSize, grav, bounceFactor;
  color c;

  //constructor
  Image(float _imgSize) {

    face = loadImage("Doge face.png");

    bounceFactor = -.8;
    faceSize = _imgSize; 
    //grav = .05;

    float sXV = random(-10, 10);
    float sYV = random(-10, 10);

    pos = new PVector(width/2, height/2);
    speed = new PVector(sXV, sYV);

    c = color(200, 255, 0);
  }

  //show doge

  void refreshDoge() {
    pos.x = mouseX;
    pos.y = mouseY;
    speed.x = random(-10, 10);
    speed.y = random(-10, 10);

    c = color(random(0,255), 200, random(0,255));
  }

  //update

  void Update() {

    pos.x += speed.x;
    pos.y += speed.y;

    speed.y += grav;

    image(face, pos.x, pos.y, faceSize, faceSize);
    tint(c);

    if (pos.y <= 0) {
      pos.y = 1;
      speed.y *= bounceFactor;
    } else if (pos.y >= height - faceSize) {
      pos.y = height - faceSize -1;
      speed.y *= bounceFactor;
    }

    if (pos.x <= 0) {
      pos.x = 1;
      speed.x *= bounceFactor;
    } else if (pos.x >= width - faceSize) {
      pos.x = width - faceSize -1;
      speed.x *= bounceFactor;
    }
  }
}
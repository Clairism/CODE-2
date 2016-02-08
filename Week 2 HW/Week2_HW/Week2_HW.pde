Image[] faces; 

void setup() {

  size(800, 800);
  faces = new Image[10];

  for (int i = 0; i< faces.length; i ++) {
    faces[i]= new Image(100);
  }
}

void draw() {

  background(0);

  for (int i = 0; i< faces.length; i ++) {
    if (mousePressed) {
      faces[i].refreshDoge();
    }
    
    faces[i].Update();
  }
}
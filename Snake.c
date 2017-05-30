#
include < graphics.h > #include < stdlib.h > #include < stdio.h > #include < conio.h > #include < dos.h >

  int x, y, xmax, ymax, flag = 0, score = 0, round = 0;
int ranx, rany;
char ch;
void pt(void);

void main(void) {
  int gdriver = DETECT, gmode, errorcode;
  initgraph( & gdriver, & gmode, "");

  xmax = getmaxx();
  ymax = getmaxy();
  x = 300;
  y = 220;
  pt();
  start:
    while (!kbhit()) {
      int len = 10, tempx, tempy, i = 0, lastx[10] = {
        0
      }, lasty[10] = {
        0
      }, ptr = 0, out = 0;
      cleardevice();
      tempx = x;
      tempy = y;

      if (ch == 'w') {
        flag = 1;
      } else if (ch == 'a') {
        flag = 2;
      } else if (ch == 's') {
        flag = 3;
      } else if (ch == 'd') {
        flag = 0;
      }

      for (i = 0; i < len; i++) {
        circle(ranx, rany, 2);
        if (i > 0 && lastx[i] != 0) {

          {
            tempx = lastx[i - 1];
            tempx = lasty[i - 1];
            circle(tempx, tempy, 2);
            getch();
            lastx[ptr] = tempx;
            lasty[ptr++] = tempy;
          }
        } else {
          circle(tempx, tempy, 2);
          lastx[ptr] = tempx;
          lasty[ptr++] = tempy;
        }
        if (flag == 0)
          tempx -= 4;
        else if (flag == 1)
          tempy += 4;
        else if (flag == 2)
          tempx += 4;
        else if (flag == 3)
          tempy -= 4;

      }
      ptr = 0;
      delay(50);

      if (flag == 0)
        x += 4;
      else if (flag == 1)
        y -= 4;
      else if (flag == 2)
        x -= 4;
      else if (flag == 3)
        y += 4;

      if ((ranx == tempx && rany == tempy)) {
        pt();
        score++;
        len++;
      }
      if (x >= xmax || x <= 2 || y >= ymax || y <= 2) {
        printf("\nGAME OVER");
        printf("\n\nScore:%d", score);
        getch();
        exit(0);

      }
    }
  ch = getch();
  goto start;
}

void pt(void) {
  randomize();
  ranx = random(xmax - 100) + 50;
  rany = random(ymax - 100) + 50;
}

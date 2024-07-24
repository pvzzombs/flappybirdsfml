#pragma once

bool collided(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh) {
  int c = ax + aw < bx ||
          bx + bw < ax ||
          ay + ah < by ||
          by + bh < ay;
  return !c;
}

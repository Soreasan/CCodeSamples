/*
Kenneth Adair
Examples of structures from the K&R book.  
*/

#include <stdio.h>

int main(){
  return 0;
}

//pg. 128 K&R
struct point{
  int x;
  int y;
};

//pg. 129 K&R
struct rect{
  struct point pt1;
  struct point pt2;
};

//pg. 130 K&R
struct point makepoint(int x, int y){
  struct point temp;
  temp.x = x;
  temp.y = y;
  return temp;
};

//pg. 130 K&R
struct point addpoint(struct point p1, struct point p2){
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

//pg. 130 K&R
/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
  return p.x >= r.pt1.x && p.x < r.pt2.x &&p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b)((a) < (b) ? (a) : (b));
#define max(a, b)((a) > (b) ? (b) : (a));

/* canonrect: canonicalize coordinates of rectangle  */
struct rect canonrect(struct rect r)
{
  struct rect temp;
  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);
  return temp;
}

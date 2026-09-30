class Rectangle {
    Point p1;
    Point p2;
    
    Rectangle(int x1,int y1,int x2,int y2) {
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }
    
    Rectangle(Point p1, Point p2) {
        this.p1 = p1;
        this.p2 = p2;
    }

    public int area() {
        int h = this.p2.y - this.p1.y;
        int l = this.p2.x - this.p1.x;

        return h * l;
    }

    public int perimeter() {
        int h = this.p2.y - this.p1.y;
        int l = this.p2.x - this.p1.x;

        return 2 * h + 2 * l;
    }

    public boolean pointInside(Point p) {
        if (p.x < this.p1.x || this.p2.x < p.x) {
            return false;
        }

        if (p.y < this.p1.y || this.p2.y < p.y) {
            return false;
        }
        
        return true;
    }

     public boolean rectangleInside(Rectangle r) {
         return this.pointInside(r.p1) && this.pointInside(r.p2);
     }
}


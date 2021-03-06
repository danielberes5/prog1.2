#include "Graph.h"
#include <string>
#include <cmath>

using namespace Graph_lib;

constexpr double PI = 3.14159265;

// Ex 13 1 - Arc

struct Arc : Shape {
    Arc(Point p, int rr, double start, double end);

    void draw_lines() const;

    int radius() const { return r; }

private:
    int r;
    double start;
    double end;
};

// Ex 13 2 - Box

struct Box : Shape {
    Box(Point p, int w, int h, int r);

    void draw_lines() const;

private:
    Vector_ref<Arc> corners;
    Lines sides;
};

// Ex 13 3 - Arrow

struct Arrow : Shape {
    Arrow(Point p1, Point p2);

    void draw_lines() const;
    
    void set_size(int s) { size = s; }

private:
    int size = 12;
    int iso = 20;
};

// Ex 13 6 - Text_box

Point n (Rectangle& r);
Point s (Rectangle& r);
Point e (Rectangle& r);
Point w (Rectangle& r);
Point nw (Rectangle& r);
Point ne (Rectangle& r);
Point sw (Rectangle& r);
Point se (Rectangle& r);
Point center (Rectangle& r);

struct Text_box : Rectangle {
    Text_box(Point pp, int ww, int hh, string ss);

    void draw_lines() const;

private:
    Text label;
};

// Ex 14 1 - Smiley, Frowny

struct Smiley : Circle {
    Smiley(Point p, int r);

    void draw_lines () const;

private:
    int r;          // radius
    Circle left;    // left eye
    Circle right;   // right eye
    Arc mouth;      // mouth
};

struct Frowny : Circle {
    Frowny(Point p, int r);

    void draw_lines () const;

private:
    int r;          // radius
    Circle left;    // left eye
    Circle right;   // right eye
    Arc mouth;      // mouth
};

struct Smiley_hat : Smiley {
    Smiley_hat(Point p, int r);
    void draw_lines () const;

private:
    Rectangle hat;
};

struct Frowny_hat : Frowny {
    Frowny_hat(Point p, int r);

    void draw_lines () const;

private:
    Polygon hat;
};

// Ex 14 11 - Binary_tree

struct Binary_tree : Shape {
    Binary_tree(Point p, int levels, string edge_style = "normal");
    int number_of_nodes() const { return nodes.size(); }

    virtual void draw_lines () const;
    int levels() const { return l; }
    void set_node_label(string n, string l);
protected:
    vector<Point> nodes;
    Vector_ref<Shape> edges;
    Vector_ref<Text> labels;
    int r = 15;
    int l;
};

struct Binary_tree_squares : Binary_tree {
    Binary_tree_squares(Point p, int levels, string edge_style)
        : Binary_tree(p,levels,edge_style) { }
    void draw_lines() const;
private:
};


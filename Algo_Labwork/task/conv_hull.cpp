#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Global reference point (p0)
Point p0;


int distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) +
           (a.y - b.y) * (a.y - b.y);
}


int cross(Point a, Point b, Point c) {
    // Vector AB × AC
    return (b.x - a.x) * (c.y - a.y) -
           (b.y - a.y) * (c.x - a.x);
}


bool compare(Point a, Point b) {
    int cp = cross(p0, a, b);

    // Collinear → keep farthest first
    if (cp == 0){
        return distSq(p0, a) > distSq(p0, b);
    }
    return cp > 0;  // Counterclockwise
}

// Graham Scan Algorithm 
vector<Point> grahamScan(vector<Point> &points) {

    int n = points.size();
    if (n < 3) return points;

    // Step 1: Find lowest Y (and leftmost if tie)
    int ymin = 0;
    for (int i = 1; i < n; i++) {
        if( points[i].y < points[ymin].y ||
            (points[i].y == points[ymin].y &&
            points[i].x < points[ymin].x)) {
                ymin = i;
        }
    }

    swap(points[0], points[ymin]);
    p0 = points[0];

    // Step 2: Sort by polar angle
    sort(points.begin() + 1, points.end(), compare);

    // Step 3: Remove collinear duplicates
    vector<Point> filtered;
    filtered.push_back(points[0]);

    for (int i = 1; i < n; i++) {
        while (i < n - 1 &&
               cross(p0, points[i], points[i + 1]) == 0)
            i++;
        filtered.push_back(points[i]);
    }

    if (filtered.size() < 3) return filtered;

    // Step 4: Stack simulation
    vector<Point> hull;
    hull.push_back(filtered[0]);
    hull.push_back(filtered[1]);
    hull.push_back(filtered[2]);

    for (int i = 3; i < filtered.size(); i++) {
        while (hull.size() >= 2 &&
               cross(hull[hull.size() - 2],
                     hull.back(),
                     filtered[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(filtered[i]);
    }

    return hull;
}

int main() {

    vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1},
        {2, 1}, {3, 0}, {0, 0},
        {3, 3}
    };

    vector<Point> hull = grahamScan(points);

    cout << "Convex Hull:\n";
    for (auto p : hull){
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
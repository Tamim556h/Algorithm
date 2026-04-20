#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point& p) const { 
        return x < p.x || (x == p.x && y < p.y); 
    }
};

long long cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point> pts) {
    int n = pts.size(), k = 0;
    if (n <= 2) return pts;

    vector<Point> hull(2 * n);
    sort(pts.begin(), pts.end());

    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(hull[k - 2], hull[k - 1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }
    
    // Build upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(hull[k - 2], hull[k - 1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }

    hull.resize(k - 1); 
    return hull;
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    if (n <= 0) {
        cout << "No points entered.\n";
        return 0;
    }

    vector<Point> points(n);
    cout << "Enter the x and y coordinates (e.g., '2 4'):\n";
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> result = convexHull(points);
    
    cout << "\n--- Convex Hull Results ---\n";
    cout << "Number of points on hull: " << result.size() << "\n";
    for (const auto& p : result) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    
    return 0;
}
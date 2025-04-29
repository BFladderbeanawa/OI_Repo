#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

struct Line {
    Point p1, p2;
};

struct Cow {
    int s;
    double x, y;
};

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool intersect(Line l1, Line l2) {
    double cp1 = cross_product(l1.p1, l1.p2, l2.p1);
    double cp2 = cross_product(l1.p1, l1.p2, l2.p2);
    double cp3 = cross_product(l2.p1, l2.p2, l1.p1);
    double cp4 = cross_product(l2.p1, l2.p2, l1.p2);

    if ((cp1 * cp2 < 0) && (cp3 * cp4 < 0)) {
        return true;
    }

    if (cp1 == 0 && min(l1.p1.x, l1.p2.x) <= l2.p1.x && l2.p1.x <= max(l1.p1.x, l1.p2.x) && min(l1.p1.y, l1.p2.y) <= l2.p1.y && l2.p1.y <= max(l1.p1.y, l1.p2.y)) return true;
    if (cp2 == 0 && min(l1.p1.x, l1.p2.x) <= l2.p2.x && l2.p2.x <= max(l1.p1.x, l1.p2.x) && min(l1.p1.y, l1.p2.y) <= l2.p2.y && l2.p2.y <= max(l1.p1.y, l1.p2.y)) return true;
    return false;

}

int main() {
    int n, t;
    cin >> n >> t;

    double X, Y;
    cin >> X >> Y;

    vector<Cow> cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].s >> cows[i].x >> cows[i].y;
    }

    for (int time = 0; time < t; ++time) {
        vector<Line> sights;
        for (int i = 0; i < n; ++i) {
            if (cows[i].s <= time) {
                sights.push_back({{cows[i].x, 0}, {0, cows[i].y}});
            }
        }

        Line path = {{X, 0}, {0, Y}};
        bool blocked = false;
        for (const auto& sight : sights) {
            if (intersect(path, sight)) {
                blocked = true;
                break;
            }
        }

        if (!blocked) {
            cout << fixed << setprecision(0) << floor(dist({X, 0}, {0, Y})) << endl;
        } else {
             vector<Point> points = {{X,0},{0,Y}};
             for(const auto& sight : sights){
                 points.push_back(sight.p1);
                 points.push_back(sight.p2);
             }
             double min_d = numeric_limits<double>::infinity();
             for(int i=0;i<points.size();++i){
                 for(int j=0;j<points.size();++j){
                     if(i==j) continue;
                     Line path2 = {points[i],points[j]};
                     bool blocked2 = false;
                     for(const auto& sight: sights){
                         if(intersect(path2,sight)){
                             blocked2 = true;
                             break;
                         }
                     }
                     if(!blocked2 && points[i].x == X && points[i].y == 0 && points[j].x == 0 && points[j].y == Y){
                        min_d = min(min_d,dist(points[i],points[j]));
                     } else if (!blocked2 && points[i].x == X && points[i].y == 0){
                         for(int k=0;k<points.size();++k){
                            if(k==i) continue;
                            Line path3 = {points[j],points[k]};
                            bool blocked3 = false;
                            for(const auto& sight: sights){
                                if(intersect(path3,sight)){
                                    blocked3 = true;
                                    break;
                                }
                            }
                            if(!blocked3 && points[k].x == 0 && points[k].y == Y){
                                min_d = min(min_d,dist(points[i],points[j])+dist(points[j],points[k]));
                            }
                         }
                     }

                 }
             }

            cout << fixed << setprecision(0) << floor(min_d) << endl;
        }
    }

    return 0;
}
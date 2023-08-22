/*
    --------- Convex Hull ----------
    
    Imagine that the points are nails sticking out of the plane,we take an elastic rubber band and stretch it around the nails and let it go. It will snap around the nails and assume a shape that minimizes its length. The area enclosed by the rubber band is called the convex hull of P. This leads to an alternative definition of the convex hull of a finite set P of points in the plane: it is the unique convex polygon whose vertices are points from P and which contains all points of P.

    The best way to solve convex hull related problem is the Graham algorithm which uses a stack but here we are using a vector (which actually is working as a stack tho so nvm). 

    We take points A,B,C for e.g. now if ∠ABC is greater than 90° anticlockwise than we select the points but if it becomes less than 90° we ommit B and select only A and C. Thus selecting all the  points this way at the end we get the convex hull formation.

*/


#include <bits/stdc++.h>
using namespace std;

bool static cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

bool check(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c)
{
    return (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first) < 0;
}

vector<pair<int, int>> convexhull(vector<pair<int, int>>& points)
{
    sort(points.begin(), points.end(), cmp);

    vector<pair<int, int>> res;
    int n = points.size();

    for (int i = 0; i < n; i++)
    {
        while (res.size() > 2 && check(res[res.size() - 2], res[res.size() - 1], points[i]))
        {
            res.pop_back();
        }
        res.push_back(points[i]);
    }

    if (res.size() == n)
    {
        return res;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        while (res.size() > 2 && check(res[res.size() - 2], res[res.size() - 1], points[i]))
        {
            res.pop_back();
        }
        res.push_back(points[i]);
    }
    res.pop_back();

    return res;
}

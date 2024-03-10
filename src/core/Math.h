#pragma once

#include "../math/Vector2.h"
#include <math.h>

static const float pi = 3.14159;

static class Math {
public:
    static const float AngleAroundCenter(Vector2 p1, Vector2 p2, Vector2 center)
    {
        float angle1 = atan2f(p1.x - center.x, p1.y - center.y);
        float angle2 = atan2f(p2.x - center.x, p2.y - center.y);

        return (angle1 - angle2) * 180 / pi;
    }

    static const float AngleAwayFromPoint(Vector2 p1, Vector2 p2)
    {
        float angle = atan2f(p2.y - p1.y, p2.x - p1.x);

        return angle * 180 / pi;
    }
};
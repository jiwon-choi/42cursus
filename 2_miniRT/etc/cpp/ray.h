#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
    	//ray class의 생성자
        ray() {}
        ray(const point3& origin, const vec3& direction)
            : orig(origin), dir(direction)
        {}
        // 광선의 광원(위에서의 A)과 방향(b)를 반환한다.
        point3 origin() const  { return orig; }
        vec3 direction() const { return dir; }
		// 광선의 끝 지점을 반환한다. 혹은 광선의 벡터
        point3 at(double t) const {
            return orig + t*dir;
        }

    public:
        // 광원의 좌표(A)
        point3 orig;
        // 광선의 방향(b) 벡터
        vec3 dir;
};

#endif

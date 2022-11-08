#include "Maths.h"
namespace k
{
	Vector2 Vector2::Zero(0.0f, 0.0f);
	Vector2 Vector2::One(1.0f, 1.0f);
	Vector2 Vector2::Right(1.0f, 0.0f);
	Vector2 Vector2::Left(-1.0f, 0.0f);
	Vector2 Vector2::Up(0.0f, -1.0f);
	Vector2 Vector2::Down(0.0f, 1.0f);
}

//디그리 각도
// 0~360
//라디안 각도
// 
//반지름이 1일때 원의 둘레는 6.28 
//반지름이 2일때 원의 둘레는 12.56